#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include <vector>

#include "Flight.h"
#include "Ticket.h"

using namespace std;

class Passenger
{
   public:

      /*
         Constructor for Passanger.

         @param name - Passenger's name.
      */
      Passenger(const string& name);

      /*
         Buys a ticket.

         @param flight - The flight the ticket's from.
      */
      void buyTicket(Flight& flight);

   private:

      string name;
      vector<Ticket> tickets;
};

#endif