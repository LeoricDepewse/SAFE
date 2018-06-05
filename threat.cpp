#include "threat.h"

Threat::Threat(std::string name, Probability frequency, bool isNew) : SecObject(name, isNew)
{
    _frequency = frequency;
}

ObjectType Threat::type() const
{
    return threat;
}

Probability Threat::frequency() const
{
    return _frequency;
}

std::string Threat::method() const
{
    return _method;
}

std::vector<Asset*> Threat::concerns() const
{
    return _concerns;
}

std::vector<Property*> Threat::properties() const
{
    return _properties;
}

void Threat::frequency(Probability frequency)
{
    _frequency = frequency;
    _changed = true;
}

void Threat::method(std::string method)
{
    _method = method;
    _changed = true;
}

void Threat::addConcern(Asset *concern)
{
    _concerns.push_back(concern);
}

void Threat::removeConcern(Asset *concern)
{
    for(auto it = _properties.begin(); it != _properties.end(); ++it)
    {
        if((*it) == concern)
        {
            _properties.erase(it);
            break;
        }
    }
    _changed = true;
}

void Threat::addProperty(Property *prop)
{
    _properties.push_back(prop);
}

void Threat::removeProperty(Property *prop)
{
    for(auto it = _properties.begin(); it != _properties.end(); ++it)
    {
        if((*it) == prop)
        {
            _properties.erase(it);
            break;
        }
    }
    _changed = true;
}
