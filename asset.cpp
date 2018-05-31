#include "asset.h"

Asset::Asset(std::string name, AssetType type) : SecObject(name)
{
    this->type = type;
}

ObjectType Asset::type()
{
    return asset;
}
