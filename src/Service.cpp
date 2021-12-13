#include "Service.h"

Service::Service(const string &type, const string &date, const Employee &employee)
{
    this->type = type;
    this->date = date;
    this->emp = employee;
}

string Service::getServiceType() {
    return type;
}

string Service::getServiceDate() {
    return date;
}

Employee Service::getServiceEmployee() {
    return emp;
}

