#include "core/Core.hpp"

namespace bakcyl::core {

Core::Core()
{

}

    std::uint8_t Core::calculateDemandIndicator(const std::uint16_t quality, const std::time_t &date)
    {
        return 0;
    }

    void Core::getEmailDataToServer(EmailData &data)
    {
        // data.productName = ;
        data.message = "An order for the product " + data.productName + " is needed.";
    }

    Core::EmailData Core::sendEmailDataToServer(const EmailData &data)
    {
        return data;
    }

    std::uint32_t Core::getProductCurrentQuantity() const
    {
        return currentQuantity;
    }
    std::uint32_t Core::getProductMinQuantity() const
    {
        return minQuantity;
    }
    std::uint32_t Core::getProductMaxQuantity() const
    {
        return maxQuantity;
    }
    Core::MethodResult Core::changeProductQuantity(const std::string &option, const std::uint32_t quantity)
    {
        currentQuantity = getProductCurrentQuantity();
        minQuantity = getProductMinQuantity();
        maxQuantity = getProductMaxQuantity();
        if(option == "increase")
        {
            if(currentQuantity+quantity > maxQuantity)
            {
                return MethodResult::ERROR;
            }
            else
            {
                return MethodResult::SUCCESS;
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
                return MethodResult::SUCCESS;
            }
        }
        else
        {
            return MethodResult::WRONG_PARAM;
        }
    }

    Core::MethodResult Core::createProduct(common::Product &product)
    {
        //Method with a proxy
        return MethodResult::SUCCESS;

    }
    common::ProductInstance Core::getProduct(const std::uint32_t productID)
    {
        common::ProductInstance product;
        //Method with a proxy
        return product;
    }
    Core::MethodResult Core::updateProduct(const std::uint32_t productID, common::Product &updatedProduct)
    {
        //Method with a proxy
        return MethodResult::SUCCESS;
    }
    Core::MethodResult Core::deleteProduct(const std::uint32_t productID)
    {
        //Method with a proxy
        return MethodResult::SUCCESS;
    }
    Core::MethodResult Core::createProductInstance(common::ProductInstance &instance)
    {
        //Method with a proxy
        return MethodResult::SUCCESS;
    }
    common::ProductInstance Core::getProductInstance(const std::string &locationID)
    {
        common::ProductInstance product;
        //Method with a proxy
        return product;
    }
    common::ProductInstance Core::getProductInstance(const std::uint32_t instanceID)
    {
        common::ProductInstance product;
        //Method with a proxy
        return product;
    }
    Core::MethodResult Core::updateProductInstance(const std::uint32_t instanceID, common::ProductInstance &updatedInstance)
    {
        //Method with a proxy
        return MethodResult::SUCCESS;
    }
    Core::MethodResult Core::deleteProductInstance(const std::uint32_t instanceID)
    {
        //Method with a proxy
        return MethodResult::SUCCESS;
    }
    Core::MethodResult Core::createLocation(const std::string &locationID)
    {
        //Method with a proxy
        return MethodResult::SUCCESS;
    }
    Core::MethodResult Core::updateLocation(const std::string &locationID, const std::string &updatedLocation)
    {
        //Method with a proxy
        return MethodResult::SUCCESS;
    }
    Core::MethodResult Core::deleteLocation(const std::string &locationID)
    {
        //Method with a proxy
        return MethodResult::SUCCESS;
    }

}
