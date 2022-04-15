#include "common/product.hpp"

namespace bakcyl::common
{
	Product::Product()
	: id(0), name(0), description(0), categories(0), currentQuantity(0),  minQuantity(0), maxQuantity(0), lastBuy(0)
	{

	}

	Product::Product(const std::uint64_t id, const std::string name, const std::string description, const std::string categories, const std::uint32_t currentQuantity, const std::uint32_t minQuantity, const std::uint32_t maxQuantity, const std::time_t lastBuy) 
	: id(id), name(name), description(description), categories(categories), currentQuantity(currentQuantity), minQuantity(minQuantity), maxQuantity(maxQuantity)
    {

    }

	std::uint64_t Product::getId() const
	{
		return id;
	}

	std::string Product::getName() const
	{
		return name;
	}

	std::string Product::getDescription() const
	{
		return description;
	}

	std::string Product::getCategories() const
	{
		return categories;
	}

	std::uint32_t Product::getCurrentQuantity() const
	{
		return currentQuantity;
	}

	std::uint32_t Product::getMinQuantity() const
	{
		return minQuantity;
	}

	std::uint32_t Product::getMaxQuantity() const
	{
		return maxQuantity;
	}

	std::time_t Product::getLastBuy() const
	{
		return lastBuy;
	}

	void Product::setId(const std::uint64_t & value)
	{
		id = value;
	}

	void Product::setName(const std::string & value)
	{
		name = value;
	}

	void Product::setDescription(const std::string & value)
	{
		description = value;
	}

	void Product::setCategories(const std::string & value)
	{
		categories = value;
	}

	void Product::setCurrentQuantity(const std::uint32_t & value)
	{
		currentQuantity = value;
	}

	void Product::setMinQuantity(const std::uint32_t & value)
	{
		minQuantity = value;
	}

	void Product::setMaxQuantity(const std::uint32_t & value)
	{
		maxQuantity = value;
	}

	void Product::setLastBuy(const std::time_t & value)
	{
		lastBuy = value;
	}
}
