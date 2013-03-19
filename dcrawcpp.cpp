#include "DcRawQT_global.h"
#include <QDataStream>
#include "dcrawqt.h"
#include "dcraw.h"

jmp_buf failure;

void CLASS ppm_thumb(DCRAWQT *p, void *byteArray)
{
  char *thumb;

  QDataStream *byteStream = new QDataStream((QByteArray *)byteArray,QIODevice::WriteOnly);

  byteStream->setByteOrder(QDataStream::LittleEndian);


  p->thumb_length = p->thumb_width*p->thumb_height*3;
  thumb = (char *) malloc (p->thumb_length);
  merror (p,thumb, "ppm_thumb()");
  if(p->ofp)
      fprintf (p->ofp, "P6\n%d %d\n255\n", p->thumb_width, p->thumb_height);

  char *hdr = (char *)malloc(sizeof(char)*18);
  memset(hdr, 0, 18);
  snprintf(hdr,17,"P6\n%d %d\n255\n",p->thumb_width, p->thumb_height);
  byteStream->writeRawData(hdr, 18);

  fread  (thumb, 1, p->thumb_length, p->ifp);
  if(p->ofp)
      fwrite (thumb, 1, p->thumb_length, p->ofp);
  byteStream->writeRawData(thumb, p->thumb_length);
  free (thumb);
}

void CLASS layer_thumb(DCRAWQT *p, void *byteArray)
{
  int i, c;
  char *thumb, map[][4] = { "012","102" };

  p->colors = p->thumb_misc >> 5 & 7;
  p->thumb_length = p->thumb_width*p->thumb_height;
  thumb = (char *) calloc (p->colors, p->thumb_length);
  merror (p,thumb, "layer_thumb()");
  if(p->ofp)
      fprintf (p->ofp, "P%d\n%d %d\n255\n",
        5 + (p->colors >> 1), p->thumb_width, p->thumb_height);
  fread (thumb, p->thumb_length, p->colors, p->ifp);
  for (i=0; i < p->thumb_length; i++)
      if(p->ofp)
        FORCC putc (thumb[i+p->thumb_length*(map[p->thumb_misc >> 8][c]-'0')], p->ofp);
  free (thumb);
}

void CLASS rollei_thumb(DCRAWQT *p, void *byteArray)
{
  unsigned i;
  ushort *thumb;

  p->thumb_length = p->thumb_width * p->thumb_height;
  thumb = (ushort *) calloc (p->thumb_length, 2);
  merror (p,thumb, "rollei_thumb()");
  if(p->ofp)
      fprintf (p->ofp, "P6\n%d %d\n255\n", p->thumb_width, p->thumb_height);
  read_shorts (p,thumb, p->thumb_length);
  for (i=0; i < p->thumb_length; i++) {
    if(p->ofp)
    {
       putc (thumb[i] << 3, p->ofp);
        putc (thumb[i] >> 5  << 2, p->ofp);
        putc (thumb[i] >> 11 << 3, p->ofp);
    }
  }
  free (thumb);
}


void CLASS jpeg_thumb(DCRAWQT *p, void *byteArray)
{
  char *thumb;
  ushort exif[5];
  struct tiff_hdr th;
  QDataStream *byteStream = new QDataStream((QByteArray *)byteArray,QIODevice::WriteOnly);

  byteStream->setByteOrder(QDataStream::LittleEndian);


  thumb = (char *) malloc (p->thumb_length);
  merror (p,thumb, "jpeg_thumb()");
  fread (thumb, 1, p->thumb_length, p->ifp);

  if(p->ofp)
  {
    fputc (0xff, p->ofp);
    fputc (0xd8, p->ofp);
  }
  char data = 0xff;
  byteStream->writeRawData((const char *)&data, 1);
  data = 0xd8;
  byteStream->writeRawData((const char *)&data,1);

  if (strcmp (thumb+6, "Exif")) {
    memcpy (exif, "\xff\xe1  Exif\0\0", 10);
    exif[1] = htons (8 + sizeof th);
    if(p->ofp)
         fwrite (exif, 1, sizeof exif, p->ofp);
    byteStream->writeRawData((const char *)exif, sizeof(exif));
    tiff_head (p,&th, 0);
    if(p->ofp)
     fwrite (&th, 1, sizeof th, p->ofp);
    byteStream->writeRawData((const char *)&th,sizeof(th));
  }
  if(p->ofp)
      fwrite (thumb+2, 1, p->thumb_length-2, p->ofp);
  byteStream->writeRawData(thumb+2, p->thumb_length - 2);
  free (thumb);
}

