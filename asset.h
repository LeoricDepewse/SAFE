#ifndef ASSET_H
#define ASSET_H
#include "secobject.h"
#include "property.h"
#include <vector>
#define TBL_ASSET "assets"

class Asset : SecObject
{
public:
    Asset(QString name, AssetType type, int id = -1, bool isNew = false);

    ObjectType type() const;
    bool sync();
    bool syncProps();

    QString description() const;
    AssetType classification() const;
    std::vector<Property*> properties() const;

    void description(QString desc);
    void classification(AssetType type);
    void addProperty(Property *prop);
    void removeProperty(Property *prop);

private:
    QString _description;
    AssetType _classification;
    std::vector<Property*> _properties = std::vector<Property*>();
};

#endif // ASSET_H
