#include "sql/Sql.hpp"
#include <QString>
#include <QtSql>

namespace bakcyl::sql {
    Sql::Sql(const std::string hostName, const std::string databaseName, const std::string userName, const std::string password)
    {
        db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName(QString::fromStdString(hostName));
        db.setDatabaseName(QString::fromStdString(databaseName));
        db.setUserName(QString::fromStdString(userName));
        db.setPassword(QString::fromStdString(password));
        db.open();
    };
};
