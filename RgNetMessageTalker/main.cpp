#include "talker.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine talkerEngine;
    talkerEngine.load(QUrl(QStringLiteral("qrc:/talker.qml")));
    if (talkerEngine.rootObjects().isEmpty())
        return -1;

    Talker talker;

    QObject *talkerTopLevel = talkerEngine.rootObjects().value(0);
    QQuickWindow *talkerWindow = qobject_cast<QQuickWindow *>(talkerTopLevel);

    // connect QML signals to C++ slots
    QObject::connect(talkerWindow, SIGNAL(qmlSignalSubmitMessage(QString, QString)),
                     &talker, SLOT(cppSlotSubmitMessage(QString, QString)));

    return app.exec();
}
