#include "sqlProxy.hpp"

#include <iostream>

namespace bakcyl::proxy
{
    std::vector<common::Product> Proxy<sql::Sql>::getAllProducts()
    {
        return convert::convertVector(db.getAllProducts());
    }

    common::Product Proxy<sql::Sql>::getProduct(const std::uint64_t &productId)
    {
        return convert::convert(db.getProduct(productId));
    }

    std::vector<common::Product> Proxy<sql::Sql>::getProductsBeginningWith(const std::string &sequence)
    {
        return convert::convertVector(db.getProductsBeginningWith(sequence));
    }

    std::vector<common::Product> Proxy<sql::Sql>::getProductsContaining(const std::string &sequence)
    {
        return convert::convertVector(db.getProductsContaining(sequence));
    }

    std::vector<common::Product> Proxy<sql::Sql>::getProductsEndingWith(const std::string &sequence)
    {
        return convert::convertVector(db.getProductsEndingWith(sequence));
    }

    void Proxy<sql::Sql>::insertProducts(const std::vector<common::Product> &products)
    {
        std::cerr << "Called";
        db.insertProducts(convert::convertVector(products));
    }

    void Proxy<sql::Sql>::updateProducts(const std::vector<common::Product> &newData)
    {
        db.updateProducts(convert::convertVector(newData));
    }

    std::vector<common::ProductInstance> Proxy<sql::Sql>::getAllInstances()
    {
        return convert::convertVector(db.getAllInstances());
    }

    void Proxy<sql::Sql>::insertInstance(const common::ProductInstance& instance)
    {
        db.insertInstance(convert::convert(instance));
    }

    void Proxy<sql::Sql>::updateInstance(const common::ProductInstance& newData)
    {
        db.updateInstance(convert::convert(newData));
    }
};
