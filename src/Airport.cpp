#include "Airport.h"

Airport::Airport() {

}

Airport::Airport(const string& name){
    this->name = name;
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

bool Airport::operator < (const Airport &a1) const
{
   return name < a1.getName();
}