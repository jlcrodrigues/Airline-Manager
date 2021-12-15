#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>
#include "bst.h"

using namespace std;

/** Defines the transports close to the airport**/
struct Transport {
    string type;
    int distance;
    int time;
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
    Airport(const string& name, BST<Transport> transports);


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
    BST<Transport> transports;
};

#endif