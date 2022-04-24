#pragma once
#include <string>

namespace bakcyl::common {
	class ProductInstance {
	private:

		std::uint32_t id{0};
		std::string locationId{0};
		std::uint64_t productId{0};
		std::uint32_t quantity{0};

	public:
		ProductInstance() = default;
		ProductInstance(const std::uint32_t id, const std::string locationId, const std::uint64_t productId, const std::uint32_t quantity);

		std::uint32_t getId() const;
		std::string getLocationId() const;
		std::uint64_t getProductId() const;
		std::uint32_t getQuantity() const;

		void setId(const std::uint32_t & value);
		void setLocationId(const std::string & value);
		void setProductId(const std::uint64_t & value);
		void setQuantity(const std::uint32_t & value);

	};
}
