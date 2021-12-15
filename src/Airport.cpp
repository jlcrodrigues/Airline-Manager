#include "Airport.h"

Airport::Airport(const string& name, set<Transport> transports){
    this->name = name;
    this->transports = transports;
}

string Airport::getCsv() const
{
    string csv = "";
    csv += name + '\n';
    return csv;
}

string Airport::getName() const {
    return name;
}

void Airport::setName(const string &name) {
    this->name = name;
}

Transport Airport::findClosest() {
    return *transports.begin();
}

bool Airport::operator < (const Airport &a1) const
{
    return name < a1.getName();
}


bool Transport::operator<(const Transport &t1) const {
    return distance < t1.distance;
}