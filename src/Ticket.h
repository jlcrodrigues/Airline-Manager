#ifndef TICKET_H
#define TICKET_H

#include "Flight.h"

class Ticket 
{
   public:

      /*
         Constructor for Ticket.

         @param flight - The flight the ticket's from.
      */
      Ticket (const Flight& flight);
   private:
      const Flight& flight;

};

#endif