#include "gui/searchboxcontroller.hpp"
#include <QDebug>

SearchboxController::SearchboxController(QObject *parent)
    : QObject{parent}
{

}

void SearchboxController::SearchboxCall()
{
    qDebug() << "Searchbox button called";
}
