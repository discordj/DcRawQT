#include "dcrimage.h"

DcRImage::DcRImage(QObject *parent)
	: QObject(parent)
{
	_israw = false;
	_isnull = true;
#ifndef USE_CIMG
	_rawimage = 0;
#endif
	_dcraw = new DcRawQT();
	connect(_dcraw,SIGNAL(process_notify(const QString&)),this,SLOT(on_dcraw_process_notify(const QString&)),Qt::DirectConnection);
}

DcRImage::DcRImage(const QString &fileName, const QStringList &args, QObject *parent) : QObject(parent)
{
	_israw = false;
	_isnull = true;
#ifndef USE_CIMG
	_rawimage = 0;
#endif
	_dcraw = new DcRawQT();
	connect(_dcraw,SIGNAL(process_notify(const QString&)),this,SLOT(on_dcraw_process_notify(const QString&)),Qt::DirectConnection);

	_filename = fileName;

	if((_israw = isRaw(fileName)))
	{
		_rawinfo = _dcraw->Identify(_filename);
		
		load(fileName,args);
	}
}

DcRImage::DcRImage(const QString &fileName, bool thumbNailOnly, QObject *parent) : QObject(parent)
{
	_israw = false;
	_isnull = true;
#ifndef USE_CIMG
	_rawimage = 0;
#endif

	_dcraw = new DcRawQT();
	connect(_dcraw,SIGNAL(process_notify(const QString&)),this,SLOT(on_dcraw_process_notify(const QString&)),Qt::DirectConnection);

	_filename = fileName;

	_israw = isRaw(fileName); 

	if(_israw)
		_rawinfo = _dcraw->Identify(_filename);


	if(thumbNailOnly && _israw)
	{
		loadthumbnail(_filename);
	}

	if(!thumbNailOnly && _israw)
	{
		load(fileName);
	}

}



DcRImage::~DcRImage()
{
    qDebug("~DcRImage");

	if(_dcraw) delete _dcraw;
#ifndef USE_CIMG
	if(_rawimage) delete _rawimage;
#else
	//delete _img16bit;
	//delete _img8bit;
#endif
}

void DcRImage::load(int argc, char *argv[])
{
			if(_dcraw->GetRawImage(argc, argv))
			{
				_isnull = false;
				_israw = true;
//#ifdef USE_CIMG
//				createCImg(_dcraw->getdcrawimage());
//#else
//				createQImage(_dcraw->getdcrawimage());
//#endif
//				buildRawHistogram();
//				buildLiveHistogram();
			}
			else {
				_isnull = true;
				_israw = false;
			}

}

void DcRImage::load(const QString &fileName,const QStringList &args)
{

	_filename = fileName;

	if(_dcraw){
		_israw = isRaw(fileName); 

		if(_israw) {
            _rawinfo = _dcraw->IdentifyingInformation();

			if(_dcraw->GetRawImage(fileName, args))
			{
				_isnull = false;
				if(!args.contains("-i"))
				{
#ifdef USE_CIMG
					createCImg(_dcraw->getdcrawimage());
#else
					createQImage(_dcraw->getdcrawimage());
#endif
					buildRawHistogram();
					buildLiveHistogram();
				}
			}

		}
	}
}

void DcRImage::load(const QString &fileName)
{
	_filename = fileName;
	if(_dcraw){
		_israw = isRaw(fileName); 

		if(_israw) {
                    _rawinfo = _dcraw->IdentifyingInformation();

			if(_dcraw->GetRawImage(fileName))
			{
				_isnull = false;
#ifdef USE_CIMG
				createCImg(_dcraw->getdcrawimage());
#else
				createQImage(_dcraw->getdcrawimage());
#endif
				buildRawHistogram();
				buildLiveHistogram();
			}

		}
	}
}

void DcRImage::loadthumbnail(const QString &fileName)
{
	if(_dcraw)
	{
		QByteArray *thumbdata;

		if((thumbdata = _dcraw->GetThumbNail(fileName)))
		{
			_isnull = false;
			_thumbnail.loadFromData(*thumbdata);
		}
	}
}

bool DcRImage::isRaw(const QString &fileName)
{
	if(_dcraw != 0)
	{
		return _dcraw->IsRaw(fileName);
	}

	return false;
}

