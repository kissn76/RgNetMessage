#ifndef SOCKETTHREAD_H
#define SOCKETTHREAD_H

#include <QTcpSocket>
#include <QThread>
#include <QQuickWindow>

class SocketThread : public QThread
{
    Q_OBJECT

public:
    SocketThread(qintptr socketDescriptor, QObject *parent, QQuickWindow *listenerWindow);

    void run() override;

signals:
    void error(QTcpSocket::SocketError socketError);
    void cppSignalSetMessage(QVariant username, QVariant message);

private:
    qintptr socketDescriptor;
    QTcpSocket *socket = nullptr;
};
#endif // SOCKETTHREAD_H
