#include "risk.h"

Risk::Risk(std::string name, Vulnerability *vuln, Threat *threat) : SecObject(name)
{
    _vuln = vuln;
    _threat = threat;
    _calcRating();
}

ObjectType Risk::type()
{
    return risk;
}

Vulnerability *Risk::vuln() const
{
    return _vuln;
}

void Risk::vuln(Vulnerability *value)
{
    _vuln = value;
    _calcRating();
}

Threat *Risk::threat() const
{
    return _threat;
}

void Risk::threat(Threat *value)
{
    _threat = value;
    _calcRating();
}

int Risk::rating() const
{
    return _rating;
}

void Risk::_calcRating()
{
    int frequency = (int)_threat->frequency;
    int severity = (int)_vuln->severity;
    _rating = frequency * severity;
}
