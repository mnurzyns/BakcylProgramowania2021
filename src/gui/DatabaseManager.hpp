#pragma once

#include <QObject>

#include "core/Core.hpp"
#include "common/product.hpp"
#include "common/productInstance.hpp"

class DatabaseManager : public QObject
{
    Q_OBJECT
public:
    explicit DatabaseManager(QObject *parent = nullptr);

    Q_INVOKABLE bool createNewProduct(int pId, QString pName, QString pCategories, QString pDescription);

    Q_INVOKABLE bool createNewProductInstance(int pId, int pInstId, QString pInstlocation, int pInstQuantity);

};
