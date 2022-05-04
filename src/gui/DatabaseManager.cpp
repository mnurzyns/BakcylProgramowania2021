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

    if(queryResult == bakcyl::core::Core::MethodResult::SUCCESS)
    {
        return true;
    }

    if(queryResult == bakcyl::core::Core::MethodResult::WRONG_PARAM)
    {
        m_failMessage = WRONG_PARAM_MESSAGE;
    }

    if(queryResult == bakcyl::core::Core::MethodResult::ERROR)
    {
        m_failMessage = ERROR_MESSAGE;
    }

    emit failMessageChanged();
    return false;
}
