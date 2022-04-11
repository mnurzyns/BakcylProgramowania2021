#pragma once

#include <QObject>

class ProductDataHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(QString productId MEMBER m_productId)
    Q_PROPERTY(QString productName MEMBER m_productName)
    Q_PROPERTY(QString productCategory MEMBER m_productCategory)
    Q_PROPERTY(QString productQuantity MEMBER m_productQuantity)
    Q_PROPERTY(QString productLocation MEMBER m_productLocation)
    Q_PROPERTY(QString productDescription MEMBER m_productDescription)

public:
    explicit ProductDataHandler(QObject *parent = nullptr);
    Q_INVOKABLE void getProductData(int productId);

signals:
    void productDataChanged();

private:
    uint64_t realProductId;

    QString m_productId;
    QString m_productName;
    QString m_productCategory;
    QString m_productQuantity;
    QString m_productLocation;
    QString m_productDescription;
};
