#ifndef DCRAW_H
#define DCRAW_H


/*
 All the global variables where stuffed into the typdef'd structure
 DcRAWImage.  This allows this to be wrapped by a C++ class, each 
 instance of the class having its own copy of these variables.  Also
 the pointers declarations to the load and write methods where modified
 to take a pointer to this structure.  The write methods where further
 modified to take a pointer to a QByteArray for storing of image file from
 the decoded raw image(either PNM, PGM, PPM or TIF) for easy conversion to a QPixmap
 or QImage object

 -- jsb
*/


/*
   All global variables are defined here, and all functions that
   access them are prefixed with "CLASS".  Note that a thread-safe
   C++ class cannot have non-const static local variables.
 */

extern "C" {

#define VERSION "8.99"

#ifndef _GNU_SOURCE
#define _GNU_SOURCE
#endif
#define _USE_MATH_DEFINES
#include <ctype.h>
#include <errno.h>
#include <fcntl.h>
#include <float.h>
#include <limits.h>
#include <math.h>
#include <setjmp.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <time.h>
#include <sys/types.h>
/*
   NO_JPEG disables decoding of compressed Kodak DC120 files.
   NO_LCMS disables the "-p" option.
 */
#ifndef NO_JPEG
#include <jpeglib.h>
#endif
#ifndef NO_LCMS
#include <lcms.h>
#endif
#ifdef LOCALEDIR
#include <libintl.h>
#define _(String) gettext(String)
#else
#define _(String) (String)
#endif
#ifdef DJGPP
#define fseeko fseek
#define ftello ftell
#else
#define fgetc getc_unlocked
#endif
#ifdef __CYGWIN__
#include <io.h>
#endif
#ifndef __MINGW__ //Added this so when using QT with the Native MS compiler vs MINGW under windows --jsb
#include <io.h>
#include <direct.h>
#define getcwd _getcwd
#define isatty _isatty
#define setmode _setmode
#endif
#ifdef WIN32
#include <sys/utime.h>
#ifndef HAVEWINSOCK
//#include <winsock2.h>
#endif
#pragma comment(lib, "ws2_32.lib")
#define snprintf _snprintf
#define strcasecmp stricmp
#define strncasecmp strnicmp
typedef __int64 INT64;
typedef unsigned __int64 UINT64;
#else
#include <unistd.h>
#include <utime.h>
#include <netinet/in.h>
typedef long long INT64;
typedef unsigned long long UINT64;
#endif

#ifdef LJPEG_DECODE
#error Please compile dcraw.c by itself.
#error Do not link it with ljpeg_decode.
#endif

#ifndef LONG_BIT
#define LONG_BIT (8 * sizeof (long))
#endif

#define ushort UshORt
typedef unsigned char uchar;
typedef unsigned short ushort;

struct decode {
  struct decode *branch[2];
  int leaf;
};// first_decode[2048], *second_decode, *free_decode;

struct tiff_ifd {
  int width, height, bps, comp, phint, offset, flip, samples, bytes;
};// tiff_ifd[10];

struct ph1 {
  int format, key_off, black, black_off, split_col, tag_21a;
  float tag_210;
};// ph1;


typedef struct dcraw{

    struct decode first_decode[2048], *second_decode, *free_decode;
    struct tiff_ifd tiff_ifd[10];
    struct ph1 ph1;

FILE *ifp, *ofp;
short order;
const char *ifname;
char *ofname;
char *meta_data;
char cdesc[5], desc[512], make[64], model[64], model2[64], artist[64];
float flash_used, canon_ev, iso_speed, shutter, aperture, focal_len;
time_t timestamp;
unsigned shot_order, kodak_cbpp, filters, exif_cfa, unique_id;
off_t    strip_offset, data_offset;
off_t    thumb_offset, meta_offset, profile_offset;
unsigned thumb_length, meta_length, profile_length;
unsigned thumb_misc, *oprof, fuji_layout, shot_select, multi_out;
unsigned tiff_nifds, tiff_samples, tiff_bps, tiff_compress;
unsigned black, maximum, mix_green, raw_color, zero_is_bad;
unsigned zero_after_ff, is_raw, dng_version, is_foveon, data_error;
unsigned tile_width, tile_length, gpsdata[32], load_flags;
ushort raw_height, raw_width, height, width, top_margin, left_margin;
ushort shrink, iheight, iwidth, fuji_width, thumb_width, thumb_height;
int flip, tiff_flip, colors;
double pixel_aspect, aber[4], gamm[6];
ushort (*image)[4], white[8][8], curve[0x10000], cr2_slice[3], sraw_mul[4];
float bright, user_mul[4], threshold;
int half_size, four_color_rgb, document_mode, highlight;
int verbose, use_auto_wb, use_camera_wb, use_camera_matrix;
int output_color, output_bps, output_tiff, med_passes;
int no_auto_bright;
unsigned greybox[4];
float cam_mul[4], pre_mul[4], cmatrix[3][4], rgb_cam[3][4];
int histogram[4][0x2000];
void(*write_thumb)(struct dcraw *,QByteArray *), (*write_fun)(struct dcraw *,QByteArray *);
void (*load_raw)(struct dcraw *), (*thumb_load_raw)(struct dcraw *);
bool imageWritten;
} DcRAWImage;

static const double xyz_rgb[3][3] = {			/* XYZ from RGB */
  { 0.412453, 0.357580, 0.180423 },
  { 0.212671, 0.715160, 0.072169 },
  { 0.019334, 0.119193, 0.950227 } };
static const float d65_white[3] = { 0.950456, 1, 1.088754 };


}



#endif // DCRAW_H
