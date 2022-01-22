#pragma once
#include <string>

namespace bakcyl::sql {
	class Product {
	private:
		unsigned long long productId;
		std::string name;
		std::string description;
		std::string categories;
		unsigned int minQuantity;
		unsigned int maxQuantity;
	public:
		Product();
		~Product();

		//Getters
		unsigned long long getProductId();
		std::string getName();
		std::string getDescription();
		std::string getCategories();
		unsigned int getMinQuantity();
		unsigned int getMaxQuantity();

		//Setters
		void setProductId(unsigned long long value);
		void setName(std::string value);
		void setDescription(std::string value);
		void setCategories(std::string value);
		void setMinQuantity(unsigned int value);
		void setMaxQuantity(unsigned int value);
	};
}