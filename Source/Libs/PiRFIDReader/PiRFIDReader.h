#ifndef PIRFIDREADER_H
#define PIRFIDREADER_H

#include "pirfidreader_global.h"
#include <QThread>


class PIRFIDREADERSHARED_EXPORT PiRFIDReader : public QThread
{
    Q_OBJECT
//*******************************PROPERTIES***********************************************//
    //State
    Q_PROPERTY(int state READ state WRITE setState NOTIFY stateChanged)
    //Logs
    Q_PROPERTY(QString log READ log WRITE setLog NOTIFY logChanged)
    //RFID data
    Q_PROPERTY(QString dataCard READ dataCard WRITE setDataCard NOTIFY dataCardChanged)

//*******************************LIST STATE************************************************//
    enum{
        RUNNING,
        CONNECTED,
        DISCONNECTED,
        TIMEOUT,
        ERROR
    }State;


//******************************CONTRUCTOR*************************************************//
public:
    PiRFIDReader(QObject *_parent = nullptr, QString _port = "", int _baudrate = 115200, int _timeout = 3000, int _nextcardtime = 2000);
    ~PiRFIDReader();

//***********************************PUBLIC VAILABLE**************************************//
public:
    //Cong ket noi
    QString     serialPort;
    //Toc do truyen
    int         baudRate;
    //Thoi gian time out
    int         timeOut;
    //Thoi gian giua cac the lien tiep
    int         timeNextCard;
    //Trang thai dang co the
    bool        onCard;

//***********************************PUBLIC FUNCTIONS**************************************//
public:
    //Lay trang thai hien tai
    int         state();
    //Lay log hien tai
    QString     log();
    //Lay ma the doc duoc hien tai
    QString     dataCard();


//************************************SIGNALS**********************************************//
signals:
    //Khi trang thai thay doi
    void stateChanged(int);
    //Khi log thay doi
    void logChanged(QString);
    //Khi the thay doi
    void dataCardChanged(QString);

//***********************************PRIVATE FUNCTIONS*************************************//
private:
    //Bat dau thread
    void run() override;
    //Set trang thai
    void setState(int);
    //Set log
    void setLog(QString);
    //Set rfid card
    void setDataCard(QString);

//***********************************PRIVATE FUNCTIONS*************************************//
private:
    //Lua ma RFID cu
    QString     m_oldCard;
    //Bien dung scan the rfid
    bool        m_stopScan;

//***********************************STATIC PRIVATE****************************************//
private:
    //Khoa trang thai chi cho 1 thread scan the rfid
    static      int         m_oneScan;
    //Trang thai cua thread
    static      int         m_state;
    //Log hien tai
    static      QString     m_log;
    //The hien tai
    static      QString     m_dataCard;


};

#endif // PIRFIDREADER_H
