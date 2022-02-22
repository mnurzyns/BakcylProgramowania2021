#include "product.hpp"

namespace bakcyl::common
{
	//Getters
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

	//Setters
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
}