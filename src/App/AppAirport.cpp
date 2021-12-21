#include "App.h"

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
   else if (command.front() == "find")
   {
      command.pop();
      findAirport();
   }
   else if (command.front() == "remove")
   {
      command.pop();
      removeAirport();
   }
   else cout << "Invalid command. Use help airport to get more info.\n";
}

void App::displayAirport()
{
   int page;
   vector<Airport> airports = airline.getAirports();
   if (airports.size() == 0)
   {
      cout << "No airports to display.\n";
      return;
   }
   vector<vector<string> > table;
   table.push_back({"Name", "Number of Transports"});
   if (command.empty()) page = 0;
   else if (!readNumber(page, command.front()))
   {
      cout << "Page must be a number. Please try again.\n";
      return;
   }
   for (auto & a: airports) table.push_back({a.getName(), to_string(a.getTransports().size())});
   displayTable(table, page);
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
   transform(name.begin(),name.end(),name.begin(),::toupper);
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

void App::editAirport()
{
   if (command.empty())
   {
      cout << "Usage:\n  airport edit name 'nameAirport'\n  airport edit transport add 'nameAirport'\n";
      return;
   }
   else if(command.front()=="name")
   {
      command.pop();
      string aname = command.front();
      transform(aname.begin(),aname.end(),aname.begin(),::toupper);
      command.pop();
      if (!airline.checkAirport(aname))
      {
         cout << "That airport doesn't exist. Maybe you want to try:\n  airport add 'nameAirport'\n";
         return;
      }
      Airport a = *airline.findAirport(aname);
      string name;
      cout << "Name: "; cin >> name; clearStream();
      airline.removeAirport(aname);
      a.setName(name);
      airline.addAirport(a);
      cout << "Airport " << name << " was updated.\n";
   }
   else if(command.front()=="transport")
   {
      command.pop();
      if(command.front()=="add")
      {
         command.pop();
         string aname = command.front();
         transform(aname.begin(),aname.end(),aname.begin(),::toupper);
         command.pop();
         if (!airline.checkAirport(aname))
         {
            cout << "That airport doesn't exist. Maybe you want to try:\n  airport add 'nameAirport'\n";
            return;
         }
         Airport a = *airline.findAirport(aname);
         Transport t;
         string distance, times;
         int i;
         cout << "Type: "; cin >> t.type; clearStream();
         do
         {
            cout << "Distance: "; cin >> distance; clearStream();
         } while (!readNumber(t.distance, distance)) ;
         do
         {
            cout << "Number of times: "; cin >> times ; clearStream();
         } while (!readNumber(i, times)) ;
         int n = i;
         vector<Date> v;
         while (i>0)
         {
            string date;
            cout << "Time " << n-i+1 << ": "; cin >> date; clearStream();
            Date d;
            if(!readTime(d,date))
            {
               cout << "Invalid Format. Try HH:MM\n";
               continue;
            }
            v.push_back(d);
            i--;
         }
         t.time = v;
         airline.removeAirport(aname);
         a.addTransport(t);
         airline.addAirport(a);
         cout << "Airport " << aname << " was updated.\n";
      }
      else
      {
         cout << "Usage:\n  airport edit transport add 'nameAirport'\n";
      }
   }
   else
   {
      cout << "Usage:\n  airport edit name 'nameAirport'\n  airport edit transport add 'nameAirport'\n";
   }
}

void App::removeAirport()
{
   string name;
   if (command.empty())
   {
      cout << "Usage:\n  airport remove 'nameAirport'\n";
      return;
   }
   name = command.front();
   transform(name.begin(),name.end(),name.begin(),::toupper);
   if (airline.removeAirport(name))
   {
      cout << "Airport " << name << " was removed.\n";
   }
   else cout << "That Airport doesn't exist.\n";
}

void App::findAirport()
{
   int page;
   string name;
   if (command.empty())
   {
      cout << "Usage:\n  - airport find 'nameAirport'\n";
      return;
   }
   name = command.front();
   command.pop();
   transform(name.begin(),name.end(),name.begin(),::toupper);
   if (airline.checkAirport(name))
   {
      Airport* a = airline.findAirport(name);
      if (command.empty()) page = 0;
      else if (!readNumber(page, command.front()))
      {
         cout << "Page must be a number. Please try again.\n";
         return;
      }
      cout << "Name: " << a->getName() << " \nNumber of Transports: " << a->getTransports().size() << " \n";
      if(a->getTransports().size()!=0) {
         cout << "Closest Transport: " << a->findClosest().type << " at " << a->findClosest().distance << " kilometers" << "\n";
         vector<vector<string> > table;
         table.push_back({"Type", "Distance", "First time", "Last time"});
         for (auto b: a->getTransports() ) table.push_back({b.type, to_string(b.distance), b.time.begin()->displayTime(), (b.time.end()-1)->displayTime()});
         displayTable(table, page);
      }
   }
   else cout << "Airport not found.\n";
}