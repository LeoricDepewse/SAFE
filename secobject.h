#ifndef SECOBJECT_H
#define SECOBJECT_H
#include <string>
#include "propenums.h"
#include "database.h"
static QString OBJ_NAME = "name";
static QString OBJ_DESC = "description";
static QString OBJ_TYPE = "type";
static QString OBJ_VALUE= "value";
static QString OBJ_RATIONALE = "rationale";
static QString OBJ_ACTION = "action";
static QString OBJ_METHOD = "method";
static QString OBJ_SEVERITY = "severity";
static QString OBJ_FREQ = "frequency";
static QString OBJ_ASSET= "asset";
static QString OBJ_THREAT = "threat";
static QString OBJ_VULN = "vulnerability";
static QString OBJ_RISK = "risk";

class SecObject
{
public:
    SecObject(QString _name, int id, bool isNew);

    virtual ObjectType type() const;
    virtual bool sync();

    bool changed() const;
    int id() const;
    QString name() const;
    bool isNew() const;

    void changed(bool changed);
    void id(int id);
    void name(QString name);

protected:
    bool _changed;

private:
    int _id;
    QString _name;
    bool _isNew;
};

#endif // SECOBJECT_H
