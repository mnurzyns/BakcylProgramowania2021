#pragma once
#include <vector>
#include <string>
#include "../common/product.hpp"
#include "../common/productInstance.hpp"
#include "baseProxy.hpp"
#include "converters.hpp"
#include "sql/Sql.hpp"

namespace bakcyl::proxy
{
    template <>
    class Proxy<sql::Sql> {
        private:
            sql::Sql db;

        public:
            Proxy();
            ~Proxy();

            std::vector<common::Product> getAllProducts();
            common::Product getProduct(const std::uint64_t& productId);
            std::vector<common::Product> getProductsBeginningWith(const std::string& sequence);
            std::vector<common::Product> getProductsContaining(const std::string& sequence);
            std::vector<common::Product> getProductsEndingWith(const std::string& sequence);
            void insertProducts(const std::vector<common::Product>& products);
            void updateProducts(const std::vector<common::Product>& newData);
            std::vector<common::ProductInstance> getAllInstances();
            void insertInstance(const common::ProductInstance& instance);
            void updateInstance(const common::ProductInstance& newData);

    };
};
