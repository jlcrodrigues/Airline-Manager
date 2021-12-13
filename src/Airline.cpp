#include "Airline.h"

Airline::Airline()
{
   flights_file = "../data/flights.csv";
   passengers_file = "../data/passengers.csv";
   planes_file = "../data/planes.csv";
}

Airline::Airline(const string &flights, const string &passengers, const string &planes)
{
   flights_file = flights;
   passengers_file = passengers;
   planes_file = planes;
   loadFlights(flights_file);
   loadPassengers(passengers_file);
   loadPlanes(planes_file);
}

vector<Flight> Airline::getFlights() const
{
   return flights;
}

vector<Passenger> Airline::getPassengers() const
{
   return passengers;
}

vector<Plane> Airline::getPlanes() const
{
   return planes;
}

bool Airline::loadFlights(const string &file_name)
{
   flights_file = file_name;
   string line;
   vector<string> line_contents;
   ifstream file(flights_file);
   if (!file.is_open()) return false;
   while(getline(file, line))
   {
      line_contents = readLine(line);
      flights.push_back(Flight(stoi(line_contents[0]),
                               line_contents[1],
                               line_contents[2],
                               Airport(line_contents[3]),
                               Airport(line_contents[4]),
                               stoi(line_contents[5])));
   }
   return true;
}

bool Airline::loadPassengers(const string &file_name)
{
   passengers_file = file_name;
   string line;
   vector<string> line_contents;
   ifstream file(passengers_file);
   if (!file.is_open()) return false;
   while(getline(file, line))
   {
      line_contents = readLine(line);
      passengers.push_back(Passenger(stoi(line_contents[0]),
                                     line_contents[1]));
   }
   return true;
}

bool Airline::loadPlanes(const string &file_name)
{
   planes_file = file_name;
   string line;
   vector<string> line_contents;
   ifstream file(planes_file);
   if (!file.is_open()) return false;
   while(getline(file, line))
   {
      line_contents = readLine(line);
      planes.push_back(Plane(line_contents[0],
                             stoi(line_contents[1])));
   }
   return true;
}

vector<string> Airline::readLine(const string& line) const
{
   string col;
   vector<string> row;
   stringstream str(line);

   while (getline(str, col, ','))
   {
      row.push_back(col);
   }
   return row;
}