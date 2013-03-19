#ifndef DCRAWQT_GLOBAL_H
#define DCRAWQT_GLOBAL_H

#include <QtCore/qglobal.h>
#include <QtGui>
#include <QStringList>

#if defined(DCRAWQT_LIBRARY)
#  define DCRAWQTSHARED_EXPORT Q_DECL_EXPORT
#else
#  define DCRAWQTSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // DCRAWQT_GLOBAL_H
