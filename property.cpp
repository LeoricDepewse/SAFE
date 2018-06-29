#include "property.h"

Property::Property(QString name, PropType type, PropValue value, int id, bool isNew) : SecObject(name, id, isNew)
{
    _propType = type;
    _value = value;
}

ObjectType Property::type() const
{
    return property;
}

bool Property::sync()
{
    MySQLData data;
    data.insert(MySQLPair(OBJ_NAME, this->name()));
    data.insert(MySQLPair(OBJ_TYPE, this->type()));
    data.insert(MySQLPair(OBJ_VALUE, this->value()));
    data.insert(MySQLPair(OBJ_RATIONALE, this->rationale()));

    bool success = false;
    if(this->id() == -1)
    {
        success = Database::insert(TBL_PROP, data);
        id(Database::find(TBL_PROP, this->name()));
    }
    else success = Database::update(TBL_PROP, data, this->id());
    return success;
}

PropType Property::propType() const
{
    return _propType;
}

PropValue Property::value() const
{
    return _value;
}

QString Property::rationale() const
{
    return _rationale;
}

void Property::propType(PropType type)
{
    _propType = type;
    _changed = true;
}

void Property::value(PropValue value)
{
    _value = value;
    _changed = true;
}

void Property::rationale(QString rationale)
{
    _rationale = rationale;
    _changed = true;
}
