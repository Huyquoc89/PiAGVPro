#ifndef PIDIGITALBOARD_H
#define PIDIGITALBOARD_H

#include "pidigitalboard_global.h"
#include <QThread>

#define ON  true
#define OFF false

// Read Write Digital Input OUtput
class PIDIGITALBOARDSHARED_EXPORT PiDigitalBoard : public QThread
{
    Q_OBJECT
    //Input
    Q_PROPERTY(QList<bool> input READ input WRITE setInput NOTIFY inputChanged)
    //Output
    Q_PROPERTY(QList<bool> output READ output WRITE setOutput NOTIFY outputChanged)
    //
    Q_PROPERTY(QString configPath READ configPath WRITE setConfigPath NOTIFY configPathChanged)


    //Format common
    //Update state
    Q_PROPERTY(int state READ state WRITE setState NOTIFY stateChanged)
    //Log
    Q_PROPERTY(QString log READ log WRITE setLog NOTIFY logChanged)

    enum{
        INIT_DONE = 0, //Trang thai da init board xong
        ERROR_DIR
    };


public:
    PiDigitalBoard(QObject *parent = nullptr, QString path = "/home/pi/boardconfig.ini");

    QList<bool> input();

    bool getInput(int addr); // Lay trang thai 1 dia chi
    void setOutput(int addr); //
    void getOutput(int addr);
private:
    //List gia tri dau vao thay doi boi thread chinh
    static QList<bool> m_input;
    //List gia tri dau ra thay doi boi 1 thread chinh
    static QList<bool> m_output;
    //Mutex de chay chi 1 thread
    static bool m_oneScan;
    //Path
    QString m_configPath;
    void run();

};

#endif // PIDIGITALBOARD_H
