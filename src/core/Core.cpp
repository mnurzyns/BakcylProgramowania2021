#include "core/Core.hpp"

namespace bakcyl::core {

Core::Core()
{

}

    std::uint8_t Core::calculateDemandIndicator(const std::uint16_t &quality, const std::time_t &date)
    {
        return 0;
    }

    void Core::getEmailDataToServer(EmailData &data)
    {
        // data.productName = ;
        data.message = "An order for the product " + data.productName + " is needed.";
    }

    Core::EmailData Core::sendEmailDataToServer(const EmailData &data)
    {
        return data;
    }

}
