#include "responce.h"

Responce::Responce(std::string name, ResponceType action, bool isNew) : SecObject(name, isNew)
{
    this->action = action;
}

ObjectType Responce::type() const
{
    return responce;
}

ResponceType Responce::action() const
{
    return _action;
}

std::__cxx11::string Responce::description() const
{
    return _description;
}

void Responce::action(ResponceType action)
{
    _action = action;
    _changed = true;
}

void Responce::description(std::__cxx11::string desc)
{
    _description = desc;
    _changed = true;
}
