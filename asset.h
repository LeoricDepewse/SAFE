#ifndef ASSET_H
#define ASSET_H
#include "secobject.h"
#include "property.h"
#include <vector>

class Asset : SecObject
{
public:
    Asset(std::string name, AssetType type);

    ObjectType type();

    std::string Description;
    AssetType classification;
    std::vector<Property> properties = std::vector<Property>();
};

#endif // ASSET_H
