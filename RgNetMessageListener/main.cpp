#include "listener.h"

#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QQuickWindow>

int main(int argc, char *argv[])
{
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);

    QGuiApplication app(argc, argv);

    QQmlApplicationEngine listenerEngine;
    listenerEngine.load(QUrl(QStringLiteral("qrc:/listener.qml")));
    if (listenerEngine.rootObjects().isEmpty())
        return -1;

    QObject *listenerTopLevel = listenerEngine.rootObjects().value(0);
    QQuickWindow *listenerWindow = qobject_cast<QQuickWindow *>(listenerTopLevel);

    Listener listener(listenerWindow);
    listener.startServer();

    return app.exec();
}
