#pragma once
#include <string>
#include <ctime>

namespace bakcyl::core {

class Core{
public:
    Core();

    struct EmailData {
            std::string emailAddressRecipient;
            std::string productName;
            std::string message;
    };

    std::uint8_t calculateDemandIndicator(const std::uint16_t &quality, std::time_t date);
    void getEmailDatatoserver(const EmailData &data);
    void sendEmailDatatoserver(const EmailData &data);

};

}
