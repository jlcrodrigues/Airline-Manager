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
       * Method to add flight to list of flights
       * @param flight - Flight to add
       */
    void addFlight(const Flight& flight);

    /**
     * Getter for list of flights
     * @return - Returns list of plane's flights records
     */
    list<Flight> getFlights();

private:
      const string id;
      const int capacity;
      queue<Service> services;
      vector<Service> old_services;
      list<Flight> flights;
};

#endif