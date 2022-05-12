#pragma once

#include <QObject>

#include "core/Core.hpp"
#include "common/product.hpp"
#include "common/productInstance.hpp"

class DatabaseManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString failMessageForProduct MEMBER m_failMessageForProduct NOTIFY failMessageChanged)
    Q_PROPERTY(QString failMessageForProductInst MEMBER m_failMessageForProductInst NOTIFY failMessageChanged)

public:
    explicit DatabaseManager(QObject *parent = nullptr);

    Q_INVOKABLE bool createNewProduct(int pId, QString pName, QString pCategories, QString pDescription);
    Q_INVOKABLE bool createNewProductInstance(int pId, int pInstId, QString pInstlocation, int pInstQuantity);

signals:
    void failMessageChanged();

private:
    const QString WRONG_PARAM_MESSAGE = "Provided parameters are invalid";
    const QString ERROR_MESSAGE = "Error occured when processing query";

    QString m_failMessageForProduct;
    QString m_failMessageForProductInst;

};
