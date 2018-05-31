#ifndef SECOBJECT_H
#define SECOBJECT_H
#include <string>
#include "propenums.h"

class SecObject
{
public:
    SecObject(std::string name);

    virtual ObjectType type();

    std::string name;
};

#endif // SECOBJECT_H
