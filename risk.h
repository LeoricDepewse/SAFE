#ifndef RISK_H
#define RISK_H
#include "vulnerability.h"
#include "threat.h"

class Risk : SecObject
{
public:
    Risk(std::string name, Vulnerability *vuln, Threat *threat);

    ObjectType type();

    Vulnerability *vuln() const;
    void vuln(Vulnerability *value);
    Threat *threat() const;
    void threat(Threat *value);
    int rating() const;

private:
    void _calcRating();
    Vulnerability *_vuln;
    Threat *_threat;
    int _rating;
};

#endif // RISK_H
