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
   while (app_run)
   {
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
      cout << "help tutorial\n  ⮡ Find out how the program works.\n";
      cout << "help airport\n  ⮡ See the airport commands.\n";
      cout << "help flight\n  ⮡ See the flight commands.\n";
      cout << "help passenger\n  ⮡ See the passenger commands.\n";
      cout << "help plane\n  ⮡ See the plane commands.\n\n";
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
   cout << "These are all the Flight commands:\n";
   cout << "display         Displays flights\n";
   cout << "'idFlight'      Selects flight with correspondent id\n";
   cout << "add             Adds new flight\n";
}

void App::helpPassenger()
{
   cout << ""; //TODO
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
       }
       theFlight();
   }
   return; //TODO
}

void App::passenger()
{
   return; //TODO
}

void App::plane()
{
   return; //TODO
}

void App::quit()
{
   app_run = false;
}

void App::addFlight() {

}

void App::theFlight() {
    string id = command.front();
    command.pop();
    if (command.empty()){ // command example for this path: flight 5. It displays data from flight number 5.
        // acabar
    }
    if (command.front() == "buy")
    {
        // acabar
    }

}

