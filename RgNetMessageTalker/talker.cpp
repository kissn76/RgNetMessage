#include "talker.h"

Talker::Talker(QObject *parent) : QObject(parent)
{
}

Talker::~Talker()
{
    delete socket;
    socket = nullptr;
}

void Talker::cppSlotSubmitMessage(QString username, QString message) {
    socket = new QTcpSocket();
    socket->connectToHost(ADDRESS, PORT);

    if (socket->waitForConnected(5000)) {
        socket->write((username + "\n").toUtf8());
        socket->flush();
        socket->waitForBytesWritten(3000);
        socket->write(message.toUtf8());
        socket->flush();
        socket->waitForBytesWritten(3000);

        socket->close();

        delete socket;
        socket = nullptr;
    } else {
        qDebug() << "Not connected!";
    }
}
