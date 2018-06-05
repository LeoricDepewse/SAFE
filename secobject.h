#ifndef SECOBJECT_H
#define SECOBJECT_H
#include <string>
#include "propenums.h"

class SecObject
{
public:
    SecObject(std::string _name, bool isNew);

    virtual ObjectType type() const;

    bool changed() const;
    std::string name() const;

    void changed(bool changed);
    void name(std::string name);

protected:
    bool _changed;

private:
    std::string _name;
};

#endif // SECOBJECT_H
