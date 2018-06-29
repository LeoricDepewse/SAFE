#include "asset.h"

Asset::Asset(QString name, AssetType type, int id, bool isNew) : SecObject(name, id, isNew)
{
    _classification = type;
}

ObjectType Asset::type() const
{
    return asset;
}

bool Asset::sync()
{
    MySQLData data;
    data.emplace(OBJ_NAME, this->name());
    data.emplace(OBJ_DESC, this->description());
    data.emplace(OBJ_TYPE, QString::number(this->type()));

    bool success = false;
    if(this->id() == -1)
    {
        success = Database::insert(TBL_ASSET, data);
        id(Database::find(TBL_ASSET, this->name()));
    }
    else success = Database::update(TBL_ASSET, data, this->id());
    return success;
}

QString Asset::description() const
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

void Asset::description(QString desc)
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
