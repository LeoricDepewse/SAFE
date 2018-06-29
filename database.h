#ifndef DATABASE_H
#define DATABASE_H
#include <QSqlDatabase>
#include <QSqlQuery>
#include <QSqlError>
#include <QVariant>
#include <map>
#include <string>

#define DBNAME "SAFE"
typedef std::pair<QString, QString> MySQLPair;
typedef std::map<QString, QString> MySQLData;

namespace Database
{
    static bool connect();
    static void disconnect();
    static QSqlQuery* select(QString table, int id = -1);
    static bool insert(QString table, MySQLData data);
    static bool update(QString table, MySQLData data, int id);
    static bool erase(QString table, int id);
    static int  find(QString table, QString name);

    static bool connected;
    static QSqlDatabase db;
    static QString host = "localhost";
    static QString user = "root";
    static QString pass = "";
}
#endif // DATABASE_H
