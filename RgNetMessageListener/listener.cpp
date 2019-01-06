#include "listener.h"
#include "socketthread.h"

Listener::Listener(QQuickWindow *listenerWindow) : listenerWindow(listenerWindow)
{
}

Listener::~Listener()
{
    delete thread;
    thread = nullptr;
}

void Listener::startServer()
{
    if (!this->listen(QHostAddress::Any, PORT)) {
        qDebug() << "Server could not start!" << endl;
    } else {
        qDebug() << "Server started! Listening on" << this->serverPort() << "tcp port..." << endl;
    }
}

void Listener::incomingConnection(qintptr socketDescriptor)
{
    thread = new SocketThread(socketDescriptor, this, this->listenerWindow);
    connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()));
    thread->start();
}
