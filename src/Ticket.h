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
      bool getBaggage();
   private:
      Flight flight;
      bool baggage;

};

#endif