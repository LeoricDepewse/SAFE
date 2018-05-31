#ifndef PROPERTY_H
#define PROPERTY_H
#include "propenums.h"

typedef struct Property
{
    PropType type;
    PropValue value;
    std::string rationale;
} Property;

#endif // PROPERTY_H
