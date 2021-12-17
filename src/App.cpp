#include "App.h"

App::App()
{
   app_run = true;
}

App::App(const string &airports, const string &flights, const string &passengers, const string &planes)
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
      else if (command.front() == "airport")
      {
         command.pop();
         airport();
         return;
      }
      else if (command.front() == "flight")
      {
         command.pop();
         flight();
         return;
      }
      else if (command.front() == "passenger")
      {
         command.pop();
         passenger();
         return;
      }
      else if (command.front() == "plane")
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
   cout << "passenger display\n  - Displays the existing passengers.\n";
   cout << "passenger edit 'id'\n  - Edit an existing passenger by id.\n";
   cout << "passenger find 'id'\n  - Try to locate a passenger by id.\n";
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
      return;
   }
}

void App::addPassenger()
{

}

void App::plane()
{
   return; //TODO
}

void App::quit()
{
   app_run = false;
}

