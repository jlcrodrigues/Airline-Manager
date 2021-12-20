#include "Passenger.h"

using namespace std;

string Passenger::sorting_rule = "name"; //id, name

bool cmpString(string s1, string s2)
{
   transform(s1.begin(), s1.end(), s1.begin(), [](unsigned char c){return tolower(c);});
   transform(s2.begin(), s2.end(), s2.begin(), [](unsigned char c){return tolower(c);});
   return s1 < s2;
}

Passenger::Passenger(const int& id, const string& name)
{
   this->id = id;
   this->name = name;
}

string Passenger::getCsv() const
{
   string csv = "";
   csv += to_string(id) + ',';
   csv += name;
   for (auto & ticket: tickets)
   {
      string bag = "0";
      if (ticket.getBaggage()) bag = "1";
      string checkin = "0";
      if (ticket.hasCheckedIn()) checkin = "1";
      csv += ',' + to_string(ticket.getFlight().getNumber()) + ',';
      csv += bag + ',' + checkin;
   }
   csv += '\n';
   return csv;
}

void Passenger::addTicket(const Ticket &ticket)
{
   tickets.push_back(ticket);
}

bool Passenger::removeTicket(const int &flight_id)
{
   vector<Ticket>::iterator it = tickets.begin();
   for (; it != tickets.end(); it++)
   {
      if (it->getFlight().getNumber() == flight_id)
      {
         tickets.erase(it);
         return true;
      }
   }
   return false;
}

bool Passenger::buyTicket(Flight* flight, const bool& baggage)
{
   if (!ticketOwned(*flight))
   {
      if (flight->buyTicket())
      {
         tickets.push_back(Ticket(*flight, baggage));
         return true;
      }
   }
   return false;
}

bool Passenger::buyTicket(Flight* flight, vector<struct GroupMember>& members)
{
   for (auto member: members)
   {
      if (member.passenger->ticketOwned(*flight)) return false;
   }
   if (flight->buyTicket(members.size()))
   {
      for (auto& member : members)
      {
         member.passenger->tickets.push_back(Ticket(*flight, member.baggage));
      }
      return true;
   }
   return false;
}

vector<Ticket> Passenger::getTickets() const
{
   return tickets;
}

int Passenger::getId() const
{
   return id;
}

string Passenger::getName() const
{
   return name;
}

bool Passenger::checkIn(Flight& flight)
{
   if (!ticketOwned(flight)) return false;
   size_t i = findTicket(flight);
   tickets[i].checkIn();
   return true;
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

Ticket Passenger::getTicket(const Flight& flight) const
{
   return tickets[findTicket(flight)];
}

bool Passenger::operator < (const Passenger& p) const
{
   if (sorting_rule == "id") {
      if (id == p.getId()) return cmpString(name, p.getName());
      return id < p.getId();
   }
   else if (sorting_rule == "name")
   {
      if (name == p.getName()) return id < p.getId();
      return cmpString(name, p.getName());
   }
   throw (invalid_argument("That rule does not exist."));
   return false;
}

bool Passenger::operator==(const Passenger &p) const
{
   return id == p.getId();
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