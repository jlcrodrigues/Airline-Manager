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

         @param flight - The flight the ticket's for.
         @param baggage - True if the ticket should include baggage. False by default.

         @return - Returns true if the purchase was successful, false otherwise.
      */
      bool buyTicket(Flight& flight, const bool& baggage = false);

      /*
         Overloaded buyTicket for when you want multiple tickets.

         @param flight - The flight the ticket's for.
         @param members - Vector with the group people organized by passanger profile and baggage option.

         @return - Returns true if the purchase was successful, false otherwise.
      */
      bool buyTicket(Flight& flight, vector<struct GroupMember>& members);

      // ********** development purpose only *************
      //bool g() {return tickets[0].getBaggage();};
      int g() {return tickets.size();};

   private:

      string name;
      vector<Ticket> tickets;
};

/*Defines a passenger and their baggage option for group ticket purchases.*/
struct GroupMember
{
   Passenger& passenger;
   bool baggage;
};


#endif