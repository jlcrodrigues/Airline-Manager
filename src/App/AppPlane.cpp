#include "App.h"

void App::plane()
{
   if (command.empty())
   {
      cout << "Invalid command. Use help passenger to see available commands.\n";
   }
   else if (command.front() == "add")
   {
      command.pop();
      addPlane();
      return;
   }
   else if (command.front() == "display")
   {
      command.pop();
      displayPlane();
      return;
   }
   else if (command.front() == "edit")
   {
      command.pop();
      editPlane();
   }
   else if (command.front() == "remove")
   {
      command.pop();
      removePlane();
   }
   else if (command.front() == "find")
   {
      command.pop();
      findPlane();
   }
   else if (command.front() == "sort")
   {
      command.pop();
      sortPlane();
   }
   else if (command.front() == "hist")
   {
      command.pop();
      historyPlane();
   }
   else if (command.front() == "service")
   {
      command.pop();
      servicePlane();
   }
   else cout << "Invalid command. Use help plane to get more info.\n";
}

void App::displayPlane()
{
   int page;
   vector<Plane> planes = airline.getPlanes();
   if (planes.size() == 0)
   {
      cout << "No planes to display.\n";
      return;
   }
   vector<vector<string>> table;
   table.push_back({"Id", "Model", "Capacity"});
   if (command.empty()) page = 0;
   else if (!readNumber(page, command.front()))
   {
      cout << "Page must be an integer. Please try again.\n";
      return;
   }
   for (auto & p: planes) table.push_back({p.getId(), p.getModel(), to_string(p.getCapacity())});
   displayTable(table, page);
}

void App::addPlane()
{
   if (command.empty())
   {
      cout << "Usage:\n  plane add 'id'\n";
      return;
   }
   transform(command.front().begin(), command.front().end(), command.front().begin(), ::toupper);
   if (command.front() == "NONE")
   {
      cout << "NONE is an invalid plane id. Try again.\n";
      return;
   }
   string id = command.front();
   transform(id.begin(), id.end(), id.begin(), ::toupper);
   command.pop();
   if (airline.checkPlane(id))
   {
      cout << "That plane already exists. To check available planes try:\n  plane display\n";
      return;
   }
   string model, capacity;
   int capacityI;
   if (command.empty())
   {
      cout << "Model: ";
      cin >> model;
      clearStream();
      transform(model.begin(), model.end(), model.begin(), ::toupper);
   }
   else
   {
      model = command.front();
      command.pop();
      transform(model.begin(), model.end(), model.begin(), ::toupper);
   }
   if (command.empty())
   {
      cout << "Capacity: ";
      cin >> capacity;
      clearStream();
      if (!readNumber(capacityI, capacity))
      {
         while (1)
         {
            cout << "Capacity must be an integer. Try again.\n\nCapacity: ";
            cin >> capacity;
            clearStream();
            if (readNumber(capacityI, capacity)) break;
         }
      }
   }
   else
   {
      capacity = command.front();
      if (!readNumber(capacityI, capacity))
      {
         while (1)
         {
            cout << "Capacity must be an integer. Try again.\n\nCapacity: ";
            cin >> capacity;
            clearStream();
            if (readNumber(capacityI, capacity)) break;
         }
      }
      capacityI = stoi(capacity);
   }
   airline.addPlane({id, model, capacityI});
   cout << "Plane " << id << " was added to the airline.\n";
}

void App::editPlane()
{
   if (command.empty())
   {
      cout << "Usage:\n  plane edit 'id'.\n";
      return;
   }
   if (!airline.checkPlane(command.front()))
   {
      cout << "That plane doesn't exist. To check existing planes try:\n  plane display\n";
      return;
   }
   string id = command.front();
   command.pop();
   if (command.empty())
   {
      string attribute;
      cout << "Which attribute do you want to edit?\nOptions: model, capacity\nAttribute: ";
      cin >> attribute;
      clearStream();
      if (attribute == "model")
      {
         string model;
         cout << "New model: ";
         cin >> model;
         clearStream();
         Plane p(id, model, airline.findPlane(id)->getCapacity());
         airline.removePlane(id);
         airline.addPlane(p);
         cout << "Plane " << id << " was updated with a new model name.\n";
         return;
      }
      if (attribute == "capacity")
      {
         string capacity;
         int capacityI;
         cout << "New capacity: ";
         cin >> capacity;
         clearStream();
         if (!readNumber(capacityI, capacity))
         {
            while (1)
            {
               cout << "Capacity must be an integer. Try again.\nCapacity: ";
               cin >> capacity;
               clearStream();
               if (readNumber(capacityI, capacity)) break;
            }
         }
         Plane p(id, airline.findPlane(id)->getModel(), capacityI );
         airline.removePlane(id);
         airline.addPlane(p);
         cout << "Plane " << id << " was updated with a new capacity.\n";
         return;
      }
      cout << "Invalid attribute.\n";
      return;
   }
   else
   {
      cout << "Invalid command. Try help to see available commands.\n";
      return;
   }
}

