#include <algorithm>
#include "Airport.h"
Airport::Airport(const string& name){
    this->name = name;
    transports = set<Transport>();
}

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

bool Airport::addTransport(Transport t1) {
    for (auto i: transports){
        if(i.distance == t1.distance && i.type == t1.type){
            i.time.insert(i.time.end(),t1.time.begin(),t1.time.end());
            vector<Date>::iterator it;
            it = unique(i.time.begin(),i.time.end());
            i.time.resize(distance(i.time.begin(), it));
            return false;
        }
    }
    transports.insert(t1);
    return true;
}

set<Transport> Airport::getTransports() {
    return transports;
}

bool Transport::operator<(const Transport &t1) const {
    if (distance == t1.distance){
        return (type < t1.type);
    }
    return distance < t1.distance;
}