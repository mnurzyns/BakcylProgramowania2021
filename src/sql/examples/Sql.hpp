#pragma once
#include <vector>

namespace bakcyl::sql {

class Sql {
public:
    Sql();
    //Products queries
    vector<Product> selectProducts(vector<string>& fieldsToSelect);
    vector<Product> selectAllProducts();
    void insertProduct(Product& product);
    void updateProduct(Product& newData);

    //Instances queries
    vector<ProductInstance> selectInstances(vector<string>& fieldsToSelect);
    vector<ProductInstance> selectAllInstances();
    void insertInstance(ProductInstance& instance);
    void updateInstance(ProductInstance& newData);
};

}
