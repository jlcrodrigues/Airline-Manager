#include "App.h"

void App::ticket()
{
   if (command.empty())
   {
      cout << "Command not recognized. Use help ticket to see available commands.\n";
   }
   else if (command.front() == "buy")
   {
      command.pop();
      buyTicket();
   }
   else if (command.front() == "display")
   {
      command.pop();
      displayTicket();
   }
   else cout << "Invalid command. Use help passenger to get more info.\n";
}

void App::displayTicket()
{
   if (command.empty()) {
      cout << "Usage:\n  ";
      cout << "  ticket display flight 'flight_id'\n    - See who has a ticket to that flight.\n";
      cout << "  ticket display passenger 'passenger_id'\n    - See the tickets owned by a passenger.\n";
   }
   else if (command.front() == "flight" || command.front() == "f")
   {
      command.pop();
      displayTicketFlight();
   }
   else if (command.front() == "passenger" || command.front() == "pa")
   {
      command.pop();
      displayTicketPassenger();
   }
   else cout << "Invalid command. Use ticket display to get more info.\n";
}

void App::displayTicketFlight()
{
   int page, flight_id;
   if (command.empty())
   {
      cout << "Usage:\n  - ticket display flight 'flight_id'\n";
      return;
   }
   if (!readNumber(flight_id, command.front()))
   {
      cout << "Please specify a valid Id. Use flight display to see available flights.\n";
      return;
   }
   command.pop();
   if (!airline.checkFlight(flight_id))
   {
      cout << "That flight doesn't exist. Use flight display to see available flights.\n";
      return;
   }
   Flight* flight = airline.findFlight(flight_id);
   vector<PassengerTicket> tickets = airline.getTicketsToFlight(*flight);
   if (tickets.size() == 0)
   {
      cout << "Tickets are yet to be purchased for flight " << flight->getNumber() << ".\n";
      return;
   }
   vector<vector<string> > table;
   table.push_back({"Id", "Name", "Baggage", "Checked in"});
   if (command.empty()) page = 0;
   else if (!readNumber(page, command.front()))
   {
      cout << "Page must be a number. Please try again.\n";
      return;
   }
   for (auto & t: tickets)
   {
      string bag = "No";
      string check_in = "No";
      if (t.ticket.hasCheckedIn()) check_in = "Yes";
      if (t.ticket.getBaggage()) bag = "Yes";
      table.push_back({to_string(t.passenger.getId()),
                       t.passenger.getName(),
                       bag, check_in});
   }
   displayTable(table, page);
}

void App::displayTicketPassenger()
{
   int page, passenger_id;
   if (command.empty())
   {
      cout << "Usage:\n  - ticket display passenger 'passenger_id'\n";
      return;
   }
   if (!readNumber(passenger_id, command.front()))
   {
      cout << "Please specify a valid Id. Use passenger display to see available passengers.\n";
      return;
   }
   command.pop();
   if (!airline.checkPassenger(passenger_id))
   {
      cout << "That passenger doesn't exist. Use passenger display to see available passengers.\n";
      return;
   }
   Passenger* passenger = airline.findPassenger(passenger_id);
   vector<Ticket> tickets = passenger->getTickets();
   if (tickets.size() == 0)
   {
      cout << "Passenger " << passenger->getId() << " doesn't own any tickets yet. Use ticket buy to purchase one.\n";
      return;
   }
   vector<vector<string> > table;
   table.push_back({"Flight Id", "Origin", "Destination", "Baggage", "Checked in"});
   if (command.empty()) page = 0;
   else if (!readNumber(page, command.front()))
   {
      cout << "Page must be a number. Please try again.\n";
      return;
   }
   for (auto & t: tickets) {
      Flight flight = t.getFlight();
      string bag = "No";
      string check_in = "No";
      if (t.hasCheckedIn()) check_in = "Yes";
      if (t.getBaggage()) bag = "Yes";
      table.push_back({to_string(flight.getNumber()),
                       flight.getAirportOrigin().getName(),
                       flight.getAirportDestination().getName(),
                       bag, check_in});
   }
   displayTable(table, page);
}

void App::buyTicket()
{
   int flight_id, passenger_id;
   vector<GroupMember> group;
   if (command.empty())
   {
      cout << "Usage:\n";
      cout << "  ticket buy 'flight_id' 'passenger_id'\n    - Buy the passenger a ticket for the flight.\n";
      cout << "  ticket buy 'flight_id' id_list\n    - Buy a ticket to various passengers.\n";
      return;
   }
   if (!readNumber(flight_id, command.front()))
   {
      cout << "Invalid flight. Use flight display to see available flights.\n";
      return;
   }
   Flight* flight = airline.findFlight(flight_id);
   if (!airline.checkFlight(flight_id))
   {
      cout << "Flight not recognized. Use flight add to add a flight or flight display to see available flights.\n";
      return;
   }
   command.pop();
   while (!command.empty())
   {
      if (!readNumber(passenger_id, command.front()))
      {
         cout << "'" << command.front() << "' is not a valid passenger. Use passenger display to see available passengers.\n";
         return;
      }
      if (!airline.checkPassenger(passenger_id))
      {
         cout << "Passenger " << passenger_id << " not found. Use passenger help to add a passenger or passenger display to see the available passengers.\n";
         return;
      }
      Passenger* pa = airline.findPassenger(passenger_id);
      cout << "Include baggage for passenger " << pa->getName() << " (" << pa->getId() << ")? (y/n):";
      group.push_back({pa, getOption()});
      command.pop();
   }
   if (airline.buyTicket(flight, group))
   {
      cout << "\nThe tickets to " << flight->getAirportDestination().getName() << " were bought.\n";
   }
   else
      cout << "Couldn't buy tickets. Please try again.\n";
}
