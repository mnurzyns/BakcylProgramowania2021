#pragma once
#include <string>

namespace bakcyl::common {
	class ProductInstance {
	private:

        std::uint32_t id;
        std::string locationId;
        std::uint64_t productId;
        std::uint32_t quantity;

	public:
		ProductInstance();
		~ProductInstance();

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
