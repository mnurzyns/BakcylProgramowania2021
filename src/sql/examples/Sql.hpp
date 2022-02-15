#pragma once
#include <vector>
#include <string>

namespace bakcyl::sql {

class Sql {
public:
    Sql();
    //Products queries
    std::vector<Product> selectAllProducts();
    Product selectProduct(std::uint64_t productId);
    std::vector<Product> selectProductsBeginningWith(std::string sequence);
    std::vector<Product> selectProductsContaining(std::string sequence);
    void insertProducts(std::vector<Product>& products);
    void updateProducts(std::vector<int> ids, std::vector<Product>& newData);

    //Instances queries
    std::vector<ProductInstance> selectAllInstances();
    void insertInstance(ProductInstance& instance);
    void updateInstance(ProductInstance& newData);
};

}
