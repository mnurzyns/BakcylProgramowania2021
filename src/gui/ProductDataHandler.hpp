#pragma once

#include <QObject>

class ProductDataHandler : public QObject
{
    Q_OBJECT
    Q_PROPERTY(uint64_t productId MEMBER m_productId NOTIFY productDataChanged)
    Q_PROPERTY(QString productName MEMBER m_productName NOTIFY productDataChanged)
    Q_PROPERTY(QString productCategory MEMBER m_productCategory NOTIFY productDataChanged)
    Q_PROPERTY(uint32_t productQuantity MEMBER m_productQuantity NOTIFY productDataChanged)
    Q_PROPERTY(QString productLocation MEMBER m_productLocation NOTIFY productDataChanged)
    Q_PROPERTY(QString productDescription MEMBER m_productDescription NOTIFY productDataChanged)

public:
    explicit ProductDataHandler(QObject *parent = nullptr);
    Q_INVOKABLE void getProductData(u_int64_t productId);

signals:
    void productDataChanged();

private:
    uint64_t m_productId;
    QString m_productName;
    QString m_productCategory;
    uint32_t m_productQuantity;
    QString m_productLocation;
    QString m_productDescription;
};
