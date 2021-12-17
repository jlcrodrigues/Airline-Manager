#include "App.h"

App::App(): ITEMS_PER_PAGE(5)
{
   app_run = true;
}

App::App(const string &airports, const string &flights, const string &passengers, const string &planes): ITEMS_PER_PAGE(5)
{
   airline = Airline(airports, flights, passengers, planes);
   app_run = true;
}

void App::run()
{
   cout << "Welcome to Airline Manager. Use help to get started.\n";
   while (app_run)
   {
      cout << ">";
      readCommand();
      processCommand();
   }
}

void App::clearStream() const
{
   cin.clear();
   cin.ignore(INT_MAX, '\n');
}

bool App::readNumber(int& n, const string& s) const
{
   try
   {
      n = stoi(s);
      return true;
   }
   catch (...)
   {
      return false;
   }
}

bool App::getOption() const
{
   char option = 'a';
   while (option != 'y' && option != 'n')
   {
      cin >> option;
      option = tolower(option);
   }
   clearStream();
   if (option == 'y') return true;
   return option != 'n';
}

void App::readCommand()
{
   string w;
   getline(cin, w);
   stringstream word(w);
   queue<string> empty;
   swap(command, empty);
   while (getline(word, w, ' '))
   {
      if (!cin)
      {
         if (cin.eof()) app_run = false;
         else cout << "Something went wrong. Please try again.";
      }
      transform(w.begin(), w.end(), w.begin(), [](unsigned char c){return tolower(c);});
      command.push(w);
   }
}

void App::processCommand()
{
   if (!command.empty())
   {
      if (command.front() == "help")
      {
         command.pop();
         help();
         return;
      }
      else if (command.front() == "airport" || command.front() == "a")
      {
         command.pop();
         airport();
         return;
      }
      else if (command.front() == "flight" || command.front() == "f")
      {
         command.pop();
         flight();
         return;
      }
      else if (command.front() == "passenger" || command.front() == "pa")
      {
         command.pop();
         passenger();
         return;
      }
      else if (command.front() == "plane" || command.front() == "pl")
      {
         command.pop();
         plane();
         return;
      }
      else if (command.front() == "quit")
      {
         quit();
         return;
      }
   }
   cout << "Invalid command. Verify that it is right or use help.\n";
}

void App::help()
{
   if (command.empty())
   {
      cout << "To find out how to use Airline Manager please use the following commands:\n\n";
      cout << "help tutorial\n  - Find out how the program works.\n";
      cout << "help airport\n  - See the airport commands.\n";
      cout << "help flight\n  - See the flight commands.\n";
      cout << "help passenger\n  - See the passenger commands.\n";
      cout << "help plane\n  - See the plane commands.\n";
      cout << "help ticket\n  - See the ticket commands.\n\n";
      return;
   }
   else if (command.front() == "tutorial")
   {
      helpTutorial();
      return;
   }
   else if (command.front() == "airport")
   {
      helpAirport();
      return;
   }
   else if (command.front() == "flight")
   {
      helpFlight();
      return;
   }
   else if (command.front() == "passenger")
   {
      helpPassenger();
      return;
   }
   else if (command.front() == "plane")
   {
      helpPlane();
      return;
   }
   else if (command.front() == "ticket")
   {
      helpTicket();
      return;
   }
   cout << "Invalid option. Use help to see the available options.\n";
}

void App::helpTutorial()
{
   cout << "tutorial"; //TODO tutorial
}

void App::helpAirport()
{
    cout << "airport display\n  - Displays airports"; //TODO
    cout << "airport 'nameAirport\n  - Selects airport with correspondent name\n";
    cout << "airport add 'nameAirport'\n  - Add the airport by name\n";
    cout << "airport remove 'nameAirport'\n  - Removes an existing airport by name\n";
    cout << "airport edit 'nameAirport'\n  - Edits an existing airport by name\n";
}

