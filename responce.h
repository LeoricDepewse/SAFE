#ifndef RESPONCE_H
#define RESPONCE_H
#include "secobject.h"

class Responce : SecObject
{
public:
    Responce(std::string name, ResponceType action);

    ObjectType type();

    ResponceType action;
    std::string description = "";
};

#endif // RESPONCE_H
