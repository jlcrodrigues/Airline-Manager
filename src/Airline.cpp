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
   Flight::sorting_rule = "departure"; //number, departure, duration, capacity
   Passenger::sorting_rule = "name"; //id, name
   Plane::sorting_rule = "id"; //id, model, capacity
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
      airports.push_back(Airport(line_contents[0], set<Transport>()));
   }
   file.close();
   sort(airports.begin(), airports.end());
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
                               Date(stoi(getDateString(line_contents[1]).substr(0,2)), stoi(getDateString(line_contents[1]).substr(2,2)), stoi(getDateString(line_contents[1]).substr(4))),
                               Date(stoi(getTimeString(line_contents[2]).substr(0,2)), stoi(getTimeString(line_contents[2]).substr(2))),
                               Date(stoi(getTimeString(line_contents[3]).substr(0,2)), stoi(getTimeString(line_contents[3]).substr(2))),
                               Airport(line_contents[4], set<Transport>()),
                               Airport(line_contents[5], set<Transport>()),
                               stoi(line_contents[6])));
   }
   file.close();
   sort(flights.begin(), flights.end());
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
   sort(passengers.begin(), passengers.end());
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
                             line_contents[1],
                             stoi(line_contents[2])));
   }
   file.close();
   sort(planes.begin(), planes.end());
   return true;
}

bool Airline::addAirport(const Airport &airport)
{
   if (findElem(airports, airport) != -1) return false;
   airports.push_back(airport);
   insertionSort(airports);
   saveFile(airports, airports_file);
   return true;
}

bool Airline::addFlight(const Flight& flight)
{
   if (findElem(flights, flight) != -1) return false;
   flights.push_back(flight);
   insertionSort(flights);
   saveFile(flights, flights_file);
   return true;
}

bool Airline::addPassenger(const Passenger &passenger)
{
   if (findElem(passengers, passenger) != -1) return false;
   passengers.push_back(passenger);
   insertionSort(passengers);
   saveFile(passengers, passengers_file);
   return true;
}

bool Airline::addPlane(const Plane &plane)
{
   if (findElem(planes, plane) != -1) return false;
   planes.push_back(plane);
   insertionSort(planes);
   saveFile(planes, planes_file);
   return true;
}

bool Airline::removeAirport(const Airport &airport)
{
   int i = findElem(airports, airport);
   if (i == -1) return false;
   airports.erase(airports.begin() + i);
   saveFile(airports, airports_file);
   return true;
}

bool Airline::removeFlight(const Flight &flight)
{
   int i = findElem(flights, flight);
   if (i == -1) return false;
   flights.erase(flights.begin() + i);
   saveFile(flights, flights_file);
   return true;
}

bool Airline::removePassenger(const Passenger& passenger)
{
   int i = findElem(passengers, passenger);
   if (i == -1) return false;
   passengers.erase(passengers.begin() + i);
   saveFile(passengers, passengers_file);
   return true;
}

bool Airline::removePlane(const Plane &plane)
{
   int i = findElem(planes, plane);
   if (i == -1) return false;
   planes.erase(planes.begin() + i);
   saveFile(planes, planes_file);
   return true;
}

bool Airline::updateAirport(const Airport &airport)
{
   if (!removeAirport(airport)) return false;
   addAirport(airport);
   saveFile(airports, airports_file);
   return true;
}

bool Airline::updateFlight(const Flight &flight)
{
   if (!removeFlight(flight)) return false;
   addFlight(flight);
   saveFile(flights, flights_file);
   return true;
}

bool Airline::updatePassenger(const Passenger& passenger)
{
   if(!removePassenger(passenger)) return false;
   addPassenger(passenger);
   saveFile(passengers, passengers_file);
   return true;
}

bool Airline::updatePlane(const Plane &plane)
{
   if (!removePlane(plane)) return false;
   addPlane(plane);
   saveFile(planes, planes_file);
   return true;
}

void Airline::setFlightOrder(const string& rule)
{
   Flight::sorting_rule = rule;
   sort(flights.begin(), flights.end());
   saveFile(flights,flights_file);
}

void Airline::setPassengerOrder(const string &rule)
{
   Passenger::sorting_rule = rule;
   sort(passengers.begin(), passengers.end());
   saveFile(passengers,passengers_file);

}

void Airline::setPlaneOrder(const string& rule)
{
   Plane::sorting_rule = rule;
   sort(planes.begin(), planes.end());
   saveFile(planes,planes_file);

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
int Airline::findElem(const vector<T>& v, const T& t)
{
   int left = 0, right = v.size() - 1;
   while (left <= right)
   {
      int mid = (left + right) / 2;
      if (v[mid] < t) left = mid + 1;
      else if (t < v[mid]) right = mid - 1;
      else return mid;
   }
   return -1;
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

string Airline::getDateString(string date) {
    stringstream ss(date), ss2;
    string s;
    while(getline(ss, date, '/')){
        ss2 << setfill('0') << setw(2) << date;
    }
    ss2 >> s;
    return s;
}

string Airline::getTimeString(string date) {
    stringstream ss(date), ss2;
    string s;
    while(getline(ss, date, ':')){
        ss2 << setfill('0') << setw(2) << date;
    }
    ss2 >> s;
    return s;
}

void Airline::displayAllFlights() {
    cout <<"|||||||    ||          ||    ||||||||    ||    ||    ||||||||    ||||||||\n";
    cout <<"||	       ||          ||    ||          ||    ||       ||       ||      \n";
    cout <<"||         ||          ||    ||          ||    ||       ||       ||      \n";
    cout <<"||||||     ||          ||    ||  ||||    ||||||||       ||       ||||||||\n";
    cout <<"||         ||          ||    ||    ||    ||    ||       ||             ||\n";
    cout <<"||         ||          ||    ||    ||    ||    ||       ||             ||\n";
    cout <<"||		   ||||||||    ||    ||||||||    ||    ||       ||       ||||||||\n";
    cout <<"═════════════════════════════════════════════════════════════════════════\n";
    cout <<"Number  DepartureDate  DepartureTime  Duration  Origin  Destination  Capacity\n";
    for(auto f: flights){
        // acabar
    }
}
