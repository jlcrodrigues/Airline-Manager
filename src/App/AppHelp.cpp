#include "App.h"

void App::help()
{
   if (command.empty())
   {
      cout << "To find out how to use Airline Manager please use the following commands:\n\n";
      cout << "help tutorial\n  - Find out how the program works.\n";
      cout << "help general\n  - See general use commands.\n";
      cout << "help airport\n  - See the airport commands.\n";
      cout << "help cart\n  - See the cart commands.\n";
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
   else if (command.front() == "general")
   {
      helpGeneral();
      return;
   }
   else if (command.front() == "airport" || command.front() == "a")
   {
      helpAirport();
      return;
   }
   else if (command.front() == "cart" || command.front() == "c")
   {
      helpCart();
      return;
   }
   else if (command.front() == "flight" || command.front() == "f")
   {
      helpFlight();
      return;
   }
   else if (command.front() == "passenger" || command.front() == "pa")
   {
      helpPassenger();
      return;
   }
   else if (command.front() == "plane" || command.front() == "pl")
   {
      helpPlane();
      return;
   }
   else if (command.front() == "ticket" || command.front() == "t")
   {
      helpTicket();
      return;
   }
   cout << "Invalid option. Use help to see the available options.\n";
}

void App::helpTutorial()
{
   cout << "Welcome to Airline Manager! This tool will allow your airline to manage flights, passengers and planes.\n";
   cout << "To get a grip of the available commands navigate trough the help sections.\n\n";
   cout << "You can keep a list of known passengers and get them tickets to flight as well as checking them in to those flights.\n";
   cout << "When someone checks in with a baggage it will be stored in a cart so be sure your flight has some cart assigned.\n";
   cout << "When a flight is ready to go, you can make it take off and we will take care of all the organizing for you.\n";
   cout << "You can also keep a list of airports, which also store information about local transfers.\n\n";
}

void App::helpGeneral()
{
   cout << "alias\n  - Learn about known aliases.\n";
   cout << "resize 'size'\n  - Change the items per page on display.\n";
   cout << "about\n  - Learn about this program.\n";
   cout << "quit\n  - Exit the program.\n";
}

void App::helpAirport()
{
   cout << "airport display [page]\n  - Displays airports.\n";
   cout << "airport add 'nameAirport'\n  - Add the airport by name.\n";
   cout << "airport edit name 'nameAirport' \n  - Edits an existing airport name by previous name.\n";
   cout << "airport edit transport add 'nameAirport' \n  - Adds a transport to an existent airport.\n";
   cout << "airport remove 'nameAirport'\n  - Removes an existing airport by name.\n";
   cout << "airport find 'nameAirport'\n  -  Try to locate a airport by name.\n";
}

void App::helpCart()
{
   cout << "cart display [page]\n  - Displays the existing carts.\n";
   cout << "cart add 'id'\n  - Add the cart by id.\n";
   cout << "cart edit 'id'\n  - Edit the cart by id.\n";
   cout << "cart remove 'id'\n  - Remove a cart by id.\n";
   cout << "cart find 'id'\n  - Try to locate a cart by id.\n";
   cout << "cart assign 'id' 'flight_id'\n  - Assign a cart to a flight.\n";
}

void App::helpFlight()
{
   cout << "flight display [page]\n  - Displays the existing flights.\n";
   cout << "flight display--p 'startDate' 'endDate' [page]\n  - Displays the existing flights from startDate to endDate.\n";
   cout << "flight add 'id'\n  - Adds the flight by id.\n";
   cout << "flight edit 'id'\n  - Edit an existing flight by id.\n";
   cout << "flight remove 'id'\n  - Removes an existing flight by id.\n";
   cout << "flight find 'id'\n  - Try to locate a flight by id.\n";
   cout << "flight sort 'order\n  - Sorts the flights in the specified order - 'number', 'duration', 'capacity' or 'departure.'\n";
   cout << "flight fly 'id'\n  - Take off flight number id.\n";
   cout << "flight plane 'idFlight' 'idPlane'\n  -  Add plane to flight.\n";
}

void App::helpPassenger()
{
   cout << "passenger display [page]\n  - Displays the existing passengers.\n";
   cout << "passenger add 'id'\n  - Add the passenger by id.\n";
   cout << "passenger edit 'id'\n  - Edit an existing passenger by id.\n";
   cout << "passenger remove 'id'\n  - Removes an existing passenger by id.\n";
   cout << "passenger find 'id'\n  - Try to locate a passenger by id.\n";
   cout << "passenger search 'name'\n  - Find passengers by name.\n";
   cout << "passenger sort 'order' [page]\n  - Sorts the passengers in the specified order.\n";
   cout << "passenger checkin 'id' 'flight_id'\n  - Check in a passenger to a flight.\n";
}

void App::helpPlane()
{
   cout << "plane display [page]\n  - Displays the existing planes.\n";
   cout << "plane add 'id'\n - Add the plane by id.\n";
   cout << "plane edit 'id'\n  - Edit an existing plane by id.\n";
   cout << "plane remove 'id'\n  - Removes an existing plane by id.\n";
   cout << "plane find 'id'\n  - Try to locate a plane by id.\n";
   cout << "plane sort 'order'\n  - Sorts the plane in the specified order.\n";
   cout << "plane hist 'id' [page]\n  -  Displays plane's flights history.\n";
   cout << "plane service display 'id'\n  -  Displays plane's future services.\n";
   cout << "plane service display--o 'id'  -  Displays plane's completed services.\n";
   cout << "plane service add 'id'\n  -  Adds a new future service to plane.\n";
   cout << "plane service next 'id'\n  -  Marks next service in queue as completed.\n";
}

void App::helpTicket()
{
   cout << "ticket display flight 'id'\n  - See who has a ticket to that flight.\n";
   cout << "ticket display passenger 'id'\n  - See the tickets owned by a passenger.\n";
   cout << "ticket buy 'flight_id' 'passenger_id'\n  - Buy the passenger a ticket for the flight.\n";
   cout << "ticket buy 'flight_id' id_list\n  - Buy a ticket to various passengers.\n";
}