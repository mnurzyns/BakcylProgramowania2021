#include "core/Core.hpp"

namespace bakcyl::core {

Core::Core()
{
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
}
