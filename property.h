#ifndef PROPERTY_H
#define PROPERTY_H
#include "secobject.h"

class Property : SecObject
{
public:
    Property(std::string name, PropType type, PropValue value, bool isNew = false);

    ObjectType type() const;

    PropType propType() const;
    PropValue value() const;
    std::string rationale() const;

    void propType(PropType type);
    void value(PropValue value);
    void rationale(std::string rationale);

private:
    PropType _propType;
    PropValue _value;
    std::string _rationale;
};

#endif // PROPERTY_H
