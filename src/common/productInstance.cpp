#include "common/productInstance.hpp"

namespace bakcyl::common
{
	ProductInstance::ProductInstance(const std::uint32_t id, const std::string locationId, const std::uint64_t productId, const std::uint32_t quantity) 
	: id(id), locationId(locationId), productId(productId), quantity(quantity)
    {

    };

	std::uint32_t ProductInstance::getId() const
	{
		return id;
	}

	std::string ProductInstance::getLocationId() const
	{
		return locationId;
	}

	std::uint64_t ProductInstance::getProductId() const
	{
		return productId;
	}

	std::uint32_t ProductInstance::getQuantity() const
	{
		return quantity;
	}

	void ProductInstance::setId(const std::uint32_t & value)
	{
		id = value;
	}

	void ProductInstance::setLocationId(const std::string & value)
	{
		locationId = value;
	}

	void ProductInstance::setProductId(const std::uint64_t & value)
	{
		productId = value;
	}

	void ProductInstance::setQuantity(const std::uint32_t & value)
	{
		quantity = value;
	}

}
