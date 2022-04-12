#include "ProductDataHandler.hpp"

ProductDataHandler::ProductDataHandler(QObject *parent)
    : QObject{parent}
{

}

void ProductDataHandler::getProductData(int productId)
{
    realProductId = productId;

    bakcyl::common::Product product = bakcyl::core::Core().getProduct(realProductId);

    m_productId = QString::number(realProductId);
    m_productName = QString("Ex name");
    m_productCategory = QString("Ex category");
    m_productQuantity = QString("Ex Quantity");
    m_productDescription = QString("Description");

    emit productDataChanged();
}
