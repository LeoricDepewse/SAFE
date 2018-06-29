#ifndef PROPERTY_H
#define PROPERTY_H
#include "secobject.h"
static QString TBL_PROP_ASSET = "asset_props";
static QString TBL_PROP_THREAT = "threat_props";

class Property : SecObject
{
public:
    Property(QString name, PropType type, PropValue value, ObjectType table, int id = -1, bool isNew = false);

    ObjectType type() const;
    bool sync();

    PropType propType() const;
    PropValue value() const;
    QString rationale() const;
    ObjectType table() const;

    void propType(PropType type);
    void value(PropValue value);
    void rationale(QString rationale);

private:
    PropType _propType;
    PropValue _value;
    QString _rationale;
    ObjectType _table;
};

#endif // PROPERTY_H
