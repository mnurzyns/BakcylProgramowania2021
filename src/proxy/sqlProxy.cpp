#include "sqlProxy.hpp"

namespace bakcyl::proxy
{
    Proxy<sql::Sql>::Proxy()
    : db(sql::Sql())
    {

    }

    Proxy<sql::Sql>::~Proxy()
    {

    }

    std::vector<common::Product> Proxy<sql::Sql>::getAllProducts()
    {
        return convert::convertVector(this->db.getAllProducts());
    }

    common::Product Proxy<sql::Sql>::getProduct(const std::uint64_t &productId)
    {
        return convert::convert(this->db.getProduct(productId));
    }

    std::vector<common::Product> Proxy<sql::Sql>::getProductsBeginningWith(const std::string &sequence)
    {
        return convert::convertVector(this->db.getProductsBeginningWith(sequence));
    }

    std::vector<common::Product> Proxy<sql::Sql>::getProductsContaining(const std::string &sequence)
    {
        return convert::convertVector(this->db.getProductsContaining(sequence));
    }

    std::vector<common::Product> Proxy<sql::Sql>::getProductsEndingWith(const std::string &sequence)
    {
        return convert::convertVector(this->db.getProductsEndingWith(sequence));
    }

    void Proxy<sql::Sql>::insertProducts(const std::vector<common::Product> &products)
    {
        this->db.insertProducts(convert::convertVector(products));
    }

    void Proxy<sql::Sql>::updateProducts(const std::vector<common::Product> &newData)
    {
        this->db.updateProducts(convert::convertVector(newData));
    }

    std::vector<common::ProductInstance> Proxy<sql::Sql>::getAllInstances()
    {
        return convert::convertVector(this->db.getAllInstances());
    }

    void Proxy<sql::Sql>::insertInstance(const common::ProductInstance& instance)
    {
        this->db.insertInstance(convert::convert(instance));
    }

    void Proxy<sql::Sql>::updateInstance(const common::ProductInstance& newData)
    {
        this->db.updateInstance(convert::convert(newData));
    }
};
