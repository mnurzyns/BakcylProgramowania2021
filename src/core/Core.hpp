#pragma once
#include <string>
#include <ctime>

namespace bakcyl::core {

class Core{
public:
    Core();

    struct Dataforemail {
            std::string email_address_recipient;
            std::string product_name;
            std::string message;
            short demand_indicator;
    };

    unsigned short DemandIndicator(const int quality, std::time_t date);
    void GetDataforemailtoserver(const struct Dataforemail &data);
    void SendDataforemailtoserver(const struct Dataforemail &data);

};

}
