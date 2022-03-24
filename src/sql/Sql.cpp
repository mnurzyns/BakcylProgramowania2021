#include "sql/Sql.hpp"
#include <QtSql>
#include <stdexcept>

namespace bakcyl::sql 
{
    Sql::Sql(const std::string host, const std::string name, const std::string user, const std::string password) 
    {
        connectionName = QString(name.c_str());
        database = QSqlDatabase::addDatabase(QString(name.c_str()));
        database.setHostName(QString(host.c_str()));
        database.setDatabaseName(QString(name.c_str()));
        database.setUserName(QString(user.c_str()));
        database.setPassword(QString(password.c_str()));

        if (!database.open()) 
        {
            throw std::runtime_error("Database connection failed!");
        }
    };

    Sql::~Sql()
    {
        database.close();
        QSqlDatabase::removeDatabase(connectionName);
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
