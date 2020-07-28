#include "PiGuideReader.h"


PiGuideReader::PiGuideReader(QObject *_parent, QString _port, int _baudrate, int _timeout, int _timeoutguide):
    QThread(_parent),
    serialPort(_port),
    baudRate(_baudrate),
    timeOut(_timeout),
    timeOutGuide(_timeoutguide)
{
    m_stopScan = false;
}
