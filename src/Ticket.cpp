#include "Ticket.h"

using namespace std;

Ticket::Ticket(const Flight& flight, const bool& baggage): flight(flight)
{
   this->baggage = baggage;
   checked_in = false;
}

Flight Ticket::getFlight() const
{
   return flight;
}

bool Ticket::getBaggage() const
{
   return baggage;
}

void Ticket::checkIn()
{
   checked_in = true;
}

bool Ticket::hasCheckedIn() const
{
   return checked_in;
}