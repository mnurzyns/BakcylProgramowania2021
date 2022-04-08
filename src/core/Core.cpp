#include "core/Core.hpp"

namespace bakcyl::core {

Core::Core()
{

}

    std::uint8_t Core::calculateDemandIndicator(const std::uint16_t quality, const std::time_t &date, const std::uint32_t &productID)
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

    std::uint32_t Core::getProductCurrentQuantity(const std::uint32_t &productID)
    {
        common::Product product;
        product = getProduct(productID);
        return product.getCurrentQuantity();
    }
    std::uint32_t Core::getProductMinQuantity(const std::uint32_t &productID)
    {
        common::Product product;
        product = getProduct(productID);
        return product.getMinQuantity();
    }
    std::uint32_t Core::getProductMaxQuantity(const std::uint32_t &productID)
    {
        common::Product product;
        product = getProduct(productID);
        return product.getMaxQuantity();
    }
    Core::MethodResult Core::changeProductQuantity(const std::string &option, const std::uint32_t quantity, const std::uint32_t &productID)
    {
        currentQuantity = getProductCurrentQuantity(productID);
        minQuantity = getProductMinQuantity(productID);
        maxQuantity = getProductMaxQuantity(productID);
        if(option == "increase")
        {
            if(currentQuantity+quantity > maxQuantity)
            {
                return MethodResult::ERROR;
            }
            else
            {
                common::Product product;
                product = getProduct(productID);
                product.setCurrentQuantity(currentQuantity+quantity);
                MethodResult value = updateProduct(productID,product);
                if(value == MethodResult::SUCCESS) return MethodResult::SUCCESS;
                else return MethodResult::ERROR;
            }
        }
        else if(option == "decrease")
        {
            if(currentQuantity-quantity < minQuantity)
            {
                return MethodResult::ERROR;
            }
            else
            {
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
                MethodResult value = updateProduct(productID,product);
                if(value == MethodResult::SUCCESS) return MethodResult::SUCCESS;
                else return MethodResult::ERROR;
            }
        }
        else
        {
            return MethodResult::WRONG_PARAM;
        }



    }

    Core::MethodResult Core::createProduct(common::Product &product)
    {
        MethodResult result;
        result = MethodResult::SUCCESS; //A call to a proxy
        return result;

    }
    common::Product Core::getProduct(const std::uint32_t &productID)
    {
        common::Product product;
        //A call to a proxy
        return product;
    }
    Core::MethodResult Core::updateProduct(const std::uint32_t &productID, common::Product &updatedProduct)
    {
        MethodResult result;
        result = MethodResult::SUCCESS; //A call to a proxy
        return result;
    }
    Core::MethodResult Core::deleteProduct(const std::uint32_t &productID)
    {
        MethodResult result;
        result = MethodResult::SUCCESS; //A call to a proxy
        return result;
    }
    Core::MethodResult Core::createProductInstance(common::ProductInstance &instance)
    {
        MethodResult result;
        result = MethodResult::SUCCESS; //A call to a proxy
        return result;
    }
    common::ProductInstance Core::getProductInstance(const std::string &locationID)
    {
        common::ProductInstance product;
        //A call to a proxy
        return product;
    }
    common::ProductInstance Core::getProductInstance(const std::uint32_t &instanceID)
    {
        common::ProductInstance product;
        //A call to a proxy
        return product;
    }
    Core::MethodResult Core::updateProductInstance(const std::uint32_t &instanceID, common::ProductInstance &updatedInstance)
    {
        MethodResult result;
        result = MethodResult::SUCCESS; //A call to a proxy
        return result;
    }
    Core::MethodResult Core::deleteProductInstance(const std::uint32_t &instanceID)
    {
        MethodResult result;
        result = MethodResult::SUCCESS; //A call to a proxy
        return result;
    }
    Core::MethodResult Core::createLocation(const std::string &locationID)
    {
        MethodResult result;
        result = MethodResult::SUCCESS; //A call to a proxy
        return result;
    }
    Core::MethodResult Core::updateLocation(const std::string &locationID, const std::string &updatedLocation)
    {
        MethodResult result;
        result = MethodResult::SUCCESS; //A call to a proxy
        return result;
    }
    Core::MethodResult Core::deleteLocation(const std::string &locationID)
    {
        MethodResult result;
        result = MethodResult::SUCCESS; //A call to a proxy
        return result;
    }

}
