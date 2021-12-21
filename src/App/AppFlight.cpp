#include "App.h"

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
   }
   else if (command.front() == "display--p")
   {
      command.pop();
      partialDisplayFlight();
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
   else if (command.front() == "fly")
   {
      command.pop();
      flyFlight();
   }
   else if (command.front() == "plane")
   {
      command.pop();
      flightPlane();
   }
   else cout << "Invalid command. Use help flight to get more info.\n";
   return;
}

void App::displayFlight()
{
   vector<Flight> flights = airline.getFlights();
   int page;
   if (flights.size() == 0)
   {
      cout << "No flights to display.\n";
      return;
   }
   vector<vector<string>> table;
   table.push_back({"Number", "Departure Date", "Departure Time", "Duration", "Origin Airport", "Destination Airport", "Capacity", "Plane"});
   if (command.empty()) page = 0;
   else if (!readNumber(page, command.front()))
   {
      cout << "Page must be an integer. Please try again.\n";
      return;
   }
   for (auto & f: flights) table.push_back({to_string(f.getNumber()), f.getDepartureDate().displayDate(), f.getDepartureTime().displayTime(), f.getDuration().displayTime(), f.getAirportOrigin().getName(), f.getAirportDestination().getName(), to_string(f.getCapacity()), f.getPlane() });
   displayTable(table, page);
}

void App::partialDisplayFlight()
{
   Date start, end;
   if (command.empty())
   {
      cout << "Invalid command. Try help to see available commands.\n";
      return;
   }
   string since = command.front();
   command.pop();
   if (!readDate(start, since))
   {
      cout << "Invalid date. Please try again.\n";
      return;
   }
   if (command.empty())
   {
      cout << "Invalid command. Try help to see available commands.\n";
      return;
   }
   string until = command.front();
   command.pop();
   if (!readDate(end, until))
   {
      cout << "Invalid date. Please try again.\n";
      return;
   }
   if (end < start)
   {
      cout << "Invalid input. First date has to be older than the second one.\n";
      return;
   }
   int page;
   if (command.empty()) page = 0;
   else if (!readNumber(page, command.front()))
   {
      cout << "Page number must be an integer.\n";
      return;
   }
   vector<Flight> flights;
   vector<vector<string>> table;
   table.push_back({"Number", "Departure Date", "Departure Time", "Duration", "Origin Airport", "Destination Airport", "Capacity", "Plane"});
   bool b = false;
   airline.setFlightOrder("departure");
   int endIndex = airline.getFlights().size() - 1;

   for (auto it: airline.getFlights())
   {
      if (start < it.getDepartureDate() || it.getDepartureDate() == start)
      {
         if (it.getDepartureDate() < end || it.getDepartureDate() == end)
         {
            flights.push_back(it);
         }
      }
   }
   if (flights.size() == 0)
   {
      cout << "There are no flights recorded in that date frame.\n";
      return;
   }
   for (auto & f: flights) table.push_back({to_string(f.getNumber()), f.getDepartureDate().displayDate(), f.getDepartureTime().displayTime(), f.getDuration().displayTime(), f.getAirportOrigin().getName(), f.getAirportDestination().getName(), to_string(f.getCapacity()), f.getPlane()});
   displayTable(table, page);
}

