#include "Passenger.h"

using namespace std;

Passenger::Passenger(const string& name)
{
   this->name = name;
}

void Passenger::buyTicket(Flight& flight)
{
   if (flight.buyTicket())
   {
      tickets.push_back(Ticket(flight));
   }
}