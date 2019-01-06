#ifndef TALKER_H
#define TALKER_H

#include <QObject>
#include <QTcpSocket>

class Talker : public QObject
{
    Q_OBJECT

public:
    explicit Talker(QObject *parent = nullptr);
    ~Talker();

signals:

public slots:
    void cppSlotSubmitMessage(QString, QString);

private:
    const unsigned short PORT = 9999;
    const QString ADDRESS = "localhost";
    QTcpSocket *socket = nullptr;
};

#endif // TALKER_H
