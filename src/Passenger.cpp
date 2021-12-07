#include "Passenger.h"

using namespace std;

Passenger::Passenger(const string& name)
{
   this->name = name;
}

bool Passenger::buyTicket(Flight& flight, const bool& baggage)
{
   if (flight.buyTicket())
   {
      tickets.push_back(Ticket(flight, baggage));
      return true;
   }
   return false;
}

bool Passenger::buyTicket(Flight& flight, vector<struct GroupMember>& members)
{
   if (flight.buyTicket(members.size()))
   {
      for (auto& member : members)
      {
         member.passenger.tickets.push_back(Ticket(flight, member.baggage));
      }
      return true;
   }
   return false;
}