void App::addFlight() {
   int id;
   if (command.empty()) {
      cout << "Usage:\n  flight add 'id'\n";
      return;
   } else if (!readNumber(id, command.front())) {
      cout << "Id must be an integer. Please try again.\n";
      return;
   }
   command.pop();
   if (airline.checkFlight(id)) {
      cout << "That flight already exists. To check existing flights try:\n  flight display\n";
   } else {
      string dD, dT, d, aO, aD, idP; // departureDate, departureTime, duration, airportOrigin, airportDestination, idPlane
      Date departureDate, departureTime, duration;
      if (command.empty())
      {
         cout << "Plane id: ";
         cin >> idP;
         clearStream();
         if (!airline.checkPlane(idP))
         {
            if(!invalidPlane(idP)) return;
         }
      }
      else
      {
         idP = command.front();
         if (!airline.checkPlane(idP))
         {
            if(!invalidPlane(idP)) return;
         }
         command.pop();
      }
      if (command.empty()) {
         cout << "Departure date (dd/mm/yyyy): ";
         cin >> dD;
         clearStream();
         if (!readDate(departureDate, dD)) {
            invalidDepartureDate(departureDate, dD);
         }
      }
      else {
         dD = command.front();
         if (!readDate(departureDate, dD)) {
            invalidDepartureDate(departureDate, dD);
         }
         command.pop();
      }
      if (command.empty()) {
         cout << "Departure time (hh:mm): ";
         cin >> dT;
         clearStream();
         if (!readTime(departureTime, dT)) {
            invalidDepartureTime(departureTime, dT);
         }
      }
      else {
         dT = command.front();
         if (!readTime(departureTime, dT)) {
            invalidDepartureTime(departureTime, dT);
         }
         command.pop();
      }
      if (command.empty()) {
         cout << "Duration (hh:mm): ";
         cin >> d;
         clearStream();
         if (!readDuration(duration, d)) {
            invalidDuration(duration, d);
         }
      }
      else {
         d = command.front();
         if (!readDuration(duration, d)) {
            invalidDuration(duration, d);
         }
         command.pop();
      }
      if (command.empty()) {
         cout << "Origin airport id: ";
         cin >> aO;
         clearStream();
         if (!airline.checkAirport(aO))
         {
            if (!invalidAirportOrigin(aO)) return;
         }
      }
      else
      {
         aO = command.front();
         transform(aO.begin(), aO.end(), aO.begin(), ::toupper);
         if (!airline.checkAirport(aO))
         {
            if (!invalidAirportOrigin(aO)) return;
         }
         command.pop();
      }
      if (command.empty()) {
         cout << "Destination airport id: ";
         cin >> aD;
         clearStream();
         if (!airline.checkAirport(aD))
         {
            if (!invalidAirportDestination(aD)) return;
         }
      }
      else {
         aD = command.front();
         transform(aD.begin(), aD.end(), aD.begin(), ::toupper);
         if (!airline.checkAirport(aD))
         {
            if (!invalidAirportDestination(aD)) return;
         }
         command.pop();
      }
      if (aO == aD)
      {
         cout << "Error. Airport origin and airport destination must be different.\n";
         return;
      }
      airline.addFlight({id, departureDate, departureTime, duration, *airline.findAirport(aO), *airline.findAirport(aD), airline.findPlane(idP)->getCapacity()});
      airline.findFlight(id)->setPlane(idP);
      airline.findPlane(idP)->addFlight({id, departureDate, departureTime, duration, *airline.findAirport(aO), *airline.findAirport(aD), airline.findPlane(idP)->getCapacity()});
      cout << "Flight number " << id << " was added successfully.\n";
   }
}

