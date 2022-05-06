#include "core/Core.hpp"

namespace bakcyl::core {

Core::Core()
{

}

    std::uint8_t Core::calculateDemandIndicator(const std::uint16_t quality, const std::time_t &date, const std::uint32_t productID)
    {
        // The demand indicator returns in how many days the product will be out of stock
        float demandFactor;
        std::time_t nowTime;
        time(&nowTime);
        demandFactor = quality/(difftime(nowTime, date)/86400); //How much of the product will disappear in a day
        float result = getProductMinQuantity(productID)/demandFactor;
        std::uint8_t answer = result;
        return answer;
    }

    void Core::getEmailDataToServer(EmailData &data)
    {
        data.message = "An order for the product " + data.productName + " is needed. Product inventory will be exhausted less than 7 days.";
    }

    Core::EmailData Core::sendEmailDataToServer(const EmailData &data)
    {
        return data;
    }

    std::uint32_t Core::getProductCurrentQuantity(const std::uint32_t productID)
    {
        common::Product product;
        product = getProduct(productID);
        return product.getCurrentQuantity();
    }
    std::uint32_t Core::getProductMinQuantity(const std::uint32_t productID)
    {
        common::Product product;
        product = getProduct(productID);
        return product.getMinQuantity();
    }
    std::uint32_t Core::getProductMaxQuantity(const std::uint32_t productID)
    {
        common::Product product;
        product = getProduct(productID);
        return product.getMaxQuantity();
    }
    Core::MethodResult Core::changeProductQuantity(const std::string &option, const std::uint32_t quantity, const std::uint32_t productID)
    {

        if(option == "increase")
        {
            return handleIncreaseOperation(quantity, productID);
        }
        else if(option == "decrease")
        {
            if(currentQuantity-quantity < minQuantity)
            {
                return MethodResult::ERROR;
            }
            else
            {
                return handleDecreaseOperation(quantity, productID);
            }
        }
        else
        {
            return MethodResult::WRONG_PARAM;
        }
    }

    Core::MethodResult Core::handleIncreaseOperation(const std::uint32_t quantity, const std::uint32_t productID)
    {
        currentQuantity = getProductCurrentQuantity(productID);
        minQuantity = getProductMinQuantity(productID);
        maxQuantity = getProductMaxQuantity(productID);
        if(currentQuantity+quantity > maxQuantity)
            {
                return MethodResult::ERROR;
            }
            else
            {
                common::Product product;
                product = getProduct(productID);
                product.setCurrentQuantity(currentQuantity+quantity);
                MethodResult value = updateProduct(product);
                if(value == MethodResult::SUCCESS)
                {
                    return MethodResult::SUCCESS;
                }
                else
                {
                    return MethodResult::ERROR;
                }
            }
    }

    Core::MethodResult Core::handleDecreaseOperation(const std::uint32_t quantity, const std::uint32_t productID)
    {
        currentQuantity = getProductCurrentQuantity(productID);
        minQuantity = getProductMinQuantity(productID);
        maxQuantity = getProductMaxQuantity(productID);
        common::Product product;
        product = getProduct(productID);
        product.setCurrentQuantity(currentQuantity-quantity);
        if(calculateDemandIndicator(quantity,product.getLastBuy(),productID)<5 || currentQuantity-1 == minQuantity)
        {
            EmailData data;
            data.productName = product.getName();
            getEmailDataToServer(data);
        }
        std::time_t timer;
        time(&timer);
        product.setLastBuy(timer);
        MethodResult value = updateProduct(product);
        if(value == MethodResult::SUCCESS)
        {
            return MethodResult::SUCCESS;
        }
        else
        {
            return MethodResult::ERROR;
        }
    }

    std::uint8_t Core::getDemandIndicator(const std::uint32_t productID)
    {
        common::Product product;
        product = getProduct(productID);
        return calculateDemandIndicator(getProductCurrentQuantity(productID),product.getLastBuy(),productID);
    }

    Core::MethodResult Core::createProduct(common::Product &product)
    {
        proxy::Proxy<sql::Sql> proxy;
        MethodResult result;
        std::vector<common::Product> productVector;
        productVector.push_back(product);
        proxy.insertProducts(productVector);
        result = MethodResult::SUCCESS;
        return result;
    }

