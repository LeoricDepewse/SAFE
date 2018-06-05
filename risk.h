#ifndef RISK_H
#define RISK_H
#include "vulnerability.h"
#include "threat.h"
#include "responce.h"

class Risk : SecObject
{
public:
    Risk(std::string _name, Vulnerability *vuln, Threat *threat, bool isNew = false);

    ObjectType type() const;

    Vulnerability *vuln() const;
    Threat *threat() const;
    int rating() const;
    Responce *responce() const;

    void vuln(Vulnerability *value);
    void threat(Threat *value);
    void responce(Responce *resp);

private:
    void _calcRating();
    Vulnerability *_vuln;
    Threat *_threat;
    int _rating;
    Responce *_resp = nullptr;
};

#endif // RISK_H
