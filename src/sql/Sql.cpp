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

        database = QSqlDatabase::addDatabase("QMYSQL");
        database.setHostName(document["host"].toString());
        database.setDatabaseName(document["database"].toString());
        database.setUserName(document["user"].toString());
        database.setPassword(document["password"].toString());

        if (!database.open()) 
        {
            throw std::runtime_error("Database connection failed!");
        }
    }

    Sql::~Sql()
    {
        database.close();
        QSqlDatabase::removeDatabase(connectionName);
    }

    QString Sql::loadCredentials() const
    {
        QFile file;
        file.setFileName("/etc/credentials.json");
        file.open(QIODevice::ReadOnly | QIODevice::Text);
        QString contents = file.readAll();
        file.close();

        return contents;
    }

    std::string Sql::getSelectSyntax(const std::string& sequence) const
    {
        return "SELECT * FROM Products WHERE Name LIKE " + sequence;
    }

    std::string Sql::getSelectSyntax(const std::uint64_t& productId) const
    {
        return "SELECT * FROM Products WHERE Id = " + std::to_string(productId);
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

            products.emplace_back(id, name, description, categories, minQuantity, maxQuantity);
        }

        query.clear();
        return products;
    }

    Product Sql::getProduct(const uint64_t& productId) const
    {
        QSqlQuery query;
        std::string syntax = getSelectSyntax(productId);
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

    std::vector<Product> Sql::getProductsBeginningWith(const std::string& sequence) const
    {
        std::vector<Product> products;
        
        QSqlQuery query;
        std::string syntax = getSelectSyntax(sequence + "%");
        query.exec(syntax.c_str());

        while (query.next()) 
        {
            const uint64_t id = query.value(0).toULongLong();
            const std::string name = query.value(1).toString().toUtf8().constData();
            const std::string description = query.value(2).toString().toUtf8().constData();
            const std::string categories = query.value(3).toString().toUtf8().constData();
            const uint32_t minQuantity = query.value(4).toInt();
            const uint32_t maxQuantity = query.value(5).toInt();

            products.emplace_back(id, name, description, categories, minQuantity, maxQuantity);
        }

        query.clear();
        return products;
    }

    std::vector<Product> Sql::getProductsContaining(const std::string& sequence) const
    {
        std::vector<Product> products;
        
        QSqlQuery query;
        std::string syntax = getSelectSyntax("%" + sequence + "%");
        query.exec(syntax.c_str());

        while (query.next()) 
        {
            const uint64_t id = query.value(0).toULongLong();
            const std::string name = query.value(1).toString().toUtf8().constData();
            const std::string description = query.value(2).toString().toUtf8().constData();
            const std::string categories = query.value(3).toString().toUtf8().constData();
            const uint32_t minQuantity = query.value(4).toInt();
            const uint32_t maxQuantity = query.value(5).toInt();

            products.emplace_back(id, name, description, categories, minQuantity, maxQuantity);
        }

        query.clear();
        return products;
    }

    std::vector<Product> Sql::getProductsEndingWith(const std::string& sequence) const
    {
        std::vector<Product> products;
        
        QSqlQuery query;
        std::string syntax = getSelectSyntax("%" + sequence);
        query.exec(syntax.c_str());

        while (query.next()) 
        {
            const uint64_t id = query.value(0).toULongLong();
            const std::string name = query.value(1).toString().toUtf8().constData();
            const std::string description = query.value(2).toString().toUtf8().constData();
            const std::string categories = query.value(3).toString().toUtf8().constData();
            const uint32_t minQuantity = query.value(4).toInt();
            const uint32_t maxQuantity = query.value(5).toInt();

            products.emplace_back(id, name, description, categories, minQuantity, maxQuantity);
        }

        query.clear();
        return products;
    }

    std::vector<ProductInstance> Sql::getAllInstances() const
    {
        std::vector<ProductInstance> instances;

        QSqlQuery query;
        query.exec("SELECT * FROM productsInstances");

        while (query.next()) 
        {
            const std::uint32_t id = query.value(0).toInt();
            const std::string locationId = query.value(1).toString().toUtf8().constData();
            const std::uint64_t productId = query.value(2).toULongLong();
            const std::uint32_t quantity = query.value(3).toInt();

            instances.emplace_back(id, locationId, productId, quantity);
        }

        query.clear();
        return instances;
    }

    ProductInstance Sql::getInstance(const std::uint32_t& id) const
    {
        QSqlQuery query;
        std::string syntax = "SELECT * FROM productsInstances WHERE id = " + std::to_string(id);
        query.exec(syntax.c_str());

        if (query.size() < 1)
        {
            throw std::runtime_error("ProductInstance doesn't exist!");
        }

        const std::string locationId = query.value(1).toString().toUtf8().constData();
        const std::uint64_t productId = query.value(2).toULongLong();
        const std::uint32_t quantity = query.value(3).toInt();

        ProductInstance instance(id, locationId, productId, quantity);

        query.clear();
        return instance;
    }

    ProductInstance Sql::getInstance(const std::uint64_t& productId) const
    {
        QSqlQuery query;
        std::string syntax = "SELECT * FROM productsInstances WHERE productId = " + std::to_string(productId);
        
        if (query.size() < 1)
        {
            throw std::runtime_error("ProductInstance doesn't exist!");
        }

        const std::uint32_t id = query.value(0).toInt();
        const std::string locationId = query.value(1).toString().toUtf8().constData();
        const std::uint32_t quantity = query.value(3).toInt();

        ProductInstance instance(id, locationId, productId, quantity);

        query.clear();
        return instance;
    }

    void Sql::insertInstance(const ProductInstance& instance)
    {
        QSqlQuery query;
        query.prepare("INSERT INTO productsInstances (id, locationId, productId, quantity) VALUES(:id, :locationId, :productId, :quantity)");
        
        qint32 id = instance.id;
        QString locationId = instance.locationId.c_str();
        qlonglong productId = instance.productId;
        qint32 quantity = instance.quantity;

        query.bindValue(":id", id);
        query.bindValue(":locationId", locationId);
        query.bindValue(":productId", productId);
        query.bindValue(":quantity", quantity);
        query.exec();
    }

    void Sql::updateInstance(const ProductInstance& newData)
    {
        QSqlQuery query;
        query.prepare("UPDATE productsInstances SET id = :id, locationId = :locationId, productId = :productId, quantity = :quantity");
        
        qint32 id = newData.id;
        QString locationId = newData.locationId.c_str();
        qlonglong productId = newData.productId;
        qint32 quantity = newData.quantity;

        query.bindValue(":id", id);
        query.bindValue(":locationId", locationId);
        query.bindValue(":productId", productId);
        query.bindValue(":quantity", quantity);             
        
        if (!query.exec())
        {
            throw std::runtime_error("Instance doesn't exist!");
        }
    }

    void Sql::insertProducts(const std::vector<Product>& products)
    {
        return;
    }

    void Sql::updateProducts(const std::vector<Product>& newData)
    {
        return;
    }
};
