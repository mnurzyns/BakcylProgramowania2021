#pragma once
#include <string>

namespace bakcyl::sql
{
    class Product
    {
        public:
            const std::uint64_t id;
            const std::string name;
            const std::string description;
            const std::string categories;
            const std::uint32_t minQuantity;
            const std::uint32_t maxQuantity;

            Product(const std::uint64_t id, const std::string name, const std::string description, const std::string categories, const std::uint32_t minQuantity, const std::uint32_t maxQuantity);
    };
};