void CLASS write_ppm_tiff(DCRAWQT *p, void *byteArray)
{
  struct tiff_hdr th;
  uchar *ppm;
  ushort *ppm2;
  int c, row, col, soff, rstep, cstep;
  int perc, val, total, white=0x2000;
  QDataStream *byteStream = new QDataStream((QByteArray *)byteArray,QIODevice::WriteOnly);

  byteStream->setByteOrder(QDataStream::LittleEndian);

  perc = p->width * p->height * 0.01;		/* 99th percentile white level */
  if (p->fuji_width) perc /= 2;
  if (!((p->highlight & ~2) || p->no_auto_bright))
    for (white=c=0; c < p->colors; c++) {
      for (val=0x2000, total=0; --val > 32; )
        if ((total += p->histogram[c][val]) > perc) break;
      if (white < val) white = val;
    }
  gamma_curve (p,p->gamm[0], p->gamm[1], 2, (white << 3)/p->bright);
  p->iheight = p->height;
  p->iwidth  = p->width;
  if (p->flip & 4) SWAP(p->height,p->width);
  ppm = (uchar *) calloc (p->width, p->colors*p->output_bps/8);
  ppm2 = (ushort *) ppm;
  merror (p,ppm, "write_ppm_tiff()");
  if (p->output_tiff) {
    tiff_head (p,&th, 1);
    if(p->ofp)
        fwrite (&th, sizeof th, 1, p->ofp);
    byteStream->writeRawData((const char *)&th, sizeof th);

    if (p->oprof){
        if(p->ofp)
            fwrite (p->oprof, ntohl(p->oprof[0]), 1, p->ofp);
        byteStream->writeRawData((const char *)p->oprof, ntohl(p->oprof[0]));
    }
} else if (p->colors > 3){
   if(p->ofp)
       fprintf (p->ofp,
      "P7\nWIDTH %d\nHEIGHT %d\nDEPTH %d\nMAXVAL %d\nTUPLTYPE %s\nENDHDR\n",
        p->width, p->height, p->colors, (1 << p->output_bps)-1, p->cdesc);
    char *hdr = (char *)malloc(sizeof(char)*(66 + strlen(p->cdesc)+1));
    memset(hdr, 0, (66 + strlen(p->cdesc)+1));
    snprintf(hdr,66 + strlen(p->cdesc),"P7\nWIDTH %d\nHEIGHT %d\nDEPTH %d\nMAXVAL %d\nTUPLTYPE %s\nENDHDR\n",
        p->width, p->height, p->colors, (1 << p->output_bps)-1, p->cdesc);
    byteStream->writeRawData(hdr, 66 + strlen(p->cdesc));

}
else{
   if(p->ofp)
       fprintf (p->ofp, "P%d\n%d %d\n%d\n",
        p->colors/2+5, p->width, p->height, (1 << p->output_bps)-1);
    char *hdr = (char *)malloc(sizeof(char)*(18));
    memset(hdr, 0, (18));
    snprintf(hdr,17,"P%d\n%d %d\n%d\n",
        p->colors/2+5, p->width, p->height, (1 << p->output_bps)-1);
    byteStream->writeRawData(hdr, 17);

}
  soff  = flip_index (p,0, 0);
  cstep = flip_index (p,0, 1) - soff;
  rstep = flip_index (p,1, 0) - flip_index (p,0, p->width);
  for (row=0; row < p->height; row++, soff += rstep) {
    for (col=0; col < p->width; col++, soff += cstep)
      if (p->output_bps == 8)
           FORCC ppm [col*p->colors+c] = p->curve[p->image[soff][c]] >> 8;
      else FORCC ppm2[col*p->colors+c] = p->curve[p->image[soff][c]];
    if (p->output_bps == 16 && !p->output_tiff && htons(0x55aa) != 0x55aa)
      swab ((char *)ppm2, (char *)ppm2, p->width*p->colors*2);
   if(p->ofp)
       fwrite (ppm, p->colors*p->output_bps/8, p->width, p->ofp);
    byteStream->writeRawData((const char *)ppm, (p->colors*p->output_bps/8)*p->width);
  }
  free(ppm);
}

