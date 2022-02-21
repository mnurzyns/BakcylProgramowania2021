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

    void DemandIndicator();

};

}
