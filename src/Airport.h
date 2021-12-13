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
private:
    string name;
    //BST<Transport> transports;
};

#endif