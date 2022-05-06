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
    m_productName = QString::fromStdString(product.getName());
    m_productCategory = QString::fromStdString(product.getCategories());
    m_productQuantity = QString::number(product.getCurrentQuantity());
    m_productDescription = QString::fromStdString(product.getDescription());

    emit productDataChanged();
}
