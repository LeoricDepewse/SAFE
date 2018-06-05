#include "property.h"

Property::Property(std::string name, PropType type, PropValue value, bool isNew) : SecObject(name, isNew)
{
    _propType = type;
    _value = value;
}

ObjectType Property::type() const
{
    return property;
}

PropType Property::propType() const
{
    return _propType;
}

PropValue Property::value() const
{
    return _value;
}

std::string Property::rationale() const
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

void Property::rationale(std::string rationale)
{
    _rationale = rationale;
    _changed = true;
}
