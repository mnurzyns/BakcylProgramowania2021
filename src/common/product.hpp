#pragma once
#include <string>

namespace bakcyl::common {
	class Product {
	private:
		std::uint64_t id;
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
		std::uint64_t getId() const;
		std::string getName() const;
		std::string getDescription() const;
		std::string getCategories() const;
		std::uint32_t getCurrentQuantity() const;
		std::uint32_t getMinQuantity() const;
		std::uint32_t getMaxQuantity() const;

		//Setters
		void setId(const std::uint64_t & value);
		void setName(const std::string & value);
		void setDescription(const std::string & value);
		void setCategories(const std::string & value);
		void setMinQuantity(const std::uint32_t & value);
		void setMaxQuantity(const std::uint32_t & value);
		void setCurrentQuantity(const std::uint32_t & value);

	};
}