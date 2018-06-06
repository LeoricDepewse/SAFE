#ifndef RESPONCE_H
#define RESPONCE_H
#include "secobject.h"

class Responce : SecObject
{
public:
    Responce(std::string name, ResponceType action, int id = -1, bool isNew = false);

    ObjectType type() const;

    ResponceType action() const;
    std::string description() const;

    void action(ResponceType action);
    void description(std::string desc);

private:
    ResponceType _action;
    std::string _description = "";
};

#endif // RESPONCE_H
