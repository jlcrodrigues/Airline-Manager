#include "Airline.h"

Airline::Airline()
{
   flights_file = "../data/flights.csv";
   passengers_file = "../data/passengers.csv";
   planes_file = "../data/planes.csv";
}

Airline::Airline(const string& airports, const string &flights, const string &passengers, const string &planes)
{
   airports_file = airports;
   flights_file = flights;
   passengers_file = passengers;
   planes_file = planes;
   loadAirports(airports_file);
   loadFlights(flights_file);
   loadPassengers(passengers_file);
   loadPlanes(planes_file);
}

vector<Airport> Airline::getAirports() const
{
   return airports;
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

bool Airline::loadAirports(const string &file_name)
{
   airports_file = file_name;
   string line;
   vector<string> line_contents;
   ifstream file(airports_file);
   if (!file.is_open()) return false;
   while(getline(file, line))
   {
      line_contents = readLine(line);
      airports.push_back(Airport(line_contents[0]));
   }
   file.close();
   return true;
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
   file.close();
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
   file.close();
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
   file.close();
   return true;
}

bool Airline::addAirport(const Airport &airport)
{
   if (isIn(airports, airport)) return false;
   airports.push_back(airport);
   insertionSort(airports);
   saveFile(airports, airports_file);
   return true;
}

bool Airline::addFlight(const Flight& flight)
{
   if (isIn(flights, flight)) return false;
   flights.push_back(flight);
   insertionSort(flights);
   saveFile(flights, flights_file);
   return true;
}

bool Airline::addPassenger(const Passenger &passenger)
{
   if (isIn(passengers, passenger)) return false;
   passengers.push_back(passenger);
   insertionSort(passengers);
   saveFile(passengers, passengers_file);
   return true;
}

bool Airline::addPlane(const Plane &plane)
{
   if (isIn(planes, plane)) return false;
   planes.push_back(plane);
   insertionSort(planes);
   saveFile(planes, planes_file);
   return true;
}

template<typename T>
void Airline::insertionSort(vector<T>& v)
{
   for (int i = 1; i < v.size(); i++)
   {
      T tmp = v[i];
      int j;
      for (j = i; j > 0 && tmp < v[j - 1]; j--)
         v[j] = v[j - 1];
      v[j] = tmp;
   }
}

template<typename T>
bool Airline::isIn(const vector<T>& v, const T& t)
{
   int left = 0, right = v.size() - 1;
   while (left <= right)
   {
      int mid = (left + right) / 2;
      if (v[mid] < t) left = mid + 1;
      else if (t < v[mid]) right = mid - 1;
      else return true;
   }
   return false;
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

template<typename T>
void Airline::saveFile(const vector<T>& values, const string& file_name) const
{
   ofstream file(file_name);
   for (auto & row: values)
   {
      file << row.getCsv();
   }
   file.close();
}