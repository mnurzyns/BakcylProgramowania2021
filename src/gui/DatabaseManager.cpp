#include "DatabaseManager.hpp"

DatabaseManager::DatabaseManager(QObject *parent)
    : QObject{parent}
{

}

bool DatabaseManager::createNewProduct(int pId, QString pName, QString pCategories, QString pDescription)
{
    bakcyl::common::Product newProduct;

    newProduct.setId(pId);
    newProduct.setName(pName.toStdString());
    newProduct.setCategories(pCategories.toStdString());
    newProduct.setDescription(pDescription.toStdString());

    bakcyl::core::Core::MethodResult queryResult = bakcyl::core::Core().createProduct(newProduct);
}
