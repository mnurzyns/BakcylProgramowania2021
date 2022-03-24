#include "sql/Sql.hpp"
#include <QtSql>
#include <QJsonDocument>
#include <QFile>
#include <QIODevice>
#include <stdexcept>
#include <string>

namespace bakcyl::sql 
{
    Sql::Sql() 
    {
        QString contents = loadCredentials();
        QJsonDocument document = QJsonDocument::fromJson(contents.toUtf8());
        
        connectionName = document["database"].toString();
        database = QSqlDatabase::addDatabase(document["database"].toString());
        database.setHostName(document["host"].toString());
        database.setDatabaseName(document["database"].toString());
        database.setUserName(document["user"].toString());
        database.setPassword(document["password"].toString());

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

    QString Sql::loadCredentials()
    {
        QFile file;
        file.setFileName("credentials.json");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QString contents = file.readAll();
        file.close();

        return contents;
    }
    
    std::vector<Product> Sql::getAllProducts() const 
    {
        std::vector<Product> products;

        QSqlQuery query;
        query.exec("SELECT * FROM Products");

        while (query.next()) 
        {
            const uint64_t id = query.value(0).toULongLong();
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

    Product Sql::getProduct(const uint64_t& productId) const
    {
        QSqlQuery query;
        std::string syntax = "SELECT * FROM Products WHERE Id=" + std::to_string(productId);
        query.exec(syntax.c_str());

        if (query.size() < 1)
        {
            throw std::runtime_error("Product doesn't exist!");
        }

        const uint64_t id = query.value(0).toULongLong();
        const std::string name = query.value(1).toString().toUtf8().constData();
        const std::string description = query.value(2).toString().toUtf8().constData();
        const std::string categories = query.value(3).toString().toUtf8().constData();
        const uint32_t minQuantity = query.value(4).toInt();
        const uint32_t maxQuantity = query.value(5).toInt();

        Product product(id, name, description, categories, minQuantity, maxQuantity);

        query.clear();
        return product;
    }
};
