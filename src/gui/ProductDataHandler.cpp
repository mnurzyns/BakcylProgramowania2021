#include "ProductDataHandler.hpp"

ProductDataHandler::ProductDataHandler(QObject *parent)
    : QObject{parent}
{

}

void ProductDataHandler::getProductData(int productId)
{
    realProductId = productId;

    // TODO: Gather data from database through core

    m_productId = QString::number(realProductId);
    m_productName = QString("Ex name");
    m_productCategory = QString("Ex category");
    m_productQuantity = QString("Ex Quantity");
    m_productLocation = QString("Ex location");
    m_productDescription = QString("Description");

    emit productDataChanged();
}