void App::removePlane()
{
   if (command.empty())
   {
      cout << "Usage:\n  plane remove 'id'\n";
      return;
   }
   string idP = command.front();
   transform(idP.begin(), idP.end(), idP.begin(), ::toupper);
   command.pop();
   if (!command.empty())
   {
      cout << "Invalid command. Try again.\n";
      return;
   }
   if (airline.removePlane(idP))
   {
      cout << "Plane " << idP << " was removed.\n";
   }
   else cout << "That plane doesn't exist.\n";
}

void App::findPlane()
{

   if (command.empty()){
      cout << "usage:\n  - plane find 'id'\n";
      return;
   }
   if (airline.checkPlane(command.front()))
   {
      Plane* p = airline.findPlane(command.front());
      cout << "Id: " << p->getId() << "\nModel: " << p->getModel() << "\nCapacity: " << p->getCapacity() << endl;
   }
   else cout << "Plane not found.\n";
}

void App::sortPlane()
{
   if (!command.empty())
   {
      if (command.front() == "id" || command.front() == "model" || command.front() == "capacity")
      {
         airline.setPlaneOrder(command.front());
         cout << "Planes sorted by " << command.front() << "\n";
      }
      else
      {
         cout << "Invalid sort option. Try plane help for more info.\n";
      }
   }
   else
   {
      cout << "Usage:\n  plane sort 'order'\n\n  Order option: id, model, capacity\n";
   }
}

void App::historyPlane()
{
   if (command.empty())
   {
      cout << "Usage:\n  plane history 'id'\n";
      return;
   }
   transform(command.front().begin(), command.front().end(), command.front().begin(), ::toupper);
   if (!airline.checkPlane(command.front()))
   {
      cout << "Plane " << command.front() << " doesn't exist. Try plane display to see existing planes\n";
      return;
   }
   string idPlane = command.front();
   command.pop();
   int page;
   vector<Flight> flights;
   for (auto &f: airline.findPlane(idPlane)->getFlights())
   {
      flights.push_back(f);
   }
   vector<vector<string>> table;
   table.push_back({"Number", "Departure Date", "Departure Time", "Duration", "Origin Airport", "Destination Airport", "Capacity"});
   if (flights.size() == 0)
   {
      cout << "Plane " << idPlane << " has no flights history. You can try - flight plane 'idFlight' 'idPlane' -  to add flights to a plane.\n";
      return;
   }
   if (command.empty()) page = 0;
   else if (!readNumber(page, command.front()))
   {
      cout << "Page must be an integer. Please try again.\n";
      return;
   }
   for (auto & f: flights) table.push_back({to_string(f.getNumber()), f.getDepartureDate().displayDate(), f.getDepartureTime().displayTime(), f.getDuration().displayTime(), f.getAirportOrigin().getName(), f.getAirportDestination().getName(), to_string(f.getCapacity())});
   displayTable(table, page);
}

void App::servicePlane()
{
   if (command.empty())
   {
      cout << "Usage:\n  plane service add 'id'\n  plane service display 'id \n  plane service display--o 'id'\n  plane service next 'id'\n";
      return;
   }
   string idP, option;
   transform(idP.begin(), idP.end(), idP.begin(), ::toupper);
   option = command.front();
   command.pop();
   if (option == "add")
   {
      serviceAdd();
      return;
   }
   else if (option == "display")
   {
      serviceDisplay();
      return;
   }
   else if (option == "display--o")
   {
      serviceDisplayO();
      return;
   }
   else if (option == "next")
   {
      serviceNext();
      return;
   }
   cout << "Invalid command. Try help to see available commands.\n";
}

