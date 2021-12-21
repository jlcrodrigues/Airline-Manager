#include "Service.h"

Service::Service(const string &type, const Date &date, const Employee &employee)
{
    this->type = type;
    this->date = date;
    this->emp = employee;
}

string Service::getServiceType()
{
    return type;
}

Employee Service::getServiceEmployee()
{
    return emp;
}

Date Service::getServiceDate()
{
    return date;
}

