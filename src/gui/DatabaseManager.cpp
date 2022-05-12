#include "DatabaseManager.hpp"

DatabaseManager::DatabaseManager(QObject *parent)
    : QObject{parent}
{

}

bool DatabaseManager::createNewProduct(int pId, QString pName, QString pCategories, QString pDescription)
{
    bakcyl::common::Product newProduct;

    newProduct.setId(static_cast<std::uint64_t>(pId));
    newProduct.setName(pName.toStdString());
    newProduct.setCategories(pCategories.toStdString());
    newProduct.setDescription(pDescription.toStdString());

    const auto queryResult = bakcyl::core::Core().createProduct(newProduct);

    // TODO: Tell the user what happened
    if(queryResult == bakcyl::core::Core::MethodResult::SUCCESS)
    {
        return true;
    }

    return false;
}

bool DatabaseManager::createNewProductInstance(int pId, int pInstId, QString pInstlocation, int pInstQuantity)
{
    bakcyl::common::ProductInstance newProductInstance;

    newProductInstance.setProductId(std::uint64_t(pId));
    newProductInstance.setId(std::uint32_t(pInstId));
    newProductInstance.setLocationId(pInstlocation.toStdString());
    newProductInstance.setQuantity(std::uint32_t(pInstQuantity));

    const auto queryResult = bakcyl::core::Core().createProductInstance(newProductInstance);

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