void App::editFlight()
{
   int id;
   string attribute;
   if (command.empty()) {
      cout << "Usage:\n  flight edit 'id'\n";
      return;
   }
   if (!readNumber(id, command.front())) {
      cout << "Id must be an integer. Please try again.\n";
      return;
   }
   if (!airline.checkFlight(stoi(command.front())))
   {
      cout << "That flight doesn't exist. To check existing flights try:\n  flight display\n";
      return;
   }
   id = stoi(command.front());
   command.pop();
   Date departureDate, departureTime, duration;
   if (command.empty())
   {
      cout << "Which attribute do you want to edit?\nOptions: departureDate, departureTime, duration, origin, destination, capacity, plane.\nAttribute: ";
      cin >> attribute;
      clearStream();
      if (attribute == "departureDate")
      {
         string dD;
         cout << "New departure date (dd/mm/yyyy): ";
         cin >> dD;
         clearStream();
         if (!readDate(departureDate, dD)) {
            invalidDepartureDate(departureDate, dD);
         }
         Flight f(id, departureDate, airline.findFlight(id)->getDepartureTime(), airline.findFlight(id)->getDuration(), airline.findFlight(id)->getAirportOrigin(), airline.findFlight(id)->getAirportDestination(), airline.findFlight(id)->getCapacity());
         f.setPlane(airline.findFlight(id)->getPlane());
         airline.findPlane(airline.findFlight(id)->getPlane())->removeFlight(*airline.findFlight(id));
         airline.findPlane(airline.findFlight(id)->getPlane())->addFlight(f);
         airline.removeFlight(id);
         airline.addFlight(f);
         cout << "Flight " << id << " was updated with a new departure date.\n";
         return;
      }
      if (attribute == "departureTime")
      {
         string dT;
         cout << "New departure time (hh:mm): ";
         cin >> dT;
         clearStream();
         if (!readDate(departureTime, dT)) {
            invalidDepartureTime(departureTime, dT);
         }
         Flight f(id, airline.findFlight(id)->getDepartureDate(), departureTime, airline.findFlight(id)->getDuration(), airline.findFlight(id)->getAirportOrigin(), airline.findFlight(id)->getAirportDestination(), airline.findFlight(id)->getCapacity());
         f.setPlane(airline.findFlight(id)->getPlane());
         airline.findPlane(airline.findFlight(id)->getPlane())->removeFlight(*airline.findFlight(id));
         airline.findPlane(airline.findFlight(id)->getPlane())->addFlight(f);
         airline.removeFlight(id);
         airline.addFlight(f);
         cout << "Flight " << id << " was updated with a new departure time.\n";
         return;
      }
      if (attribute == "duration")
      {
         string d;
         cout << "New duration (hh:mm): ";
         cin >> d;
         clearStream();
         if (!readDuration(duration, d)) {
            invalidDuration(duration, d);
         }
         Flight f(id, airline.findFlight(id)->getDepartureDate(), airline.findFlight(id)->getDepartureTime(), duration, airline.findFlight(id)->getAirportOrigin(), airline.findFlight(id)->getAirportDestination(), airline.findFlight(id)->getCapacity());
         f.setPlane(airline.findFlight(id)->getPlane());
         airline.findPlane(airline.findFlight(id)->getPlane())->removeFlight(*airline.findFlight(id));
         airline.findPlane(airline.findFlight(id)->getPlane())->addFlight(f);
         airline.removeFlight(id);
         airline.addFlight(f);
         cout << "Flight " << id << " was updated with a new duration.\n";
         return;
      }
      if (attribute == "origin")
      {
         string aO;
         cout << "New origin airport id: ";
         cin >> aO;
         clearStream();
         transform(aO.begin(), aO.end(), aO.begin(), ::toupper);
         if (!airline.checkAirport(aO))
         {
            if (!invalidAirportOrigin(aO)) return;
         }
         Flight f(id, airline.findFlight(id)->getDepartureDate(), airline.findFlight(id)->getDepartureTime(), airline.findFlight(id)->getDuration(), *airline.findAirport(aO), airline.findFlight(id)->getAirportDestination(), airline.findFlight(id)->getCapacity());
         f.setPlane(airline.findFlight(id)->getPlane());
         airline.findPlane(airline.findFlight(id)->getPlane())->removeFlight(*airline.findFlight(id));
         airline.findPlane(airline.findFlight(id)->getPlane())->addFlight(f);
         airline.removeFlight(id);
         airline.addFlight(f);
         cout << "Flight " << id << " was updated with a new origin airport.\n";
         return;
      }
      if (attribute == "destination")
      {
         string aD;
         cout << "New destination airport id: ";
         cin >> aD;
         clearStream();
         transform(aD.begin(), aD.end(), aD.begin(), ::toupper);
         if (!airline.checkAirport(aD))
         {
            if (!invalidAirportDestination(aD)) return;
         }
         Flight f(id, airline.findFlight(id)->getDepartureDate(), airline.findFlight(id)->getDepartureTime(), airline.findFlight(id)->getDuration(), *airline.findAirport(aD), airline.findFlight(id)->getAirportDestination(), airline.findFlight(id)->getCapacity());
         f.setPlane(airline.findFlight(id)->getPlane());
         airline.findPlane(airline.findFlight(id)->getPlane())->removeFlight(*airline.findFlight(id));
         airline.findPlane(airline.findFlight(id)->getPlane())->addFlight(f);
         airline.removeFlight(id);
         airline.addFlight(f);
         cout << "Flight " << id << " was updated with a new destination airport.\n";
         return;
      }
      if (attribute == "capacity")
      {
         string capacity;
         int capacityI;
         cout << "New flight capacity: ";
         cin >> capacity;
         clearStream();
         if (!readNumber(capacityI, capacity))
         {
            while (1) {
               cout << "Flight capacity must be an integer. Please try again.\nFlight capacity: ";
               cin >> capacity;
               clearStream();
               if (readNumber(capacityI, capacity)) break;
            }
         }
         Flight f(id, airline.findFlight(id)->getDepartureDate(), airline.findFlight(id)->getDepartureTime(), airline.findFlight(id)->getDuration(), airline.findFlight(id)->getAirportOrigin(), airline.findFlight(id)->getAirportDestination(), capacityI);
         f.setPlane(airline.findFlight(id)->getPlane());
         if (airline.findFlight(id)->getPlane() != "NONE")
         {
            airline.findPlane(airline.findFlight(id)->getPlane())->removeFlight(*airline.findFlight(id));
            airline.findPlane(airline.findFlight(id)->getPlane())->addFlight(f);
         }
         airline.removeFlight(id);
         airline.addFlight(f);
         cout << "Flight " << id << " was updated with a new capacity.\n";
         return;
      }
      if (attribute == "plane")
      {
         string idP;
         cout << "New plane: ";
         cin >> idP;
         clearStream();
         if (!airline.checkPlane(idP))
         {
            cout << "Plane " << idP << " doesn't exist. Try plane display to check existing planes.\n";
            return;
         }
         if (airline.findFlight(id)->getPlane() == "NONE")
         {
            Flight f(id, airline.findFlight(id)->getDepartureDate(), airline.findFlight(id)->getDepartureTime(), airline.findFlight(id)->getDuration(), airline.findFlight(id)->getAirportOrigin(), airline.findFlight(id)->getAirportDestination(), airline.findFlight(id)->getCapacity());
            f.setPlane(idP);
            airline.findPlane(idP)->addFlight(f);
            airline.removeFlight(id);
            airline.addFlight(f);
            cout << "Flight " << id << " was updated with a new plane.\n";
            return;
         }
         Flight f(id, airline.findFlight(id)->getDepartureDate(), airline.findFlight(id)->getDepartureTime(), airline.findFlight(id)->getDuration(), airline.findFlight(id)->getAirportOrigin(), airline.findFlight(id)->getAirportDestination(), airline.findFlight(id)->getCapacity());
         f.setPlane(idP);
         airline.findPlane(airline.findFlight(id)->getPlane())->removeFlight(*airline.findFlight(id));  // removes flight from old plane's flights list
         airline.findPlane(idP)->addFlight(f);  // adds flight to new plane's flights list
         airline.removeFlight(id);
         airline.addFlight(f);
         cout << "Flight " << id << " was updated with a new plane.\n";
         return;
      }
      cout << "Invalid option.\n";
      return;
   }
   else
   {
      cout << "Invalid command. Use help to see the available commands.\n";
      return;
   }
}

