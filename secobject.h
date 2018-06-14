#ifndef SECOBJECT_H
#define SECOBJECT_H
#include <string>
#include "propenums.h"

class SecObject
{
public:
    SecObject(std::string _name, int id, bool isNew);

    virtual ObjectType type() const;
    virtual bool sync();

    bool changed() const;
    int id() const;
    std::string name() const;
    bool isNew() const;

    void changed(bool changed);
    void id(int id);
    void name(std::string name);

protected:
    bool _changed;

private:
    int _id;
    std::string _name;
    bool _isNew;
};

#endif // SECOBJECT_H
