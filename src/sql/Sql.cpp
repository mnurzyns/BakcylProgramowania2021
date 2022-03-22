#include "sql/Sql.hpp"
#include <QtSql>

namespace bakcyl::sql {
    Sql::Sql() {
	
    };
    
    std::vector<Product> Sql::getAllProducts() const {
        std::vector<Product> products;

        {
            QSqlDatabase database = QSqlDatabase::addDatabase("");
            database.setHostName("");
            database.setDatabaseName("");
            database.setUserName("");
            database.setPassword("");

            bool opened = database.open();

            if (!opened) {
                //Error handling
            }

            QSqlQuery query;
            query.exec("SELECT * FROM Products");

            while (query.next()) {
                uint64_t id = query.value(0).toLongLong();
                std::string name = query.value(1).toString().toUtf8().constData();
                std::string description = query.value(2).toString().toUtf8().constData();
                std::string categories = query.value(3).toString().toUtf8().constData();
                uint32_t minQuantity = query.value(4).toInt();
                uint32_t maxQuantity = query.value(5).toInt();

                Product product(id, name, description, categories, minQuantity, maxQuantity);
                products.push_back(product);
            }

            query.clear();
            database.close();
        }

        QSqlDatabase::removeDatabase("");
        return products;
    }
};
