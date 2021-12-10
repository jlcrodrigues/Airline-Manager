#include "Passenger.h"

using namespace std;

Passenger::Passenger(const string& name)
{
   this->name = name;
}

bool Passenger::buyTicket(Flight& flight, const bool& baggage)
{
   if (!ticketOwned(flight))
   {
      if (flight.buyTicket())
      {
         tickets.push_back(Ticket(flight, baggage));
         return true;
      }
   }
   return false;
}

bool Passenger::buyTicket(Flight& flight, vector<struct GroupMember>& members)
{
   for (auto member: members)
   {
      if (member.passenger.ticketOwned(flight)) return false;
   }
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

bool Passenger::checkIn(Flight& flight)
{
   if (!ticketOwned(flight)) return false;
   size_t i = findTicket(flight);
   if (tickets[i].getBaggage())
   {
      throw invalid_argument("You should check in with baggage.");
      return false;
   }
   tickets.erase(tickets.begin() + i);
   return true;
}

bool Passenger::checkIn(Flight& flight, const double& weight)
{
   if (!ticketOwned(flight)) return false;
   size_t i = findTicket(flight);
   if (tickets[i].getBaggage())
   {
      tickets.erase(tickets.begin() + i);
      flight.insertBaggage(Baggage(weight));
      return true;
   }
   return false;
}

bool Passenger::ticketOwned(const Flight& flight) const
{
   for (auto ticket : tickets)
   {
      if (ticket.getFlight().getNumber() == flight.getNumber())
         return true;
   }
   return false;
}

size_t Passenger::findTicket(const Flight& flight) const
{
   for (size_t i = 0; i < tickets.size(); i++)
   {
      if (tickets[i].getFlight().getNumber() == flight.getNumber())
         return i;
   }
   throw invalid_argument("This passenger does not own that ticket.");
   return -1;
}