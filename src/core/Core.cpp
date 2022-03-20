#include "core/Core.hpp"

namespace bakcyl::core {

Core::Core()
{
}
    std::uint32_t Core::getProductCurrentQuantity(const std::uint64_t &id) const
    {
        return currentQuantity;
    }
    std::uint32_t Core::getProductMinQuantity(const std::uint64_t &id) const
    {
        return minQuantity;
    }
    std::uint32_t Core::getProductMaxQuantity(const std::uint64_t &id) const
    {
        return maxQuantity;
    }
    std::uint8_t Core::changeProductQuantity(const std::uint64_t &id, const std::string &option, const std::uint32_t &quantity)
    {
        currentQuantity = getProductCurrentQuantity(id);
        minQuantity = getProductMinQuantity(id);
        maxQuantity = getProductMaxQuantity(id);
        if(option == "increase")
        {
            if(currentQuantity+quantity > maxQuantity)
            {
                //If the condition above is true, it returns an error.
                return 1;
            }
            else
            {
                //Returns control to PROXY for updating the product status in the database and returns 0 if everything was successful.
                return 0;
            }
        }
        else if(option == "decrease")
        {
            if(currentQuantity-quantity < minQuantity)
            {
                //If the condition above is true, it returns an error.
                return 1;
            }
            else
            {
                //Returns control to PROXY for updating the product status in the database and returns 0 if everything was successful.
                return 0;
            }
        }
        else
        {
            //Returns 2 if the wrong "option" parameter was given.
            return 2;
        }
    }
}
