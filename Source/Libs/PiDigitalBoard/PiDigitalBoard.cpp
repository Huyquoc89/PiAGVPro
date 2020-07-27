#include "PiDigitalBoard.h"

QList<bool> PiDigitalBoard::m_input;
QList<bool> PiDigitalBoard::m_output;
bool        PiDigitalBoard::m_oneScan;

PiDigitalBoard::PiDigitalBoard(QObject *_parent,QString _path) :
    QThread (_parent), m_configPath(_path)
{
}

bool PiDigitalBoard::getInput(int addr)
{
    return m_input[addr];
}

void PiDigitalBoard::run()
{
    if(m_oneScan != true)
    {
        m_oneScan = true;
        while(true)
        {
            // Code here update input output list in here
        }
    }
}
