#ifndef PROPENUMS_H
#define PROPENUMS_H
#include <QString>

enum ObjectType
{
    base,
    asset,
    vulnerability,
    threat,
    risk,
    responce,
    property
};

enum PropType
{
    noPropType      = 0,
    confidentiality = 1,
    integrity       = 2,
    availability    = 3,
    accountability  = 4,
    anonymity       = 5,
    pseudonymity    = 6,
    unobservability = 7,
    unlinkability   = 8
};
static const QString PROPTYPES[] =
{
    "None"
    "Confidentiality",
    "Integrity",
    "Availability",
    "Accountability",
    "Anonymity",
    "Pseudonymity",
    "Unobservability",
    "Unlinkability"
};

enum PropValue
{
    none   = 0,
    low    = 1,
    medium = 2,
    high   = 3
};
static const QString PROPVALUES[] =
{
    "None",
    "Low",
    "Medium",
    "High"
};

enum AssetType
{
    noAssetType = 0,
    information = 1,
    systems     = 2,
    software    = 3,
    hardware    = 4,
    people      = 5
};
static const QString ASSETTYPE[] =
{
    "None",
    "Information",
    "Systems",
    "Software",
    "Hardware",
    "People"
};

enum Probability
{
    noProb      = 0,
    improbable  = 1,
    incredible  = 2,
    remote      = 3,
    occasional  = 4,
    probable    = 5,
    frequent    = 6
};
static const QString PROBABILITY[] =
{
    "None",
    "Improbable",
    "Incredible",
    "Remote",
    "Occasional",
    "Probable",
    "Frequent"
};

enum ResponceType
{
    accept,
    transfer,
    prevent,
    deter,
    detect,
    react
};

#endif // PROPENUMS_H
