#ifndef AIRPORT_H
#define AIRPORT_H

#include <string>

using namespace std;

/** Defines the transports close to the airport**/
struct Transport {
    string type;
    int distance;
    int time;
};

class Airport
{
public:

    /**Airport default's constructor.**/
    Airport();

    /**
       *Constructor for plane.

       *@param name - airport's name.
    **/
    Airport(const string& name);

    /**
       *Getter for name.

       *@return name - Returns airport's name.
    **/
    string getName();

    /**
       *Setter for name.

       *@param name - airport's name.
    **/
    void setName(const string& name);
private:
    string name;
    //BST<Transport> transports;
};

#endif