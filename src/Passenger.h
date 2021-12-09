#ifndef PASSENGER_H
#define PASSENGER_H

#include <string>
#include <vector>
#include <stdexcept>

#include "Flight.h"
#include "Ticket.h"

using namespace std;

class Passenger
{
   public:
      Passenger() {};

      /**
         *Constructor for Passanger.

         *@param name - Passenger's name.
      **/
      Passenger(const string& name);

      /**
         *Buys a ticket.

         *@param flight - The flight the ticket's for.
         *@param baggage - True if the ticket should include baggage. False by default.

         *@return - Returns true if the purchase was successful, false otherwise.
      **/
      bool buyTicket(Flight& flight, const bool& baggage = false);

      /**
         *Overloaded buyTicket for when you want multiple tickets.

         *@param flight - The flight the ticket's for.
         *@param members - Vector with the group people organized by passanger profile and baggage option.

         *@return - Returns true if the purchase was successful, false otherwise.
      **/
      bool buyTicket(Flight& flight, vector<struct GroupMember>& members);

      // ********** development purpose only *************
      //bool g() {return tickets[0].getBaggage();};
      int g() {return tickets.size();};

      /**
       * Checks a bag into a flight.

       * @param flight - The flight you want to check in.
       * @param weight - The bag's weight.

       * @return - Returns true if the check-in was successful, false otherwise.
       */
      bool checkIn(const Flight& flight, const double& weight);

   private:
      /**
       * Checks if a ticket has been purchased already.

       * @param flight - The flight we want to check for.

       * @return Returns true if the passenger owns the ticket, false otherwise.
       */
      bool ticketOwned(const Flight& flight) const;

      /**
       * Looks for a ticket and returns it's index in tickets if found.
       * @param flight - The flight you want a ticket to.
       * @return - Returns the ticket's index for that flight.
       */
      size_t findTicket(const Flight& flight) const;

      string name;
      vector<Ticket> tickets;
};

/**Defines a passenger and their baggage option for group ticket purchases.**/
struct GroupMember
{
   Passenger& passenger;
   bool baggage;
};


#endif