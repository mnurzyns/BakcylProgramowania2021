#pragma once

#include <QObject>

#include <core/Core.hpp>
#include <common/product.hpp>

class DatabaseManager : public QObject
{
    Q_OBJECT

    Q_PROPERTY(QString failMessage MEMBER m_failMessage NOTIFY failMessageChanged)

public:
    explicit DatabaseManager(QObject *parent = nullptr);

    Q_INVOKABLE bool createNewProduct(int pId, QString pName, QString pCategories, QString pDescription);

signals:
    void failMessageChanged();

private:
    const QString WRONG_PARAM_MESSAGE = "Provided parameters are invalid";
    const QString ERROR_MESSAGE = "Error occured when processing query";

    QString m_failMessage;

};
