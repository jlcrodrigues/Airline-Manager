#ifndef PLANE_H
#define PLANE_H

#include "Service.h"
#include "Flight.h"

#include <string>
#include <queue>
#include <list>

using namespace std;

class Plane
{
   public:
      static string sorting_rule;

      /**Plane's default constructor.**/
      Plane() = default;

      /**
         *Constructor for plane.

         *@param id - The license number.
         *@param capacity - Plane's capacity.
      **/
      Plane (const string& id, const string model, const int&capacity);


      /**
       * Turns the object data into a csv row in order to be used later.
       * @return - Returns a string representing a csv row with the class attributes.
       */
       string getCsv() const;

      /**
         *Getter for capacity.

         *@return - Returns the plane's capacity.
      **/
         int getCapacity() const;

       /**
        * Method to add service to queue of services
        * @param service - Service to add
        */
       void addService(const Service& service);

       /**
        * Getter for plane's services
        * @return - Returns queue of plane's services to be completed
        */
       queue<Service> getServices();

       /**
        * Getter for plane's old services
        * @return - Returns vector of plane's services history
        */
       vector<Service> getOldServices();

       /**
        * Getter for next service in order
        * @return - Returns the next service to be completed
        */
       Service getNextService();

       /**
        * Getter for the id.
        * @return - Returns the plane's id.
        */
       string getId() const;

       /**
        * Getter for plane's model
        * @return - Returns plane's model
        */
       string getModel() const;

       /**
          * Method to add flight to list of flights
          * @param flight - Flight to add
          */
       void addFlight(const Flight& flight);
       void removeFlight (const Flight& flight);

       /**
        * Getter for list of flights
        * @return - Returns list of plane's flights records
        */
       list<Flight> getFlights();

       /**
        * Plane's < operator.
        * @param p1 - A plane object.
        * @return Returns true if the id is lower.
        */
       bool operator < (const Plane& p) const;

private:
      string id;
      int capacity;
      string model;
      queue<Service> services;
      vector<Service> old_services;
      list<Flight> flights;
};

#endif