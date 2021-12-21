#ifndef TICKET_H
#define TICKET_H

#include "Flight.h"

class Ticket 
{
   public:
      Ticket() = default;

      /**
         *Constructor for Ticket.

        *@param flight - The flight the ticket's from.
        *@param baggage - True if the ticket should include baggage. False by default.
      **/
      Ticket(const Flight& flight, const bool& baggage = false);

      /**
       * Getter for flight.

       * @return Returns member flight.
       */
      Flight getFlight() const;

      /**
         *Getter for baggage.

         *@return - Returns baggage boolean.
      **/
      bool getBaggage() const;

      /**
       * Makes the ticket checked in.
       */
      void checkIn();

      /**
       * Check if the ticket has been check in already.
       * @return - True if the ticket is already checked in.
       */
      bool hasCheckedIn() const;
   private:
      Flight flight;
      bool baggage;
      bool checked_in;

};

#endif