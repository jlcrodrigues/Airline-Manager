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
      cout << "help plane\n  - See the plane commands.\n\n";
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
   cout << "Invalid option. Use help to see the available options.\n";
}

void App::helpTutorial()
{
   cout << "tutorial"; //TODO tutorial
}

void App::helpAirport()
{
   cout << ""; //TODO
}

void App::helpFlight()
{
   cout << "flight display\n  - Displays flights\n";
   cout << "flight 'idFlight'\n  - Selects flight with correspondent id\n";
   cout << "flight add 'flightsID, departureDate, departureTime, duration, origin Airport id, destination Airport id'\n  - Adds new flight\n\n";
   cout << "flight remove 'flightsID, departureDate, departureTime, duration, origin Airport id, destination Airport id'\n  -  Removes flight\n\n";
   cout << "flight edit 'x' 'y' 'z'\n  -  Edits flight with id x. Changes attribute y to new value z\n\n";
   cout << "flight sort 'order\n  - Sorts the flights in the specified order - 'number', 'duration', 'capacity' and 'departure'\n\n";
}

void App::helpPassenger()
{
   cout << "passenger add 'id'\n  - Add the passenger by id.\n";
   cout << "passenger display [page]\n  - Displays the existing passengers.\n";
   cout << "passenger edit 'id'\n  - Edit an existing passenger by id.\n";
   cout << "passenger remove 'id'\n  - Removes an existing passenger by id.\n";
   //TODO cout << "passenger find 'id'\n  - Try to locate a passenger by id.\n";
   cout << "passenger sort 'order'\n  - Sorts the passengers in the specified order.\n";
}

void App::helpPlane()
{
   cout << ""; //TODO
}

void App::airport()
{
   return; //TODO
}

void App::flight()
{
   if (command.empty())
   {
       cout << "Invalid option. Use help to see the available options.\n";
   }
   else if (command.front() == "display")
   {
       command.pop();
       // Airline::displayAllFlights();
   }
   else if (command.front() == "add")
   {
       command.pop();
       addFlight();
   }
   else
   {
       try
       {
           stoi(command.front());
       }catch (...)
       {
           cout <<"Invalid id number. Id must be an integer\n";
           app_run = false;
       }
       selectedFlight();
   }
   return; //TODO
}

void App::addFlight() {

}

void App::selectedFlight() {
   string id = command.front();
   command.pop();

   if (command.empty()){ // command example for this path: flight 5. It displays data from flight number 5.

   }
   if (command.front() == "buy")
   {
      // acabar
   }

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
   else if (command.front() == "sort")
   {
      command.pop();
      sortPassenger();
   }
   else cout << "Invalid command. Use help passenger to get more info.\n";
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
   else cout << "That passenger doesn't exist.";
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
