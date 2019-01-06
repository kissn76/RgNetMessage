#ifndef LISTENER_H
#define LISTENER_H

#include "socketthread.h"

#include <QQuickWindow>
#include <QTcpServer>

class Listener : public QTcpServer
{
    Q_OBJECT
public:
    Listener(QQuickWindow *listenerWindow = nullptr);
    ~Listener() override;
    void startServer();

signals:

public slots:

protected:
    void incomingConnection(qintptr socketDescriptor) override;

private:
    const unsigned short PORT = 9999;
    SocketThread *thread = nullptr;
    QQuickWindow *listenerWindow = nullptr;
};

#endif // LISTENER_H
