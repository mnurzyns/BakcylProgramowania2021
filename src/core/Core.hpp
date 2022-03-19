#pragma once
#include <string>

namespace bakcyl::core {

class Core{
public:
    Core();

    std::uint32_t currentQuantity;
    std::uint32_t minQuantity;
    std::uint32_t maxQuantity;

    std::uint32_t getProductCurrentQuantity(const std::uint64_t &id) const;
    std::uint32_t getProductMinQuantity(const std::uint64_t &id) const;
    std::uint32_t getProductMaxQuantity(const std::uint64_t &id) const;
    std::uint8_t changeProductQuantity(const std::uint64_t &id, const std::string &option, const std::uint32_t &quantity);

};

}
