#pragma once

#include <QObject>

#include <core/Core.hpp>
#include <common/product.hpp>

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);

    bool createNewProduct(int pId, QString pName, QString pCategories, QString pDescription);

signals:

};
