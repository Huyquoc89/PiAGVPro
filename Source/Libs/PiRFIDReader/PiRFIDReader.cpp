#include "PiRFIDReader.h"

//******************************STATIC DECLARE****************************//
int         PiRFIDReader::m_oneScan;
int         PiRFIDReader::m_state;
QString     PiRFIDReader::m_log;
QString     PiRFIDReader::m_dataCard;


PiRFIDReader::PiRFIDReader(QObject *_parent, QString _port, int _baudrate, int _timeout, int _timenextcard) :
    QThread(_parent),
    serialPort(_port),
    baudRate(_baudrate),
    timeOut(_timeout),
    timeNextCard(_timenextcard)
{
    m_stopScan = false;
}

void PiRFIDReader::run()
{

}
