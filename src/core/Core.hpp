#pragma once
#include <string>
#include <ctime>
#include <vector>
#include "common/product.hpp"
#include "common/productInstance.hpp"
#include "proxy/sqlProxy.hpp"

namespace bakcyl::core {

class Core{
public:
    Core();

    struct EmailData
    {
            std::string productName;
            std::string message;
    };

    std::uint8_t calculateDemandIndicator(const std::uint16_t quality, const std::time_t &date, const std::uint32_t productID);
    void getEmailDataToServer(EmailData &data);
    EmailData sendEmailDataToServer(const EmailData &data);

    enum class MethodResult
    {
        SUCCESS,
        ERROR,
        WRONG_PARAM
    };

    std::uint32_t currentQuantity;
    std::uint32_t minQuantity;
    std::uint32_t maxQuantity;

    std::uint32_t getProductCurrentQuantity(const std::uint32_t productID);
    std::uint32_t getProductMinQuantity(const std::uint32_t productID);
    std::uint32_t getProductMaxQuantity(const std::uint32_t productID);

    MethodResult changeProductQuantity(const std::string &option, const std::uint32_t quantity, const std::uint32_t productID);
    MethodResult handleIncreaseOperation(const std::uint32_t quantity, const std::uint32_t productID);
    MethodResult handleDecreaseOperation(const std::uint32_t quantity, const std::uint32_t productID);
    std::uint8_t getDemandIndicator(const std::uint32_t productID);

    MethodResult createProduct(common::Product &product);
    common::Product getProduct(const std::uint32_t productID);
    MethodResult updateProduct(const std::uint32_t productID, common::Product &updatedProduct);
    MethodResult deleteProduct(const std::uint32_t productID);

    MethodResult createProductInstance(common::ProductInstance &instance);
    common::ProductInstance getProductInstanceByLocationID(const std::string &locationID);
    common::ProductInstance getProductInstance(const std::uint32_t instanceID);
    MethodResult updateProductInstance(const std::uint32_t instanceID, common::ProductInstance &updatedInstance);
    MethodResult deleteProductInstance(const std::uint32_t instanceID);

    MethodResult createLocation(const std::string &locationID);
    MethodResult updateLocation(const std::string &locationID, const std::string &updatedLocation);
    MethodResult deleteLocation(const std::string &locationID);
    std::vector<std::string> getLocations();
    std::vector<common::Product> searchProducts(const auto &value, const std::string &searchType);

    std::vector<common::Product> getAllProducts();

};

}
