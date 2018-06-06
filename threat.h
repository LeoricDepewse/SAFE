#ifndef THREAT_H
#define THREAT_H
#include "secobject.h"
#include "asset.h"

class Threat : SecObject
{
public:
    Threat(std::string _name, Probability frequency, int id = -1, bool isNew = false);

    ObjectType type() const;

    Probability frequency() const;
    std::string method() const;
    std::vector<Asset*> concerns() const;
    std::vector<Property*> properties() const;

    void frequency(Probability frequency);
    void method(std::string method);
    void addConcern(Asset *concern);
    void removeConcern(Asset *concern);
    void addProperty(Property *prop);
    void removeProperty(Property *prop);

private:
    Probability _frequency;
    std::string _method = "";
    std::vector<Asset*> _concerns = std::vector<Asset*>();
    std::vector<Property*> _properties = std::vector<Property*>();
};

#endif // THREAT_H
