#pragma once
#include <string>

namespace bakcyl::sql {
	class Product {
	private:
		std::uint64_t productId;
		std::string name;
		std::string description;
		std::string categories;
		std::uint32_t currentQuantity;
		std::uint32_t minQuantity;
		std::uint32_t maxQuantity;
	public:
		Product();
		~Product();

		//Getters
		std::uint64_t getProductId();
		std::string getName();
		std::string getDescription();
		std::string getCategories();
		std::uint32_t getCurrentQuantity();
		std::uint32_t getMinQuantity();
		std::uint32_t getMaxQuantity();

		//Setters
		void setProductId(std::uint64_t value);
		void setName(std::string value);
		void setDescription(std::string value);
		void setCategories(std::string value);
		void setMinQuantity(std::uint32_t value);
		void setMaxQuantity(std::uint32_t value);
	};
}