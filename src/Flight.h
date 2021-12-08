#ifndef FLIGHT_H
#define FLIGHT_H

#include "Plane.h"
#include "Aeroport.h"

class Flight
{
   public:

      /**Flight's default constructor.**/
      Flight();

      /**
         *Constructor for Ticket.

         *@param capacity - The capacity for this flight.
      **/
      Flight(const Plane &Plane, const int &number, const string &departure, const string &duration, const Aeroport &origin, const Aeroport &destination);

      /**
         *Getter for occupation.

         *@return - The flight's current occupation.
      **/
      int getOccupation() const;

      /**
         *If there's one available, fills a seat.

         *@return - True if the ticket was bought, false otherwise.
      **/
      bool buyTicket(const int& amount = 1);

   private:
      
      const Plane plane;
      int capacity;
      int occupation;
      int number;
      string departure;
      string duration;
      Aeroport origin;
      Aeroport destination;
};

#endif