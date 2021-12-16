#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>
#include <set>
#include <vector>
#include "Date.h"

using namespace std;

/** Defines the transports close to the airport**/
struct Transport {
    string type;
    int distance;
    vector<Date> time;
    /**
       * Transport's < operator.
       * @param t1 - An transport object.
       * @return - Returns true if the transport's distance to airport is lower than the other transport
    **/
    bool operator < (const Transport& t1) const;
};

class Airport
{
public:

    /**Airport default's constructor.**/
    Airport()=default;

    /**
       *Constructor for plane.
       *@param name - airport's name.
    **/
    Airport(const string& name);

    /**
       *Constructor for plane.
       * @param name - airport's name
       * @param transports - set of transports near the airport
    **/
    Airport(const string& name, set<Transport> transports);


    /**
     * Turns the object data into a csv row in order to be used later.
     * @return - Returns a string representing a csv row with the class attributes.
     */
    string getCsv() const;

    /**
       *Getter for name.
       *@return name - Returns airport's name.
    **/
    string getName() const;

    /**
       *Setter for name.
       *@param name - airport's name.
    **/
    void setName(const string& name);


    /**
       * Gets all the transports near the airport.
       * @return - Returns a set with all transports.
    **/
    set<Transport> getTransports();

    /**
       * Adding a transport to the set of transports on Airport.
       * @param t1 - Transport that will be added.
       * @return - True if the Transport was added successfully, false if Transport already existed.
     **/
    bool addTransport(Transport t1);

    /**
       *Finds the transport that is closer to the airport.
       *@return transport - The closest transport.
    **/
    Transport findClosest();

    /**
     * Airport's < operator.
     * @param a1 - An airport object.
     * @return - //TODO
     */
    bool operator < (const Airport& a1) const;

private:
    string name;
    set<Transport> transports;
};

#endif