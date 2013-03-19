#ifndef DCRAWQT_H
#define DCRAWQT_H

#include "dcrawqt_global.h"

#include <QSize>
#include <QtWidgets/QProgressDialog>
#include <QStringList>

#include "dcraw.h"


/*
This is the bridge class, used to call into the C code of
dcraw. It keeps a pointer to the dcraw instance data.
*/

class DcRawQT : public QObject {
	Q_OBJECT
public:
   DcRawQT();
   ~DcRawQT();
   QString Identify(QString filename);
   QByteArray *GetThumbNail(QString filename);
   QByteArray *GetThumbNail(QString filename, QStringList args);
   QByteArray *GetImage(QString filename);
   QByteArray *GetImage(QString filename, QStringList args);
   QByteArray *GetImage(int argc, char *argv[]);
   bool GetRawImage(QString filename);
   bool GetRawImage(QString filename, QStringList args);
   bool GetRawImage(int argc, char *argv[]);
   bool IsRaw(QString filename);
   int *Histogram(int index) { return histogram[index]; }
   int Histogram(int index1, int index2) { return histogram[index1][index2]; }
   QString IdentifyingInformation() { return identifyInformation; }
   void setShowProgress(bool show) { showProgress = show; }
   DcRAWImage *getdcrawimage() { return p; }
private:
   int histogram[4][0x2000]; //maps to the dcraw histogram data, this is the histogram for the RAW IMAGE
   QString identifyInformation;
   bool _isRaw;
   bool showProgress;
   DcRAWImage *p; //dcraw instance data
   int BuildCommandLine(QStringList argsList, char*** argv);
   int themain (int argc, const char **argv, QByteArray *imageArray);
   int dcrawmain (int argc, const char **argv, QByteArray *imageArray);
   void buildHistogram();

signals:
   void process_notify(const QString& message);
};

#endif // DCRAWQT_H
