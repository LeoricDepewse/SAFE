#include "secobject.h"

SecObject::SecObject(QString name, int id, bool isNew)
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

bool SecObject::sync()
{
    return false;
}

bool SecObject::changed() const
{
    return _changed;
}

int SecObject::id() const
{
    return _id;
}

QString SecObject::name() const
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

void SecObject::id(int id)
{
    if(_isNew)
    {
        _id = id;
        _isNew = false;
    }
}

void SecObject::name(QString name)
{
    _name = name;
    _changed = true;
}