int DcRawQT::themain (int argc, const char **argv, QByteArray *outArray)
{
  int arg, status=0;
  int timestamp_only=0, thumbnail_only=0, identify_only=0;
  int user_qual=-1, user_black=-1, user_sat=-1, user_flip=-1;
  int use_fuji_rotate=1, write_to_stdout=0, quality, i, c;
  const char *sp, *bpfile=0, *dark_frame=0, *write_ext;
  char opm, opt, *ofname, *cp;
  struct utimbuf ut;
#ifndef NO_LCMS
  const char *cam_profile=0, *out_profile=0;
#endif

  p = new struct dcraw;

#ifndef LOCALTIME
  putenv ((char *) "TZ=UTC");
#endif
#ifdef LOCALEDIR
  setlocale (LC_CTYPE, "");
  setlocale (LC_MESSAGES, "");
  bindtextdomain ("dcraw", LOCALEDIR);
  textdomain ("dcraw");
#endif
    qDebug("Initializing DcRawQT");
  init_dcraw(p);
  if (argc == 1) {
    printf(_("\nRaw photo decoder \"dcraw\" v%s"), VERSION);
    printf(_("\nby Dave Coffin, dcoffin a cybercom o net\n"));
    printf(_("\nUsage:  %s [OPTION]... [FILE]...\n\n"), argv[0]);
    puts(_("-v        Print verbose messages"));
    puts(_("-c        Write image data to standard output"));
    puts(_("-e        Extract embedded thumbnail image"));
    puts(_("-i        Identify files without decoding them"));
    puts(_("-i -v     Identify files and show metadata"));
    puts(_("-z        Change file dates to camera timestamp"));
    puts(_("-w        Use camera white balance, if possible"));
    puts(_("-a        Average the whole image for white balance"));
    puts(_("-A <x y w h> Average a grey box for white balance"));
    puts(_("-r <r g b g> Set custom white balance"));
    puts(_("+M/-M     Use/don't use an embedded color matrix"));
    puts(_("-C <r b>  Correct chromatic aberration"));
    puts(_("-P <file> Fix the dead pixels listed in this file"));
    puts(_("-K <file> Subtract dark frame (16-bit raw PGM)"));
    puts(_("-k <num>  Set the darkness level"));
    puts(_("-S <num>  Set the saturation level"));
    puts(_("-n <num>  Set threshold for wavelet denoising"));
    puts(_("-H [0-9]  Highlight mode (0=clip, 1=unclip, 2=blend, 3+=rebuild)"));
    puts(_("-t [0-7]  Flip image (0=none, 3=180, 5=90CCW, 6=90CW)"));
    puts(_("-o [0-5]  Output colorspace (raw,sRGB,Adobe,Wide,ProPhoto,XYZ)"));
#ifndef NO_LCMS
    puts(_("-o <file> Apply output ICC profile from file"));
    puts(_("-p <file> Apply camera ICC profile from file or \"embed\""));
#endif
    puts(_("-d        Document mode (no color, no interpolation)"));
    puts(_("-D        Document mode without scaling (totally raw)"));
    puts(_("-j        Don't stretch or rotate raw pixels"));
    puts(_("-W        Don't automatically brighten the image"));
    puts(_("-b <num>  Adjust brightness (default = 1.0)"));
    puts(_("-g <p ts> Set custom gamma curve (default = 2.222 4.5)"));
    puts(_("-q [0-3]  Set the interpolation quality"));
    puts(_("-h        Half-size color image (twice as fast as \"-q 0\")"));
    puts(_("-f        Interpolate RGGB as four colors"));
    puts(_("-m <num>  Apply a 3x3 median filter to R-G and B-G"));
    puts(_("-s [0..N-1] Select one raw image or \"all\" from each file"));
    puts(_("-6        Write 16-bit instead of 8-bit"));
    puts(_("-4        Linear 16-bit, same as \"-6 -W -g 1 1\""));
    puts(_("-T        Write TIFF instead of PPM"));
    puts("");
    return 1;
  }
  argv[argc] = "";
  for (arg=1; (((opm = argv[arg][0]) - 2) | 2) == '+'; ) {
    opt = argv[arg++][1];
    if ((cp = (char *)strchr (sp="nbrkStqmHACg", opt)))
      for (i=0; i < "114111111422"[cp-sp]-'0'; i++)
	if (!isdigit(argv[arg+i][0])) {
	  fprintf (stderr,_("Non-numeric argument to \"-%c\"\n"), opt);
	  return 1;
	}
    switch (opt) {
      case 'n':  p->threshold   = atof(argv[arg++]);  break;
      case 'b':  p->bright      = atof(argv[arg++]);  break;
      case 'r':
           FORC4 p->user_mul[c] = atof(argv[arg++]);  break;
      case 'C':  p->aber[0] = 1 / atof(argv[arg++]);
                 p->aber[2] = 1 / atof(argv[arg++]);  break;
      case 'g':  p->gamm[0] =     atof(argv[arg++]);
                 p->gamm[1] =     atof(argv[arg++]);
                 if (p->gamm[0]) p->gamm[0] = 1/p->gamm[0]; break;
      case 'k':  user_black  = atoi(argv[arg++]);  break;
      case 'S':  user_sat    = atoi(argv[arg++]);  break;
      case 't':  user_flip   = atoi(argv[arg++]);  break;
      case 'q':  user_qual   = atoi(argv[arg++]);  break;
      case 'm':  p->med_passes  = atoi(argv[arg++]);  break;
      case 'H':  p->highlight   = atoi(argv[arg++]);  break;
      case 's':
        p->shot_select = abs(atoi(argv[arg]));
        p->multi_out = !strcmp(argv[arg++],"all");
	break;
      case 'o':
	if (isdigit(argv[arg][0]) && !argv[arg][1])
          p->output_color = atoi(argv[arg++]);
#ifndef NO_LCMS
        else     out_profile = argv[arg++];
	break;
      case 'p':  cam_profile = argv[arg++];
#endif
	break;
      case 'P':  bpfile     = argv[arg++];  break;
      case 'K':  dark_frame = argv[arg++];  break;
      case 'z':  timestamp_only    = 1;  break;
      case 'e':  thumbnail_only    = 1;  break;
      case 'i':  identify_only     = 1;  break;
      case 'c':  write_to_stdout   = 1;  break;
      case 'v':  p->verbose           = 1;  break;
      case 'h':  p->half_size         = 1;		/* "-h" implies "-f" */
      case 'f':  p->four_color_rgb    = 1;  break;
      case 'A':  FORC4 p->greybox[c]  = atoi(argv[arg++]);
      case 'a':  p->use_auto_wb       = 1;  break;
      case 'w':  p->use_camera_wb     = 1;  break;
      case 'M':  p->use_camera_matrix = (opm == '+');  break;
      case 'D':
      case 'd':  p->document_mode = 1 + (opt == 'D');
      case 'j':  use_fuji_rotate   = 0;  break;
      case 'W':  p->no_auto_bright    = 1;  break;
      case 'T':  p->output_tiff       = 1;  break;
      case '4':  p->gamm[0] = p->gamm[1] =
                 p->no_auto_bright    = 1;
      case '6':  p->output_bps       = 16;  break;
      default:
	fprintf (stderr,_("Unknown option \"-%c\".\n"), opt);
	return 1;
    }
  }
  if (p->use_camera_matrix < 0)
      p->use_camera_matrix = p->use_camera_wb;
  if (arg == argc) {
    fprintf (stderr,_("No files to process.\n"));
    qDebug("No files to process.\n");
    return 1;
  }
  if (write_to_stdout) {
    if (isatty(1)) {
      fprintf (stderr,_("Will not write an image to the terminal!\n"));
      qDebug("Will not write an image to the terminal!\n");
      p->ofp = stderr;
//      return 1;
    }
#if defined(WIN32) || defined(DJGPP) || defined(__CYGWIN__)
    if (setmode(1,O_BINARY) < 0) {
      perror ("setmode()");
      return 1;
    }
#endif
  }
  for ( ; arg < argc; arg++) {
    status = 1;
    p->image = 0;
    p->oprof = 0;
    p->meta_data = ofname = 0;
    p->ofp = 0;
    if (setjmp (failure)) {
      if (fileno(p->ifp) > 2) fclose(p->ifp);
      if (fileno(p->ofp) > 2) fclose(p->ofp);
      status = 1;
      goto cleanup;
    }
    p->ifname = argv[arg];
    if (!(p->ifp = fopen (p->ifname, "rb"))) {
      perror (p->ifname);
      continue;
    }
    status = (identify(p),!p->is_raw);
    if (user_flip >= 0)
      p->flip = user_flip;
    switch ((p->flip+3600) % 360) {
      case 270:  p->flip = 5;  break;
      case 180:  p->flip = 3;  break;
      case  90:  p->flip = 6;
    }
    if (timestamp_only) {
      if ((status = !p->timestamp))
        fprintf (stderr,_("%s has no timestamp->\n"), p->ifname);
      else if (identify_only){
        printf ("%10ld%10d %s\n", (long) p->timestamp, p->shot_order, p->ifname);
        this->identifyInformation += QString("%1%2 %3\n").arg((long) p->timestamp,10).arg(p->shot_order,10).arg(p->ifname);
    }
      else {
        if (p->verbose)
          fprintf (stderr,_("%s time set to %d.\n"), p->ifname, (int) p->timestamp);
        ut.actime = ut.modtime = p->timestamp;
        utime (p->ifname, &ut);
      }
      goto next;
    }
    p->write_fun= &CLASS write_ppm_tiff;
    if (thumbnail_only) {
      if ((status = !p->thumb_offset)) {
        fprintf (stderr,_("%s has no thumbnail.\n"), p->ifname);
	goto next;
      } else if (p->thumb_load_raw) {
        p->load_raw =p->thumb_load_raw;
        p->data_offset = p->thumb_offset;
        p->height = p->thumb_height;
        p->width  = p->thumb_width;
        p->filters = 0;
      } else {
        fseek (p->ifp, p->thumb_offset, SEEK_SET);
        p->write_fun = p->write_thumb;
	goto thumbnail;
      }
    }
    if (p->load_raw == &CLASS kodak_ycbcr_load_raw) {
      p->height += p->height & 1;
      p->width  += p->width  & 1;
    }
    if (identify_only && p->verbose && p->make[0])
    {
      this->identifyInformation += QString("\nFilename: %1\n").arg(p->ifname);
      printf (_("\nFilename: %s\n"), p->ifname);
      this->identifyInformation += QString("Timestamp: %1").arg(ctime(&p->timestamp));
      printf (_("Timestamp: %s"), ctime(&p->timestamp));
      this->identifyInformation += QString("Camera: %1 %2\n").arg(p->make).arg(p->model);
      printf (_("Camera: %s %s\n"), p->make, p->model);
      if (p->artist[0]){
        this->identifyInformation += QString("Owner: %1\n").arg(p->artist);
        printf (_("Owner: %s\n"), p->artist);
    }
      if (p->dng_version) {
        this->identifyInformation += QString("DNG Version: ");
        printf (_("DNG Version: "));
        for (i=24; i >= 0; i -= 8){
         this->identifyInformation += QString("%1%2").arg(p->dng_version >> i & 255).arg((char)( i ? '.':'\n'));
          printf ("%d%c", p->dng_version >> i & 255, i ? '.':'\n');
        }
      }
      this->identifyInformation += QString("ISO speed: %1\n").arg((int) p->iso_speed);
      printf (_("ISO speed: %d\n"), (int) p->iso_speed);
      printf (_("Shutter: "));
      this->identifyInformation += QString("Shutter: ");
      if (p->shutter > 0 && p->shutter < 1) {
        p->shutter = (printf ("1/"), 1 / p->shutter);
        this->identifyInformation += QString("1/");
      }
      this->identifyInformation += QString("%1 sec\n").arg(p->shutter,0,'f',1);
      printf (_("%0.1f sec\n"), p->shutter);
      this->identifyInformation += QString("Aperture: f/%1\n").arg(p->aperture, 0,'f',1);
      printf (_("Aperture: f/%0.1f\n"), p->aperture);
      this->identifyInformation += QString("Focal length: %1 mm\n").arg(p->focal_len,0,'f',1);
      printf (_("Focal length: %0.1f mm\n"), p->focal_len);
      this->identifyInformation += QString("Embedded ICC profile: %1\n").arg(p->profile_length ? _("yes"):_("no"));
      printf (_("Embedded ICC profile: %s\n"), p->profile_length ? _("yes"):_("no"));
      this->identifyInformation += QString("Number of raw images: %1\n").arg(p->is_raw);
      printf (_("Number of raw images: %d\n"), p->is_raw);
      if (p->pixel_aspect != 1)
      {
        this->identifyInformation += QString("Pixel Aspect Ratio: %1\n").arg(p->pixel_aspect,0,'f',6);
        printf (_("Pixel Aspect Ratio: %0.6f\n"), p->pixel_aspect);
      }
      if (p->thumb_offset){
        this->identifyInformation += QString("Thumb size:  %1 x %2\n").arg(p->thumb_width).arg(p->thumb_height);
        printf (_("Thumb size:  %4d x %d\n"), p->thumb_width, p->thumb_height);
      }
      this->identifyInformation += QString("Full size:   %1 x %2\n").arg(p->raw_width).arg(p->raw_height);
      printf (_("Full size:   %4d x %d\n"), p->raw_width, p->raw_height);
    } else if (!p->is_raw)
      fprintf (stderr,_("Cannot decode file %s\n"), p->ifname);
    if (!p->is_raw) goto next;
    p->shrink = p->filters &&
        (p->half_size || p->threshold || p->aber[0] != 1 || p->aber[2] != 1);
    p->iheight = (p->height + p->shrink) >> p->shrink;
    p->iwidth  = (p->width  + p->shrink) >> p->shrink;
    if (identify_only) {
      if (p->verbose) {
        if (use_fuji_rotate) {
          if (p->fuji_width) {
            p->fuji_width = (p->fuji_width - 1 + p->shrink) >> p->shrink;
            p->iwidth = p->fuji_width / sqrt(0.5);
            p->iheight = (p->iheight - p->fuji_width) / sqrt(0.5);
	  } else {
            if (p->pixel_aspect < 1) p->iheight = p->iheight / p->pixel_aspect + 0.5;
            if (p->pixel_aspect > 1) p->iwidth  = p->iwidth  * p->pixel_aspect + 0.5;
	  }
	}
        if (p->flip & 4)
          SWAP(p->iheight,p->iwidth);
        this->identifyInformation += QString("Image size:  %1 x %2\n").arg(p->width).arg(p->height);
        printf (_("Image size:  %4d x %d\n"), p->width, p->height);
        this->identifyInformation += QString("Output size: %1 x %2\n").arg(p->iwidth).arg(p->iheight);
        printf (_("Output size: %4d x %d\n"), p->iwidth, p->iheight);
        this->identifyInformation += QString("Raw colors: %1").arg(p->colors);
        printf (_("Raw colors: %d"), p->colors);
        if (p->filters) {
	  printf (_("\nFilter pattern: "));
          this->identifyInformation += QString("\nFilter patter: ");
          if (!p->cdesc[3]) p->cdesc[3] = 'G';
          for (i=0; i < 16; i++){
            putchar (p->cdesc[fc(p,i >> 1,i & 1)]);
            this->identifyInformation += QString("%1").arg((char)p->cdesc[fc(p,i >> 1,i & 1)]);
          }
	}
        this->identifyInformation += QString("\nDaylight multipliers:");
        printf (_("\nDaylight multipliers:"));
        FORCC printf (" %f", p->pre_mul[c]);
        FORCC this->identifyInformation += QString(" %1").arg(p->pre_mul[c],0,'f');
        if (p->cam_mul[0] > 0) {
          this->identifyInformation += QString("\nCamera multipliers:");
          printf (_("\nCamera multipliers:"));
          FORC4 printf (" %f", p->cam_mul[c]);
          FORC4 this->identifyInformation += QString(" %1").arg(p->cam_mul[c],0,'f');
        }
	putchar ('\n');
    } else {
        this->identifyInformation += QString("%1 is a %2 %3 image.\n").arg(p->ifname).arg(p->make).arg(p->model);
        printf (_("%s is a %s %s image.\n"), p->ifname, p->make, p->model);
    }
next:
      fclose(p->ifp);
      continue;
    }
    if (p->use_camera_matrix && p->cmatrix[0][0] > 0.25) {
      memcpy (p->rgb_cam, p->cmatrix, sizeof p->cmatrix);
      p->raw_color = 0;
    }
    p->image = (ushort (*)[4]) calloc (p->iheight*p->iwidth, sizeof *p->image);
    merror (p,p->image, "main()");
    if (p->meta_length) {
      p->meta_data = (char *) malloc (p->meta_length);
      merror (p,p->meta_data, "main()");
    }
    if (p->verbose)
      fprintf (stderr,_("Loading %s %s image from %s ...\n"),
        p->make, p->model, p->ifname);
    if (p->shot_select >= p->is_raw)
      fprintf (stderr,_("%s: \"-s %d\" requests a nonexistent image!\n"),
        p->ifname, p->shot_select);
    fseeko (p->ifp, p->data_offset, SEEK_SET);
    (*p->load_raw)(p);
    if (p->zero_is_bad) remove_zeroes(p);
    bad_pixels (p,bpfile);
    if (dark_frame) subtract (p,dark_frame);
    quality = 2 + !p->fuji_width;
    if (user_qual >= 0) quality = user_qual;
    if (user_black >= 0) p->black = user_black;
    if (user_sat > 0) p->maximum = user_sat;
#ifdef COLORCHECK
    colorcheck();
#endif
#ifdef USE_RESTRICTED
    if (p->is_foveon && !p->document_mode) foveon_interpolate(p);
#endif
    if (!p->is_foveon && p->document_mode < 2) scale_colors(p);
    pre_interpolate(p);
    if (p->filters && !p->document_mode) {
      if (quality == 0)
        lin_interpolate(p);
      else if (quality == 1 || p->colors > 3)
        vng_interpolate(p);
      else if (quality == 2)
        ppg_interpolate(p);
      else ahd_interpolate(p);
    }
    if (p->mix_green)
      for (p->colors=3, i=0; i < p->height*p->width; i++)
        p->image[i][1] = (p->image[i][1] + p->image[i][3]) >> 1;
    if (!p->is_foveon && p->colors == 3) median_filter(p);
    if (!p->is_foveon && p->highlight == 2) blend_highlights(p);
    if (!p->is_foveon && p->highlight > 2) recover_highlights(p);
    if (use_fuji_rotate) fuji_rotate(p);
#ifndef NO_LCMS
    if (cam_profile) apply_profile (cam_profile, out_profile);
#endif
    convert_to_rgb(p);
    if (use_fuji_rotate) stretch(p);
thumbnail:
    if (p->write_fun == &CLASS jpeg_thumb)
      write_ext = ".jpg";
    else if (p->output_tiff &&p->write_fun== &CLASS write_ppm_tiff)
      write_ext = ".tiff";
    else
      write_ext = ".pgm\0.ppm\0.ppm\0.pam" + p->colors*5-5;
    ofname = (char *) malloc (strlen(p->ifname) + 64);
    merror (p,ofname, "main()");
    if (write_to_stdout)
      strcpy (ofname,_("standard output"));
    else {
      strcpy (ofname, p->ifname);
      if ((cp = strrchr (ofname, '.'))) *cp = 0;
      if (p->multi_out)
	sprintf (ofname+strlen(ofname), "_%0*d",
                snprintf(0,0,"%d",p->is_raw-1), p->shot_select);
      if (thumbnail_only)
	strcat (ofname, ".thumb");
      strcat (ofname, write_ext);
      p->ofp = fopen (ofname, "wb");
      if (!p->ofp) {
	status = 1;
	perror (ofname);
	goto cleanup;
      }
    }
    if (p->verbose)
      fprintf (stderr,_("Writing data to %s ...\n"), ofname);
    (*p->write_fun)(p,outArray);
    fclose(p->ifp);
    if (p->ofp != 0 && p->ofp != stdout) fclose(p->ofp);
cleanup:
    if (p->meta_data) free (p->meta_data);
    if (ofname) free (ofname);
    if (p->oprof) free (p->oprof);
    if (p->image) free (p->image);
    if (p->multi_out) {
      if (++p->shot_select < p->is_raw) arg--;
      else p->shot_select = 0;
    }
  }
  return status;
}