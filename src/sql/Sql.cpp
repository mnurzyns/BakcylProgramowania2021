#include "sql/Sql.hpp"
#include <QtSql>

namespace bakcyl::sql 
{
    Sql::Sql() 
    {
        database = QSqlDatabase::addDatabase("");
        database.setHostName("");
        database.setDatabaseName("");
        database.setUserName("");
        database.setPassword("");

        if (!database.open()) 
        {
            //Error handling
        }
    };

    Sql::~Sql()
    {
        database.close();
        QSqlDatabase::removeDatabase("");
    }
    
    std::vector<Product> Sql::getAllProducts() const 
    {
        std::vector<Product> products;

        QSqlQuery query;
        query.exec("SELECT * FROM Products");

        while (query.next()) 
        {
            const uint64_t id = query.value(0).toLongLong();
            const std::string name = query.value(1).toString().toUtf8().constData();
            const std::string description = query.value(2).toString().toUtf8().constData();
            const std::string categories = query.value(3).toString().toUtf8().constData();
            const uint32_t minQuantity = query.value(4).toInt();
            const uint32_t maxQuantity = query.value(5).toInt();

            Product product(id, name, description, categories, minQuantity, maxQuantity);
            products.emplace_back(product);
        }

        query.clear();
        return products;
    }
};
