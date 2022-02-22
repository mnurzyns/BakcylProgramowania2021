#pragma once

namespace bakcyl::core {

class Core{
public:
    Core();

    struct Dataforemail {
	std::string email_address_recipient;
	std::string product_name;
	std::string message;
    };

    unsigned short DemandIndicator(int quality, std::time_t date);
    void GetDataforemailtoserver(struct Dataforemail* data);
    void SendDataforemailtoserver(struct Dataforemail* data);

};

}