void App::helpFlight()
{
   cout << "flight display [page]\n  - Displays the existing flights\n";
   cout << "flight add 'id'\n  - Adds the flight by id.\n";
   cout << "flight edit 'id'\n  -  Edit an existing flight by id.\n";
   cout << "flight remove 'id'\n  -  Removes an existing flight by id.\n";
   cout << "flight find 'id'\n  -  Try to locate a flight by id.\n";
   cout << "flight sort 'order\n  - Sorts the flights in the specified order - 'number', 'duration', 'capacity' and 'departure'\n";
}

void App::helpPassenger()
{
   cout << "passenger display [page]\n  - Displays the existing passengers.\n";
   cout << "passenger add 'id'\n  - Add the passenger by id.\n";
   cout << "passenger edit 'id'\n  - Edit an existing passenger by id.\n";
   cout << "passenger remove 'id'\n  - Removes an existing passenger by id.\n";
   cout << "passenger find 'id'\n  - Try to locate a passenger by id.\n";
   cout << "passenger sort 'order'\n  - Sorts the passengers in the specified order.\n";
}

void App::helpPlane()
{
   cout << ""; //TODO
}

void App::helpTicket()
{
   cout << "ticket buy 'flight_id' 'passenger_id'\n  - Buy the passenger a ticket for the flight.\n";
   cout << "ticket buy 'flight_id' id_list\n  - Buy a ticket to various passengers.\n";
}

void App::airport()
{
    if (command.empty())
    {
        cout << "Invalid command. Use help airport to see available commands.\n";
    }
    else if (command.front() == "add")
    {
        command.pop();
        addAirport();
    }
    else if (command.front() == "display")
    {
        command.pop();
        displayAirport();
    }
    else if (command.front() == "edit")
    {
        command.pop();
        editAirport();
    }
    else if (command.front() == "remove")
    {
        command.pop();
        removeAirport();
    }
    else cout << "Invalid command. Use help airport to get more info.\n";
}

void App::flight()
{
   if (command.empty())
   {
       cout << "Invalid option. Use help to see the available commands.\n";
   }
   else if (command.front() == "add")
   {
       command.pop();
       addFlight();
   }
   else if (command.front() == "display")
   {
       command.pop();
       displayFlight();
       return;
   }
   else if (command.front() == "edit")
   {
       command.pop();
       editFlight();
   }
   else if (command.front() == "remove")
   {
       command.pop();
       removeFlight();
   }
   else if (command.front() == "find")
   {
       command.pop();
       findFlight();
   }
   else if (command.front() == "sort")
   {
       command.pop();
       sortFlight();
   }
   else cout << "Invalid command. Use help flight to get more info.\n";
   return;
}

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
   else if (command.front() == "sort")
   {
      command.pop();
      sortPassenger();
   }
   else cout << "Invalid command. Use help passenger to get more info.\n";
}

void App::addAirport()
{
    string name;
    if(command.empty())
    {
        cout << "Usage:\n  airport add 'nameAirport'\n";
        return;
    }
    name = command.front();
    command.pop();
    if (airline.checkAirport(name))
    {
        cout << "That airport already exists. Maybe you want to try:\n  airport edit 'nameAirport'\n";
    }
    else
    {
        airline.addAirport({name});
        cout << "\nAirport " << name << " added to the airline.\n";
    }
}

void App::addFlight() {
    int id;
    if (command.empty()) {
        cout << "Usage:\n flight add 'id'\n";
        return;
    } else if (!readNumber(id, command.front())) {
        cout << "Id must be a number. Please try again.\n";
        return;
    }
    command.pop();
    if (airline.checkFlight(id)) {
        cout << "That flight already exists. Maybe you want to try:\n  flight edit 'id'\n";
    } else {
        string dD, dT, d; // departureDate, departureTime, duration
        Date departureDate, departureTime, duration;
        if (command.empty()) {

        }
    }
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
      if (command.empty()) {
         cout << "Name: ";
         cin >> name;
         clearStream();
      }
      else name = command.front();
      airline.addPassenger({id, name});
      cout << "\nPassenger " << name << " added to the airline.\n";
   }

}