void App::serviceDisplay()
{
   if (command.empty())
   {
      cout << "Invalid command. Use help to check available commands.\n";
      return;
   }
   string idP = command.front();
   command.pop();
   transform(idP.begin(), idP.end(), idP.begin(), ::toupper);
   if (!airline.checkPlane(idP))
   {
      cout << "Plane " << idP << " doesn't exist. Try plane display to check existing planes.\n";
      return;
   }
   int page, size;
   if (airline.findPlane(idP)->getServices().empty())
   {
      cout << "Plane " << idP << " has no services to be completed. Try plane service add 'id' to add a new one.\n";
      return;
   }
   queue<Service> copy = airline.findPlane(idP)->getServices();
   vector<Service> services;
   size = airline.findPlane(idP)->getServices().size();
   for (int i = 0; i < size; i++)
   {
      services.push_back(copy.front());
      copy.pop();
   }
   vector<vector<string>> table;
   table.push_back({"Type", "Date", "Employee id", "Employee name"});
   if (command.empty()) page = 0;
   else if (!readNumber(page, command.front()))
   {
      cout << "Page must be an integer. Please try again.\n";
      return;
   }
   for (auto & s: services) table.push_back({s.getServiceType(), s.getServiceDate().displayDate() ,s.getServiceEmployee().name, to_string(s.getServiceEmployee().id)});
   displayTable(table, page);
}

void App::serviceDisplayO()
{
   if (command.empty())
   {
      cout << "Invalid command. Use help to check available commands.\n";
      return;
   }
   string idP = command.front();
   command.pop();
   transform(idP.begin(), idP.end(), idP.begin(), ::toupper);
   if (!airline.checkPlane(idP))
   {
      cout << "Plane " << idP << " doesn't exist. Try plane display to check existing planes.\n";
      return;
   }
   int page, size;
   if (airline.findPlane(idP)->getOldServices().size() == 0)
   {
      cout << "Plane " << idP << " has no service history. Try plane service add 'id' to add a new one.\n";
      return;
   }
   vector<Service> services = airline.findPlane(idP)->getOldServices();
   vector<vector<string>> table;
   table.push_back({"Type", "Date", "Employee id", "Employee name"});
   if (command.empty()) page = 0;
   else if (!readNumber(page, command.front()))
   {
      cout << "Page must be a number. Please try again.\n";
      return;
   }
   for (auto & s: services) table.push_back({s.getServiceType(), s.getServiceDate().displayDate() ,s.getServiceEmployee().name, to_string(s.getServiceEmployee().id)});
   displayTable(table, page);
}

void App::serviceAdd() {
   if (command.empty()) {
      cout << "Invalid command. Use help if you need to.\n";
      return;
   }
   string idP = command.front();
   command.pop();
   if (!command.empty())
   {
      cout << "Invalid command.\n";
      return;
   }
   transform(idP.begin(), idP.end(), idP.begin(), ::toupper);
   if (!airline.checkPlane(idP)) {
      cout << "Plane " << idP << " doesn't exist. Try plane display to check existing planes.\n";
      return;
   }
   string type, date, name, idS;
   int id;
   Date d;
   Employee e;
   cout << "Service type (cleaning, maintenance): ";
   cin >> type;
   clearStream();
   if (type == "cleaning" || type == "maintenance") {
      cout << "Service date (dd/mm/yyyy): ";
      cin >> date;
      clearStream();
      if (!readDate(d, date)) {
         cout << "Invalid date.\n";
         return;
      }
//        if (!airline.findPlane(idP)->getServices().empty())
//        {
//            if (airline.findPlane(idP)->getServices().back().getServiceDate() < d)
//            {
//                cout << "You can't add a service with this date because there's services scheduled after this date.\nYou can use plane next 'id' to clear the queue.\n";
//                return;
//            }
//        }
      cout << "Employee id: ";
      cin >> idS;
      clearStream();
      if (!readNumber(id, idS)) {
         cout << "Employee id must be an integer.\n";
         return;
      }
      cout << "Employee name: ";
      cin >> name;
      clearStream();
      e.id = id;
      e.name = name;
      Service s(type, d, e);
      airline.findPlane(idP)->addService(s);
      cout << "Service was added to plane " << idP << "\n";
      return;
   }
   cout << "Invalid service type.\n";
   return;
}

void App::serviceNext()
{
   if (command.empty())
   {
      cout << "Invalid command. Try help to check available commands.\n";
      return;
   }
   string idP = command.front();
   command.pop();
   if (!command.empty())
   {
      cout << "Invalid command.\n";
      return;
   }
   transform(idP.begin(), idP.end(), idP.begin(), ::toupper);
   if (!airline.checkPlane(idP)) {
      cout << "Plane " << idP << " doesn't exist. Try plane display to check existing planes.\n";
      return;
   }
   airline.findPlane(idP)->getNextService();
   cout << "Service was marked as completed. And was removed from the queue.\n";
}