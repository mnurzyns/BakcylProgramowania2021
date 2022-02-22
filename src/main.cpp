#include <QGuiApplication>
#include <QQmlApplicationEngine>
#include <QtQuickControls2/QtQuickControls2>
#include <QQmlContext>

#include "gui/searchboxcontroller.hpp"

int main(int argc, char *argv[])
{
#if QT_VERSION < QT_VERSION_CHECK(6, 0, 0)
    QCoreApplication::setAttribute(Qt::AA_EnableHighDpiScaling);
#endif

    QGuiApplication app(argc, argv);
    QQmlApplicationEngine engine;

    engine.load(QUrl(QString("qrc:/main.qml")));

    SearchboxController searchboxController;

    QQmlContext* rootContext = engine.rootContext();
    rootContext->setContextProperty("searchController", &searchboxController);

    return app.exec();
}

