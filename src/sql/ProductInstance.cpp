#include "sql/ProductInstance.hpp"

namespace bakcyl::sql {
    ProductInstance::ProductInstance(const std::uint32_t id, const std::string locationId, const std::uint64_t productId, const std::uint32_t quantity) : id(id), locationId(locationId), productId(productId), quantity(quantity)
    {

    };
};
