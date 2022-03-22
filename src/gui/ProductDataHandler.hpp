#pragma once

#include <QObject>

class ProductDataHandler : public QObject
{
    Q_OBJECT

public:
    explicit ProductDataHandler(QObject *parent = nullptr);

};
