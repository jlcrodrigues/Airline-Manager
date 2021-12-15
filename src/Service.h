#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include <queue>
#include "Date.h"

using namespace std;

struct Employee
{
    string name;
    int id;
};


class Service
{
public:
    /**
     * Service Constructor
     * @param type - Type of service (maintenance or cleaning)
     * @param date - Date service will be done
     * @param employee - Employee in charge of service
     */

    Service(const string&type, const Date&date, const Employee& employee);

    /**
     * Getter for type of service
     * @return - Returns service's type
     */
    string getServiceType();

    /**
     * Getter for service's employee
     * @return - Returns service's employee
     */
    Employee getServiceEmployee();

private:
    string type;
    Date date;
    Employee emp;
};

#endif