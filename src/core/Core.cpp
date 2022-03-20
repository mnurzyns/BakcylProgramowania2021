#include "core/Core.hpp"

namespace bakcyl::core {

Core::Core()
{

}

    std::uint8_t Core::calculateDemandIndicator(const std::uint16_t &quality, const std::time_t &date)
    {
        return 0;
    }

    void Core::getEmailDataToServer(const struct EmailData &data)
    {
        // data.email_address_recipient = ;
        // data.product_name = ;
        // data.message = "An order for the product <<product_name>> with the id <<product_id>> is needed."
    }

    Core::EmailData Core::sendEmailDataToServer(const struct EmailData &data)
    {
        return data;
    }

}
