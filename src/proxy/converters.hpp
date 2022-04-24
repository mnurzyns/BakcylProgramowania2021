#pragma once
#include "sql/Sql.hpp"
#include "../common/product.hpp"
#include "../common/productInstance.hpp"

namespace bakcyl::proxy::convert
{
    sql::ProductInstance convert(const common::ProductInstance& PI);
    common::ProductInstance convert(const sql::ProductInstance& PI);
    sql::Product convert(const common::Product& P);
    common::Product convert(const sql::Product& P);
    std::vector<sql::Product> convertVector(const std::vector<common::Product>& PV);
    std::vector<common::Product> convertVector(const std::vector<sql::Product>& PV);
    std::vector<sql::ProductInstance> convertVector(const std::vector<common::ProductInstance>& PIV);
    std::vector<common::ProductInstance> convertVector(const std::vector<sql::ProductInstance>& PIV);
}