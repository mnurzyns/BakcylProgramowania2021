#pragma once
#include <string>

namespace bakcyl::core {

class Core{
public:
    Core();

    enum class MethodResult
    {
        SUCCESS,
        ERROR,
        WRONG_PARAM
    };

    std::uint32_t currentQuantity;
    std::uint32_t minQuantity;
    std::uint32_t maxQuantity;

    std::uint32_t getProductCurrentQuantity() const;
    std::uint32_t getProductMinQuantity() const;
    std::uint32_t getProductMaxQuantity() const;
    MethodResult changeProductQuantity(const std::string &option, const std::uint32_t quantity);

};

}
