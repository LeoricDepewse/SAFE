#ifndef THREAT_H
#define THREAT_H
#include "secobject.h"
#include "asset.h"

class Threat : SecObject
{
public:
    Threat(std::string name, Probability frequency);

    ObjectType type();

    Probability frequency;
    std::string method = "";
    std::vector<Asset*> concerns = std::vector<Asset*>();
    std::vector<Property> properties = std::vector<Property>();
};

#endif // THREAT_H