    common::Product Core::getProduct(const std::uint32_t productID)
    {
        common::Product product;
        proxy::Proxy<sql::Sql> proxy;
        proxy.getProduct(productID);
        return product;
    }
    Core::MethodResult Core::updateProduct(common::Product &updatedProduct)
    {
        MethodResult result;
        proxy::Proxy<sql::Sql> proxy;
        std::vector<common::Product> productVector;
        productVector.push_back(updatedProduct);
        proxy.updateProducts(productVector);
        result = MethodResult::SUCCESS;
        return result;
    }
    Core::MethodResult Core::deleteProduct(const std::uint32_t productID)
    {
        MethodResult result;
        proxy::Proxy<sql::Sql> proxy;
        result = MethodResult::SUCCESS; //A call to a proxy
        return result;
    }
    Core::MethodResult Core::createProductInstance(common::ProductInstance &instance)
    {
        MethodResult result;
        proxy::Proxy<sql::Sql> proxy;
        proxy.insertInstance(instance);
        result = MethodResult::SUCCESS;
        return result;
    }
    common::ProductInstance Core::getProductInstanceByLocationID(const std::string &locationID)
    {
        common::ProductInstance product;
        proxy::Proxy<sql::Sql> proxy;
        //A call to a proxy
        return product;
    }
    common::ProductInstance Core::getProductInstance(const std::uint32_t instanceID)
    {
        common::ProductInstance product;
        proxy::Proxy<sql::Sql> proxy;
        //A call to a proxy
        return product;
    }
    Core::MethodResult Core::updateProductInstance(common::ProductInstance &updatedInstance)
    {
        MethodResult result;
        proxy::Proxy<sql::Sql> proxy;
        proxy.updateInstance(updatedInstance);
        result = MethodResult::SUCCESS;
        return result;
    }
    Core::MethodResult Core::deleteProductInstance(const std::uint32_t instanceID)
    {
        MethodResult result;
        proxy::Proxy<sql::Sql> proxy;
        result = MethodResult::SUCCESS; //A call to a proxy
        return result;
    }
    Core::MethodResult Core::createLocation(const std::string &locationID)
    {
        MethodResult result;
        proxy::Proxy<sql::Sql> proxy;
        result = MethodResult::SUCCESS; //A call to a proxy
        return result;
    }
    Core::MethodResult Core::updateLocation(const std::string &locationID, const std::string &updatedLocation)
    {
        MethodResult result;
        proxy::Proxy<sql::Sql> proxy;
        result = MethodResult::SUCCESS; //A call to a proxy
        return result;
    }
    Core::MethodResult Core::deleteLocation(const std::string &locationID)
    {
        MethodResult result;
        proxy::Proxy<sql::Sql> proxy;
        result = MethodResult::SUCCESS; //A call to a proxy
        return result;
    }
    std::vector<std::string> Core::getLocations()
    {
        std::vector<std::string> result;
        proxy::Proxy<sql::Sql> proxy;
        //result = A call to a proxy
        return result;
    }
    std::vector<std::vector<common::Product>> Core::searchProducts(const auto &value, const std::string &searchType)
    {
        std::vector<std::vector<common::Product>> result;
        proxy::Proxy<sql::Sql> proxy;
        switch(searchType)
        {
        case "BeginningWith":
            result.push_back(proxy.getProductsBeginningWith(value));
            break;
        case "Containing":
            result.push_back(proxy.getProductsContaining(value));
            break;
        case "EndingWith":
            result.push_back(proxy.getProductsEndingWith(value));
            break;
        case "ByName":
            result.push_back(proxy.getProductsContaining(value));
            break;
        case "ById":
            result.push_back(getProduct(value));
            break;
        }
        return result;
    }

    std::vector<common::Product> getAllProducts()
    {
        proxy::Proxy<sql::Sql> proxy;
        return proxy.getAllProducts();
    }

    std::vector<common::ProductInstance> getAllProductsInstances()
    {
        proxy::Proxy<sql::Sql> proxy;
        return proxy.getAllInstances();
    }

    std::vector<common::ProductInstance> getProductInstancesByProductID(const std::uint32_t productID)
    {
        proxy::Proxy<sql::Sql> proxy;
        std::vector<common::ProductInstance> Instances = proxy.getAllInstances();
        std::vector<common::ProductInstance> Result;
        for(auto it = Instances.begin(); it != Instances.end(); it++)
        {
            common::ProductInstance item = *it;
            if(item.getId() == productID)
            {
                Result.push_back(*it);
            }
        }
        Instances.clear();
        return Result;
    }

}
