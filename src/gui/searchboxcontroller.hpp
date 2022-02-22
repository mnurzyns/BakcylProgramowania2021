#pragma once

#include <QObject>

class SearchboxController : public QObject
{
    Q_OBJECT
public:
    explicit SearchboxController(QObject *parent = nullptr);

signals:
    void SearchboxCall();

};
