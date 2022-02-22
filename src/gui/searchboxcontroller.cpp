#include "gui/searchboxcontroller.hpp"
#include <QDebug>

SearchboxController::SearchboxController(QObject *parent)
    : QObject{parent}
{

}

void SearchboxController::SeachButtonPressed()
{
    qDebug() << "Searchbox button called";
}
