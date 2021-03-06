#include "converters.hpp"

namespace bakcyl::proxy::convert
{
    sql::ProductInstance convert(const common::ProductInstance& PI)
    {
        return sql::ProductInstance(PI.getId(), PI.getLocationId(), PI.getProductId(), PI.getQuantity());
    }

    common::ProductInstance convert(const sql::ProductInstance& PI)
    {
        return common::ProductInstance(PI.id, PI.locationId, PI.productId, PI.quantity);
    }

    common::Product convert(const sql::Product& P)
    {
        return common::Product(P.id, P.name, P.description, P.categories, 0, P.minQuantity, P.maxQuantity, std::time(nullptr));
    }

    sql::Product convert(const common::Product& P)
    {
        return sql::Product(P.getId(), P.getName(), P.getDescription(), P.getCategories(), P.getMinQuantity(), P.getMaxQuantity());
    }

    std::vector<sql::Product> convertVector(const std::vector<common::Product>& PV)
    {
        std::vector<sql::Product> vecOut;
        for(const auto& product : PV) {
            vecOut.push_back(convert(product));
        }
        return vecOut;
    }

    std::vector<common::Product> convertVector(const std::vector<sql::Product>& PV)
    {
        std::vector<common::Product> vecOut;
        for(const auto& product : PV) {
            vecOut.push_back(convert(product));
        }
        return vecOut;
    }

    std::vector<sql::ProductInstance> convertVector(const std::vector<common::ProductInstance>& PIV)
    {
        std::vector<sql::ProductInstance> vecOut;
        for(const auto& productInstance : PIV) {
            vecOut.push_back(convert(productInstance));
        }
        return vecOut;
    }

    std::vector<common::ProductInstance> convertVector(const std::vector<sql::ProductInstance>& PIV)
    {
        std::vector<common::ProductInstance> vecOut;
        for(const auto& productInstance : PIV) {
            vecOut.push_back(convert(productInstance));
        }
        return vecOut;
    }
}