void App::displayFlight()
{

}

void App::displayPassenger()
{
   vector<Passenger> passengers = airline.getPassengers();
   int page;
   if (command.empty()) page = 0;
   else if (!readNumber(page, command.front()))
   {
      cout << "Page must be a number. Please try again.\n";
      return;
   }
   page *= ITEMS_PER_PAGE;
   while (passengers.size() <= page) page -= ITEMS_PER_PAGE;
   if (0 <= page)
   {
      cout << "Id\tName\n";
      for (int i = page; i < passengers.size() &&  i < page + ITEMS_PER_PAGE; i++)
      {
         cout << passengers[i].getId() << '\t' << passengers[i].getName() << '\n';
      }
      //cout << "Page (" << page / 5 + 1 << "/" << passengers.size() / 5 << ").\n"; TODO
   }
   else cout << "No passengers to display.\n\n";
}

void App::editFlight()
{

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

void App::removeFlight()
{

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
   else cout << "That passenger doesn't exist.";
}

void App::findFlight()
{

}

void App::findPassenger()
{
   int id;
   if (command.empty())
   {
      cout << "Usage:\n  - passenger find 'id'";
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

void App::sortFlight()
{

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

void App::plane()
{
   return; //TODO
}

void App::ticket()
{
   if (command.empty())
   {
      cout << "Invalid command. Use help ticket to see available commands.\n";
   }
   else if (command.front() == "buy")
   {
      command.pop();
      buyTicket();
      return;
   }
}

void App::buyTicket()
{
   int flight_id, passenger_id;
   vector<GroupMember> group;
   if (command.empty())
   {
      helpTicket(); return;
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
         cout << "Passenger " << passenger_id << "not found. Use passenger help to add a passenger or passenger display to see the available passengers.\n";
         return;
      }
      Passenger* pa = airline.findPassenger(passenger_id);
      char option;
      cout << "Include baggage for passenger " << pa->getName() << "(" << pa->getId() << ")? (y/n) ";
      group.push_back({pa, getOption()});
   }
   if (airline.buyTicket(flight, group))
   {
      cout << "The tickets to " << flight->getAirportDestination().getName() << " were bought.\n";
   }
   else
      cout << "Couldn't buy tickets. Please try again.";
}

void App::quit()
{
   app_run = false;
}

bool App::partialDisplay(string since, string until)
{
   bool b = false;
   Date start(stoi(since.substr(0,2)), stoi(since.substr(2,2)), stoi(since.substr(4)));
   Date end(stoi(until.substr(0,2)), stoi(until.substr(2,2)), stoi(until.substr(4)));
   if (end < start) return false;

   airline.setFlightOrder("departure");
   int endIndex = airline.getFlights().size() - 1;

   cout <<"═════════════════════════════════════════════════════════════════════════════\n";
   cout <<"Number  DepartureDate  DepartureTime  Duration  Origin  Destination  Capacity\n";
   for (vector<Flight>::iterator it = airline.getFlights().begin(); it != airline.getFlights().end(); it++)
   {
      if (it->getDepartureDate() == start || start < it->getDepartureDate()){
         for (vector<Flight>::iterator it2 = it; it2 != airline.getFlights().end(); it2++){
            if (it2->getDepartureDate() == end){
               partialDisplayAux(*it2);
               b = true;
               continue;
            }
            if (!(it2->getDepartureDate() == end) && b == true) return true;
            partialDisplayAux(*it2);
            if(it2 == airline.getFlights().end() - 1) return true;
         }
      }
   }

}

void App::partialDisplayAux(Flight f)
{
   cout <<f.getNumber() << "  " << f.getDepartureDate().displayDate() <<"  "<<f.getDepartureTime().displayTime() <<"  "<<f.getDepartureDate().displayTime() << "  " << f.getAirportOrigin().getName() <<"  "<<f.getAirportDestination().getName() <<"  "<<f.getDuration().displayTime() << endl;
}
