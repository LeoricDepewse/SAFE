#ifndef PROPERTY_H
#define PROPERTY_H
#include "secobject.h"
#define TBL_PROP "asset_props"

class Property : SecObject
{
public:
    Property(QString name, PropType type, PropValue value, int id = -1, bool isNew = false);

    ObjectType type() const;
    bool sync();

    PropType propType() const;
    PropValue value() const;
    QString rationale() const;

    void propType(PropType type);
    void value(PropValue value);
    void rationale(QString rationale);

private:
    PropType _propType;
    PropValue _value;
    QString _rationale;
};

#endif // PROPERTY_H
