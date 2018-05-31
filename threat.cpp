#include "threat.h"

Threat::Threat(std::string name, Probability frequency) : SecObject(name)
{
    this->frequency = frequency;
}

ObjectType Threat::type()
{
    return threat;
}
