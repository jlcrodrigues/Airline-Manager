#ifndef SERVICE_H
#define SERVICE_H

#include <string>
#include <queue>

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

    Service(const string&type, const string&date, const Employee& employee);

private:
    string type;
    string date;
};

#endif