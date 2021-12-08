#ifndef PLANE_H
#define PLANE_H

#include "Service.h"
#include "Plane.h"
#include "Flight.h"

#include <string>
#include <queue>
#include <list>

using namespace std;

class Plane
{
   public:

      /**Plane's default constructor.**/
      Plane();

      /**
         *Constructor for plane.

         *@param id - The license number.
         *@param capacity - Plane's capacity.
      **/
      Plane (const string& id, const int&capacity);

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
     * Getter for next service in order
     * @return - Returns the oldest service of the queue
     */

    Service getNextService();

    /**
       * Method to add flight to list of flights
       * @param flight - Flight to add
       */
    //void addFlight(const Flight& flight);

private:
      const string id;
      const int capacity;
      queue<Service> services;
      list<Flight> flights;
};

#endif