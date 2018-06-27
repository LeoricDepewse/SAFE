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

QSqlQuery *select(QString table, QString name)
{
    if(!connected)
        return nullptr;

    QString statement = "SELECT * FROM :table";
    if(!name.isEmpty())
        statement += " WHERE name = :name";

    QSqlQuery* query = new QSqlQuery(db);
    query->prepare(statement);
        query->bindValue(":table", table);
        query->bindValue(":name", name);

    if(query->exec())
        return query;
    else throw query->lastError().text();
}

bool insert(QString table, MySQLData data)
{
    if(!connected)
        return false;

    QSqlQuery* query = new QSqlQuery(db);

    QString statement = "INSERT INTO :table (";
    QString values = ") VALUES (";
    for(auto it = data.begin(); it != data.end(); ++it)
    {
        statement += it->first + ", ";
        values += ":" + it->first + ", ";
    }
    statement.chop(2);
    values.chop(2);
    statement += values + ")";

    query->prepare(statement);
        query->bindValue(":table", table);
        for(auto it = data.begin(); it != data.end(); ++it)
            query->bindValue(":" + it->first, it->second);

    bool success = query->exec();
    delete query;
    return success;
}

bool update(QString table, MySQLData data, int id)
{
    if(!connected)
        return false;

    QSqlQuery* query = new QSqlQuery(db);

    QString statement = "UPDATE :table SET ";
    for(auto it = data.begin(); it != data.end(); ++it)
        statement += it->first + " = :" + it->first + ", ";
    statement.chop(2);
    statement += " WHERE id = :id";

    query->prepare(statement);
        query->bindValue(":table", table);
        query->bindValue(":id", id);
        for(auto it = data.begin(); it != data.end(); ++it)
            query->bindValue(":"+it->first, it->second);

    bool success = query->exec();
    delete query;
    return success;
}

bool erase(QString table, int id)
{
    if(!connected)
        return false;

    QSqlQuery* query = new QSqlQuery(db);

    QString statement = "DELETE FROM :table WHERE id = :id";

    query->prepare(statement);
        query->bindValue(":table", table);
        query->bindValue(":id", id);

    bool success = query->exec();
    delete query;
    return success;
}
