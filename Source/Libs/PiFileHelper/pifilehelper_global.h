#ifndef PIFILEHELPER_GLOBAL_H
#define PIFILEHELPER_GLOBAL_H

#include <QtCore/qglobal.h>

#if defined(PIFILEHELPER_LIBRARY)
#  define PIFILEHELPERSHARED_EXPORT Q_DECL_EXPORT
#else
#  define PIFILEHELPERSHARED_EXPORT Q_DECL_IMPORT
#endif

#endif // PIFILEHELPER_GLOBAL_H