void App::removeFlight()
{
   int id;
   if (command.empty())
   {
      cout << "Usage:\n  flight remove 'id'\n";
      return;
   }
   if (!readNumber(id, command.front()))
   {
      cout << "Id must be an integer. Please try again.\n";
      return;
   }
   if (airline.removeFlight(id))
   {
      cout << "Flight " << id << " was removed.\n";
   }
   else cout << "That flight doesn't exist.\n";
}

void App::findFlight()
{
   int id;
   if (command.empty())
   {
      cout << "Usage:\n  - flight find 'id'\n";
      return;
   }
   if (!readNumber(id, command.front()))
   {
      cout << "Id must be an integer. Please try again.\n";
      return;
   }
   if (airline.checkFlight(id))
   {
      Flight* f = airline.findFlight(id);
      cout << "Id: " << f->getNumber() << "\nDeparture date: " << f->getDepartureDate().displayDate() << "\nDeparture time: " << f->getDepartureTime().displayDate() << "\nDuration: " << f->getDuration().displayTime() << "\nOrigin airport: " << f->getAirportOrigin().getName() << "\nDestination airport: " << f->getAirportDestination().getName() << "\nCapacity: " << f->getCapacity() << endl;
   }
   else cout << "Flight not found. To check existing flights you can try: \n  flight display\n";
}

void App::sortFlight()
{
   if (!command.empty())
   {
      if (command.front() == "number" || command.front() == "departure" || command.front() == "duration" || command.front() == "capacity")
      {
         airline.setFlightOrder(command.front());
         cout << "Flights sorted by " << command.front() << ".\n";
      }
      else
      {
         cout << "Invalid sort option. Use help flight for more info.\n";
      }
   }
   else
   {
      cout << "Usage:\n  flight sort 'order'\n\n  Order options: number, departure, duration, capacity\n";
   }
}

void App::flyFlight()
{
   int id, n_tickets, n_passengers, n_seats;
   if (command.empty())
   {
      cout << "Usage:\n  flight fly 'id'\n";
      return;
   }
   if (!readNumber(id, command.front()))
   {
      cout << "Invalid id. Please try again.\n";
      return;
   }
   if (!airline.checkFlight(id))
   {
      cout << "That flight doesn't exist. Use flight display to see available flights.\n";
      return;
   }
   Flight* flight = airline.findFlight(id);
   n_seats = flight->getCapacity();
   n_passengers = airline.getCheckedIn(id);
   n_tickets =  airline.flyFlight(id);
   cout << "The flight took of with " << n_passengers << " passengers and " << n_tickets << "/" << n_seats << " tickets sold.\n";
}

void App::flightPlane()
{
   if (command.empty())
   {
      cout << "Usage:\n  flight plane 'idFlight' 'idPlane'\n";
      return;
   }
   int idF;
   string idP;
   if (!readNumber(idF, command.front()))
   {
      cout << "Flight id must me an integer.\n";
      return;
   }
   if (!airline.checkFlight(idF))
   {
      cout << "Flight number " << idF << " doesn't exist. Use flight display to check existing flights.\n";
      return;
   }
   command.pop();
   idP = command.front();
   transform(idP.begin(), idP.end(), idP.begin(), ::toupper);
   if (!airline.checkPlane(idP))
   {
      cout << "Plane number " << idP << " doesn't exist. Use plane display to check existing planes.\n ";
      return;
   }
   airline.findFlight(idF)->setPlane(idP);
   airline.findPlane(idP)->addFlight(*airline.findFlight(idF));
   cout << "Flight number " << idF << " was successfully attributed to plane " << idP << ".\n";
}