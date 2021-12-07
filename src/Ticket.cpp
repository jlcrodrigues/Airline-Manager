#include "Ticket.h"

using namespace std;

Ticket::Ticket(const Flight& flight, const bool& baggage): flight(flight)
{
   this->baggage = baggage;
}

bool Ticket::getBaggage()
{
   return baggage;
}