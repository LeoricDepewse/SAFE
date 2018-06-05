#include "responce.h"

Responce::Responce(std::string name, ResponceType action) : SecObject(name)
{
    this->action = action;
}

ObjectType Responce::type()
{
    return responce;
}