QImage DcRImage::getthumbimage()
{
	return _thumbnail;
}
const QPixmap DcRImage::getthumbpixmap()
{
	QPixmap pm = QPixmap::fromImage(_thumbnail);
	return pm;
}

void DcRImage::setQImagetextkeys(QImage *image)
{
	QStringList infolist = _rawinfo.split("\n",QString::SkipEmptyParts);
	
	foreach(QString item, infolist)
	{
		QStringList iteminfo = item.split(": ");
		image->setText(iteminfo.at(0),iteminfo.at(1));
	}
}
QImage DcRImage::getimage()
{
#ifdef USE_CIMG
	if(!_croprect.isEmpty() && !_croprect.isNull() && _croprect.isValid())
	{
		 int x0 = _croprect.toRect().x();
		 int y0 = _croprect.toRect().y();
		 int x1 = _croprect.toRect().x() + _croprect.toRect().width();
		 int y1 = _croprect.toRect().y() + _croprect.toRect().height();
		crop(x0,y0,x1,y1);
	}
	if(!_img16bit.is_empty())
	{
		QImage qImage(_img16bit.width(), _img16bit.height(), QImage::Format_RGB32);
    	unsigned short *sptr_r=0, *sptr_g=0, *sptr_b=0;
		sptr_r = _img16bit.data(0,0,0,0);
		if(_img16bit.spectrum() >=2 )
			sptr_g = _img16bit.data(0,0,0,1);			
		if(_img16bit.spectrum() >=3 )
			sptr_b = _img16bit.data(0,0,0,2);

		for(int row=0; row < qImage.height(); row++){
			for(int col=0; col < qImage.width(); col++)
			{
				QRgb rgb = qRgb(_img16bit.spectrum() > 1 ? (*sptr_r++)>> 8 : *sptr_r >> 8,
								_img16bit.spectrum() >= 2 ? (*sptr_g++) >> 8 :(*sptr_r) >> 8 ,
								_img16bit.spectrum() >= 3 ? (*sptr_b++) >> 8 : (*sptr_r++) >> 8 );
				qImage.setPixel(col,row,rgb);
			}
		}

		setQImagetextkeys(&qImage); //Copy the exif info from the dcraw image to the QImage text.
		return qImage;
	}
	if(!_img8bit.is_empty())
	{
		QImage qImage(_img8bit.width(), _img8bit.height(), QImage::Format_RGB32);
    	unsigned char *sptr_r=0, *sptr_g=0, *sptr_b=0;
		sptr_r = _img8bit.data(0,0,0,0);
		if(_img8bit.spectrum() >=2 )
			sptr_g = _img8bit.data(0,0,0,1);			
		if(_img8bit.spectrum() >=3 )
			sptr_b = _img8bit.data(0,0,0,2);

		for(int row=0; row < qImage.height(); row++){
			for(int col=0; col < qImage.width(); col++)
			{
				QRgb rgb = qRgb(_img8bit.spectrum() > 1 ? *sptr_r++ : *sptr_r  ,
								_img8bit.spectrum() >= 2 ? *sptr_g++ : *sptr_r,
								_img8bit.spectrum() >=3 ? *sptr_b++ : *sptr_r++);
				qImage.setPixel(col,row,rgb);
			}
		}
		setQImagetextkeys(&qImage);//Copy the exif info from the dcraw image to the QImage text.
		return qImage;
	}
	return QImage();
#else
	QImage qImage(*_rawimage);

	setQImagetextkeys(&qImage);

	return qImage;
#endif
	
}
bool DcRImage::save(QString fileName, QString fileType, int quality)
{
	return getimage().save(fileName, fileType.toLatin1(), quality);
}
bool DcRImage::save(QString fileName)
{
	return getimage().save(fileName);
}

void DcRImage::restore() 
{
#ifdef USE_CIMG
	_croprect = QRectF(0,0,0,0);
	createCImg(_dcraw->getdcrawimage()); 
#else
	createQImage(_dcraw->getdcrawimage());
#endif
	buildLiveHistogram();
}


