#include "secobject.h"

SecObject::SecObject(std::string name)
{
    this->name = name;
    id = nextId++;
}

ObjectType SecObject::type()
{
    return base;
}
