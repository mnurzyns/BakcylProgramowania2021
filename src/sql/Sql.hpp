#pragma once
#include <vector>
#include <string>
#include "sql/Product.hpp"
#include "sql/ProductInstance.hpp"
 
namespace bakcyl::sql 
{
    class Sql {
        public:
            Sql();  

            std::vector<Product> getAllProducts() const;
            Product getProduct(const std::uint64_t& productId) const;
            std::vector<Product> getProductsBeginningWith(const std::string& sequence) const;
            std::vector<Product> getProductsContaining(const std::string& sequence) const;
            std::vector<Product> getProductsEndingWith(const std::string& sequence) const;
            void insertProducts(const std::vector<Product>& products);
            void updateProducts(const std::vector<Product>& newData);

            std::vector<ProductInstance> getAllInstances() const;
            void insertInstance(const ProductInstance& instance);
            void updateInstance(const ProductInstance& newData);
    };
};
