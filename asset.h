#ifndef ASSET_H
#define ASSET_H
#include "secobject.h"
#include "property.h"
#include <vector>

class Asset : SecObject
{
public:
    Asset(std::string name, AssetType type, int id = -1, bool isNew = false);

    ObjectType type() const;

    std::string description() const;
    AssetType classification() const;
    std::vector<Property*> properties() const;

    void description(std::string desc);
    void classification(AssetType type);
    void addProperty(Property *prop);
    void removeProperty(Property *prop);

private:
    std::string _description;
    AssetType _classification;
    std::vector<Property*> _properties = std::vector<Property*>();
};

#endif // ASSET_H