QString DcRImage::getmessage()
{
	QString message;
	{
		QMutexLocker locker(&_mutex);
		if(!_messages.isEmpty())
			message = _messages.dequeue();
	}

	return message;

}

void DcRImage::crop(int x0, int y0, int x1, int y1)
{
#ifdef USE_CIMG
	cropCImg(x0,y0,x1,y1); 
#endif
}

//Protected slots
void DcRImage::on_dcraw_process_notify(const QString& message)
{
	{
		QMutexLocker locker(&_mutex);
		_messages.enqueue(message);
		qDebug(qPrintable(QString("%2 message(s), Enqueued: %1").arg(message).arg(_messages.count())));
	}

	emit process_notify(message);
}


//Private functions/methods
void DcRImage::buildRawHistogram()
{
	memset(_rawhistogram, 0, sizeof(_rawhistogram));
	for(int i=0; i < _dcraw->getdcrawimage()->colors; i++)
    {
        for(int j=0; j < 8192; j++)
        {
			_rawhistogram[i][j] = _dcraw->Histogram(i,j);
        }
    }
}

void DcRImage::buildLiveHistogram()
{
	memset(_livehistogram, 0, sizeof(_livehistogram));

#ifdef USE_CIMG
	if(!_img16bit.is_empty())
    {
		unsigned short* cptr_r, *cptr_g, *cptr_b;
	      cptr_r = _img16bit.data(0,0,0,0);
		  if(_img16bit.spectrum() >=2 )
			cptr_g = _img16bit.data(0,0,0,1);
		  if(_img16bit.spectrum() >=3 )
			cptr_b = _img16bit.data(0,0,0,2);
	
		  for(int row=0; row < _img16bit.height(); row++)
			  for(int col=0; col < _img16bit.width(); col++)
			  {
				  _livehistogram[0][(int)(*cptr_r++)>>3]++;
				  if(_img16bit.spectrum() >= 2)
					  _livehistogram[1][(int)(*cptr_g++)>>3]++;
				  if(_img16bit.spectrum() >=3)
					  _livehistogram[2][(int)(*cptr_b++)>>3]++;
			  }


    }
	else if(!_img8bit.is_empty())
    {
		unsigned char* cptr_r, *cptr_g, *cptr_b;
	      cptr_r = _img8bit.data(0,0,0,0);
		  if(_img8bit.spectrum() >=2 )
			cptr_g = _img8bit.data(0,0,0,1);
		  if(_img8bit.spectrum() >=3 )
			cptr_b = _img8bit.data(0,0,0,2);
	
		  for(int row=0; row < _img8bit.height(); row++)
			  for(int col=0; col < _img8bit.width(); col++)
			  {
				  _livehistogram[0][(int)*cptr_r++]++;
				  if(_img8bit.spectrum() >= 2)
					  _livehistogram[1][(int)*cptr_g++]++;
				  if(_img8bit.spectrum() >=3)
					  _livehistogram[2][(int)*cptr_b++]++;
			  }
    }
#else
		  for(int row=0; row < _rawimage->height(); row++)
			  for(int col=0; col < _rawimage->width(); col++)
			  {
				  QRgb rgb = _rawimage->pixel(col,row);

				  _livehistogram[0][qRed(rgb)]++;
				  if(_dcraw->getdcrawimage()->colors >= 2)
					  _livehistogram[1][qGreen(rgb)]++;
				  if(_dcraw->getdcrawimage()->colors >=3)
					  _livehistogram[2][qBlue(rgb)]++;
			  }

#endif

}
#ifdef USE_CIMG
void DcRImage::createCImgPnm(char **memorydata, unsigned int *memsize)
{
	if(!_img16bit.is_empty())
    {
            _img16bit.save_pnm_tomem(memorydata, memsize);
    }
	else if(!_img8bit.is_empty())
    {
            _img8bit.save_pnm_tomem(memorydata, memsize);
    }

}

void DcRImage::cropCImg(int x0, int y0, int x1, int y1)
  {
	  if(!_img16bit.is_empty())
	  {
		  _img16bit.crop(x0,y0,x1,y1);
	  }
	  else if(!_img8bit.is_empty())
		  _img8bit.crop(x0,y0,x1,y1);

      buildLiveHistogram();

  }
#endif
