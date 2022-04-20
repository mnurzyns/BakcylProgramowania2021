#pragma once
#include <string>
#include <ctime>

namespace bakcyl::common {
	class Product {
	private:
		std::uint64_t id{0};
		std::string name{0};
		std::string description{0};
		std::string categories{0};
		std::uint32_t currentQuantity{0};
		std::uint32_t minQuantity{0};
		std::uint32_t maxQuantity{0};
		std::time_t lastBuy{0};

	public:
		Product() = default;
		Product(const std::uint64_t id, const std::string name, const std::string description, const std::string categories, const std::uint32_t currentQuantity, const std::uint32_t minQuantity, const std::uint32_t maxQuantity, const std::time_t lastBuy);

		std::uint64_t getId() const;
		std::string getName() const;
		std::string getDescription() const;
		std::string getCategories() const;
		std::uint32_t getCurrentQuantity() const;
		std::uint32_t getMinQuantity() const;
		std::uint32_t getMaxQuantity() const;
		std::time_t getLastBuy() const;

		void setId(const std::uint64_t & value);
		void setName(const std::string & value);
		void setDescription(const std::string & value);
		void setCategories(const std::string & value);
		void setMinQuantity(const std::uint32_t & value);
		void setMaxQuantity(const std::uint32_t & value);
		void setCurrentQuantity(const std::uint32_t & value);
		void setLastBuy(const std::time_t & value);

	};
}
