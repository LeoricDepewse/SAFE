#include "risk.h"

Risk::Risk(std::string name, Vulnerability *vuln, Threat *threat, int id, bool isNew) : SecObject(name, id, isNew)
{
    _vuln = vuln;
    _threat = threat;
    _calcRating();
}

ObjectType Risk::type() const
{
    return risk;
}

Vulnerability *Risk::vuln() const
{
    return _vuln;
}

Threat *Risk::threat() const
{
    return _threat;
}

int Risk::rating() const
{
    return _rating;
}

Responce *Risk::responce() const
{
    return _resp;
}

void Risk::vuln(Vulnerability *value)
{
    _vuln = value;
    _calcRating();
}

void Risk::threat(Threat *value)
{
    _threat = value;
    _calcRating();
}

void Risk::responce(Responce *resp)
{
    _resp = resp;
    _changed = true;
}

void Risk::_calcRating()
{
    int frequency = (int)_threat->frequency;
    int severity = (int)_vuln->severity;
    _rating = frequency * severity;
    _changed = true;
}
