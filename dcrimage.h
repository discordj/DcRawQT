#ifndef DCRIMAGE_H
#define DCRIMAGE_H

#include <QObject>
#include <QImage>
#include <QRgb>
#include <QQueue>
#include <QMutex>
#include <QRectF>

#include "dcraw.h"
#include "dcrawqt.h"

#ifdef USE_CIMG
#include <CImg.h>
using namespace cimg_library;
#ifndef cimg_display
#define cimg_display 0
#endif
#endif

#include "dcrawqt_global.h"
/*
This is my object that interfaces with QT and the bridge code into dcraw.
It will use either the CImg library or QImage for storing the image of screen.  Ultimately 
the QImage or QPixmap can be used for displaying to the screen.
*/
class DCRAWQTSHARED_EXPORT DcRImage : public QObject
{
	Q_OBJECT

public:
    DcRImage(QObject *parent=0); //creates an empty object
	//creates an object that parses the raw file with the arguments specified in args
	DcRImage(const QString &fileName, const QStringList &args, QObject *parent=0);
	//creates an object that parses the raw file for just the thumbnail in the raw image
	DcRImage(const QString &fileName, bool thumbNailOnly, QObject *parent=0);
	~DcRImage();

	//loads the raw image file with the arguments specified by args
	void load(const QString &fileName,const QStringList &args);
	//loads the raw image file with a default set of args
	void load(const QString &fileName);
	void load(int argc, char *argv[]);
	void loadthumbnail(const QString &fileName);
	bool isRaw(const QString &fileName);
	bool isNull() { return _isnull; }
	QImage getimage();
	const QPixmap getpixmap(); 
	QImage getthumbimage();
	const QPixmap getthumbpixmap();
	bool save(QString fileName, QString fileType, int quality);
	bool save(QString fileName);
	void restore();
	QString rawinformation() { return _rawinfo; }
    int *RawHistogram(int index) { return _rawhistogram[index]; }
    int *LiveHistogram(int index) { return _livehistogram[index]; }
	QString getmessage();
	void setQImagetextkeys(QImage *image);
	//will move to a separate activity
	void crop(int x0, int y0, int x1, int y1);
	QRectF croprect() { return _croprect; }
	void setcroprect(QRectF rect){_croprect = rect; }
	
	
protected slots:
	void on_dcraw_process_notify(const QString& message);

signals:
	void process_notify(const QString& message);
private:
#ifdef USE_CIMG
   CImg<unsigned char> _img8bit; //CImg object for 8bit/pixel image
   CImg<unsigned short> _img16bit;//CImg object for 16bit/pixel image
#else
   QImage *_rawimage; // this is only used if the CImg library isn't used, only 8bit/pixel
#endif
   DcRawQT *_dcraw; // our pointer to the bridge class

   bool _israw; //if this is a supported raw image format will be true
   bool _isnull; //if no image has been processed or there was an issue this will be true;

   int _rawhistogram[4][0x2000]; //maps to the dcraw histogram data, this is the histogram for the RAW IMAGE
   int _livehistogram[4][0x2000]; //maps to the cimg/QImage histogram data, this is the live histogram

   QString _rawinfo;// the exif info from the raw image (ISO, Shutterspeed, etc)
   QString _filename;// the file name of the raw image
   QImage _thumbnail; // the thumbail as a QImage if it was extracted

   //The next two items are used for the message queue from the bridge class
   //that give information and feedback on where it is in the process
   QQueue<QString> _messages;
   QMutex _mutex;
   QRectF _croprect;

#ifdef USE_CIMG
   void createCImg(DcRAWImage *p); //
   void createCImgTif(DcRAWImage *p, char **memorydata, unsigned int *memsize, const unsigned int bytes_per_pixel);
   void createCImgPnm(char **memorydata, unsigned int *memsize);
   void cropCImg(int x0, int y0, int x1, int y1);
#else
   void createQImage(DcRAWImage *p); //internal method for creating the QImage object from the image structure in dcraw
#endif
   void buildLiveHistogram();
   void buildRawHistogram();
};

#endif // DCRIMAGE_H
