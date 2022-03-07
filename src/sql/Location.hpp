#pragma once
#include <string>

namespace bakcyl::sql
{
    class Location
    {
        public:
            const std::string id;
            const std::string categories;

            Location(const std::string id, const std::string categories);
    };
};