#include "gui/searchboxcontroller.hpp"
#include <QDebug>

SearchboxController::SearchboxController(QObject *parent)
    : QObject{parent},
      m_searchboxText("")
{

}

QString SearchboxController::getSearchboxText()
{
    return m_searchboxText;
}

void SearchboxController::setSearchboxText(QString newValue)
{
    if(m_searchboxText != newValue)
    {
        m_searchboxText = newValue;
        emit searchboxTextChanged();
    }
}
