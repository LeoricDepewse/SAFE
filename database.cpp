#include "database.h"

using namespace Database;
bool connect()
{
    //connection reset
    if(connected)
        disconnect();

    db = QSqlDatabase::addDatabase("QMYSQL");
        db.setHostName(host);
        db.setDatabaseName(DBNAME);
        db.setUserName(user);
        db.setPassword(pass);

    connected = db.open();
    if(connected)
        return true;
    else throw db.lastError().text();
}

void disconnect()
{
    db.close();
    db.removeDatabase(db.connectionName());
    connected = false;
}

QSqlQuery* select(std::string table)
{
    if(!connected)
        return nullptr;

    QSqlQuery* query = new QSqlQuery(db);
    query->prepare("SELECT * FROM :table");
        query->bindValue(":table", QString::fromStdString(table));

    if(query->exec())
        return query;
    else throw query->lastError().text();
}

QSqlQuery *select(std::string table, std::string name)
{
    if(!connected)
        return nullptr;

    QSqlQuery* query = new QSqlQuery(db);
    query->prepare("SELECT * FROM :table WHERE name = :name");
        query->bindValue(":table", QString::fromStdString(table));
        query->bindValue(":name", QString::fromStdString(name));

    if(query->exec())
        return query;
    else throw query->lastError().text();
}
