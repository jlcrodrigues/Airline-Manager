#include "App.h"

void App::passenger()
{
   if (command.empty())
   {
      cout << "Invalid command. Use help passenger to see available commands.\n";
   }
   else if (command.front() == "add")
   {
      command.pop();
      addPassenger();
      return;
   }
   else if (command.front() == "display")
   {
      command.pop();
      displayPassenger();
      return;
   }
   else if (command.front() == "edit")
   {
      command.pop();
      editPassenger();
   }
   else if (command.front() == "remove")
   {
      command.pop();
      removePassenger();
   }
   else if (command.front() == "find")
   {
      command.pop();
      findPassenger();
   }
   else if (command.front() == "search")
   {
      command.pop();
      searchPassenger();
   }
   else if (command.front() == "sort")
   {
      command.pop();
      sortPassenger();
   }
   else if (command.front() == "checkin")
   {
      command.pop();
      checkIn();
   }
   else cout << "Invalid command. Use help passenger to get more info.\n";
}

void App::displayPassenger()
{
   int page;
   vector<Passenger> passengers = airline.getPassengers();
   if (passengers.size() == 0)
   {
      cout << "No passengers to display.\n";
      return;
   }
   vector<vector<string>> table;
   table.push_back({"Id", "Name"});
   if (command.empty()) page = 0;
   else if (!readNumber(page, command.front()))
   {
      cout << "Page must be a number. Please try again.\n";
      return;
   }
   for (auto & p: passengers) table.push_back({to_string(p.getId()), p.getName()});
   displayTable(table, page);
}

void App::addPassenger()
{
   int id;
   if (command.empty())
   {
      cout << "Usage:\n  passenger add 'id'\n";
      return;
   }
   if (!readNumber(id, command.front()))
   {
      cout << "Id must be a number. Please try again.\n";
      return;
   }
   command.pop();
   if (airline.checkPassenger(id))
   {
      cout << "That passenger already exists. Maybe you want to try:\n  passenger edit 'id'\n";
   }
   else
   {
      string name;
      cout << "Name: ";
      getline(cin, name);
      airline.addPassenger({id, name});
      cout << "\nPassenger " << name << " added to the airline.\n";
   }

}

void App::editPassenger()
{
   int id;
   string name;
   if (command.empty())
   {
      cout << "Usage:\n  passenger edit 'id'\n";
      return;
   }
   if (!readNumber(id, command.front()))
   {
      cout << "Id must be a number. Please try again.\n";
      return;
   }
   if (!airline.removePassenger(id))
   {
      cout << "That passenger doesn't exist. Maybe you want to try:\n  passenger add 'id'\n";
      return;
   }
   cout << "Name: "; cin >> name; clearStream();
   airline.addPassenger({id, name});
   cout << "Passenger " << name << " was updated.\n";
}

void App::removePassenger()
{
   int id;
   if (command.empty())
   {
      cout << "Usage:\n  passenger remove 'id'\n";
      return;
   }
   if (!readNumber(id, command.front()))
   {
      cout << "Id must be a number. Please try again.\n";
      return;
   }
   if (airline.removePassenger(id))
   {
      cout << "Passenger " << id << " was removed.\n";
   }
   else cout << "That passenger doesn't exist.\n";
}

void App::findPassenger()
{
   int id;
   if (command.empty())
   {
      cout << "Usage:\n  - passenger find 'id'\n";
      return;
   }
   if (!readNumber(id, command.front()))
   {
      cout << "Id must be a number. Please try again.\n";
      return;
   }
   if (airline.checkPassenger(id))
   {
      Passenger* p = airline.findPassenger(id);
      cout << "Id: " << p->getId() << " \nName: " << p->getName() << "\n";
   }
   else cout << "Passenger not found.\n";
}

void App::searchPassenger()
{
   int page = 0;
   string name;
   vector<Passenger> passengers;
   vector<vector<string> > table;
   if (command.empty())
   {
      cout << "Usage:\n  - passenger search 'name' [page]\n";
      return;
   }
   while (!readNumber(page, command.front()))
   {
      name += command.front() + ' ';
      command.pop();
      if (command.empty()) break;
   }
   passengers = airline.searchNames(name);
   if (passengers.empty())
      cout << "No passengers match that name.\n";
   else
   {
      table.push_back({"Id", "Name"});
      for (auto & p: passengers) table.push_back({to_string(p.getId()), p.getName()});
      displayTable(table, page);
   }
}

void App::sortPassenger()
{
   if (!command.empty()) {
      if (command.front() == "id" || command.front() == "name") {
         airline.setPassengerOrder(command.front());
         cout << "Passengers sorted by " << command.front() << ".\n";
      }
   }
   else
   {
      cout << "Usage:\n  passenger sort 'order'\n\n  Order options: id, name\n";
   }
}

void App::checkIn()
{
   int id, flight_id;
   if (command.empty())
   {
      cout << "Usage:\n  passenger checkin 'id' 'flight_id'\n";
      return;
   }
   if (!readNumber(id, command.front()))
   {
      cout << "Not a valid Passenger id. Please try again.\n";
      return;
   }
   command.pop();
   if (!readNumber(flight_id, command.front()))
   {
      cout << "Not a valid Flight id. Please try again.\n";
      return;
   }
   command.pop();
   if (!airline.checkPassenger(id))
   {
      cout << "Passenger not found. Use passenger display to see available passengers.\n";
      return;
   }
   if (!airline.checkFlight(flight_id))
   {
      cout << "Flight not found. Please check the flight Id.\n";
      return;
   }
   Passenger* passenger = airline.findPassenger(id);
   Flight* flight = airline.findFlight(flight_id);
   if (passenger->ticketOwned(*flight))
   {
      Ticket ticket = passenger->getTicket(*flight);
      if (ticket.hasCheckedIn())
      {
         cout << "Passenger " << id << " has already checked in to that flight.\n";
         return;
      }
      if (!passenger->getTicket(*flight).getBaggage())
      {
         airline.checkIn(flight_id, id);
      }
      else
      {
         double weight;
         cout << "Baggage weight (kg): ";
         cin >> weight;
         clearStream();
         if (!airline.checkIn(flight_id, id, weight))
         {
            cout << "Flight " << flight_id << "'s carts are all full. Try adding a new one before checking in a passenger.\n";
            return;
         }
      }
      cout << "Check in successful!\n";
   }
}