#include "asset.h"

Asset::Asset(std::string name, AssetType type, bool isNew) : SecObject(name, isNew)
{
    _classification = type;
}

ObjectType Asset::type() const
{
    return asset;
}

std::string Asset::description() const
{
    return _description;
}

AssetType Asset::classification() const
{
    return _classification;
}

std::vector<Property*> Asset::properties() const
{
    return _properties;
}

void Asset::description(std::string desc)
{
    _description = desc;
    _changed = true;
}

void Asset::classification(AssetType type)
{
    _classification = type;
    _changed = true;
}

void Asset::addProperty(Property *prop)
{
    _properties.push_back(prop);
    _changed = true;
}

void Asset::removeProperty(Property *prop)
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
