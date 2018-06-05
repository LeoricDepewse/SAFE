#include "secobject.h"

SecObject::SecObject(std::string name, bool isNew)
{
    this->_name = name;
    id = nextId++;
    _changed = isNew;
}

ObjectType SecObject::type() const
{
    return base;
}

bool SecObject::changed() const
{
    return _changed;
}

std::string SecObject::name() const
{
    return _name;
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
