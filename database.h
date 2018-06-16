#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <map>
#include <string>

#define DBNAME "SAFE"
typedef std::map<std::string, std::string> MySQLData;

namespace Database
{
    static bool connect();
    static void disconnect();
    static QSqlQuery* select(std::string table);
    static QSqlQuery* select(std::string table, std::string name);
    static bool insert(std::string table, MySQLData data);
    static bool update(std::string table, MySQLData data);
    static bool erase(std::string table, std::string name);

    static bool connected;
    static QSqlDatabase db;
    static QString host = "localhost";
    static QString user = "root";
    static QString pass = "";
}
#endif // DATABASE_H
