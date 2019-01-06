#include "socketthread.h"

SocketThread::SocketThread(qintptr socketDescriptor, QObject *parent, QQuickWindow *listenerWindow) : QThread(parent), socketDescriptor(socketDescriptor)
{
    // connect C++ signals to QML slots
    QObject::connect(this, SIGNAL(cppSignalSetMessage(QVariant, QVariant)),
                     listenerWindow, SLOT(qmlSlotSetMessage(QVariant, QVariant)));
}

void SocketThread::run()
{
    socket = new QTcpSocket();

    if (!socket->setSocketDescriptor(socketDescriptor)) {
        emit error(socket->error());
        return;
    }

    socket->waitForReadyRead(3000);
    QString username = socket->readLine().replace("\n", "");
    socket->waitForReadyRead(3000);
    QString message = socket->readLine();

    socket->disconnectFromHost();
    socket->waitForDisconnected();
    socket->close();

    delete socket;
    socket = nullptr;

    emit cppSignalSetMessage(username, message);
    //qDebug() << username << message;
}
