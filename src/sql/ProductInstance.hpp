#pragma once
#include <string>

namespace bakcyl::sql
{
    class ProductInstance
    {
        public:
            const std::uint32_t id;
            const std::string locationId;
            const std::uint64_t productId;
            const std::uint32_t quantity;

            ProductInstance(const std::uint32_t id, const std::string locationId, const std::uint64_t productId, const std::uint32_t quantity);
    };
};