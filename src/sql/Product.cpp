#include "sql/Product.hpp"

namespace bakcyl::sql {
    Product::Product(const std::uint64_t id, const std::string name, const std::string description, const std::string categories, const std::uint32_t minQuantity, const std::uint32_t maxQuantity) : id(id), name(name), description(description), categories(categories), minQuantity(minQuantity), maxQuantity(maxQuantity)
    {

    };
};
