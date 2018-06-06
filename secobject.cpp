#include "secobject.h"

SecObject::SecObject(std::string name, int id, bool isNew)
{
    this->_name = name;
    _id = id;
    _changed = isNew;
    _isNew = isNew;
}

ObjectType SecObject::type() const
{
    return base;
}

bool SecObject::changed() const
{
    return _changed;
}

int SecObject::id() const
{
    return _id;
}

std::string SecObject::name() const
{
    return _name;
}

bool SecObject::isNew() const
{
    return _isNew;
}

void SecObject::changed(bool changed)
{
    _changed = changed;
}

void SecObject::name(std::string name)
{
    _name = name;
    _changed = true;
}
