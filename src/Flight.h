#ifndef FLIGHT_H
#define FLIGHT_H

#include "Aeroport.h"

class Flight
{
   public:

      /**Flight's default constructor.**/
      Flight(): capacity(0) {};

      /**
         *Constructor for Ticket.

         *@param capacity - The capacity for this flight.
      **/
      Flight(const int &number, const string &departure, const string &duration, const Aeroport &origin, const Aeroport &destination, const int& capacity);

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
      const int capacity;
      int occupation;
      int number;
      string departure;
      string duration;
      Aeroport origin;
      Aeroport destination;
};

#endif