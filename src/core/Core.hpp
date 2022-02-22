#pragma once
#include <string>

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

    unsigned short DemandIndicator(int quality, std::time_t date);
    void GetDataforemailtoserver(struct Dataforemail* data);
    void SendDataforemailtoserver(struct Dataforemail* data);

};

}
