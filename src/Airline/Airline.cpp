#include "Airline.h"

Airline::Airline()
{
   airports_file = "../data/airports.csv";
   flights_file = "../data/flights.csv";
   passengers_file = "../data/passengers.csv";
   planes_file = "../data/planes.csv";
   carts_file = "../data/carts.csv";
   Flight::sorting_rule = "departure"; //number, departure, duration, capacity
   Passenger::sorting_rule = "name"; //id, name
   Plane::sorting_rule = "id"; //id, model, capacity
   loadAirports(airports_file);
    loadPlanes(planes_file);
   loadFlights(flights_file);
   loadPassengers(passengers_file);
   loadCarts(carts_file);
   assignAllCarts();
}

Airline::Airline(const string& airports, const string &flights, const string &passengers, const string &planes, const string& carts)
{
   airports_file = airports;
   flights_file = flights;
   passengers_file = passengers;
   planes_file = planes;
   carts_file = carts;
   Flight::sorting_rule = "departure"; //number, departure, duration, capacity
   Passenger::sorting_rule = "name"; //id, name
   Plane::sorting_rule = "id"; //id, model, capacity
   loadAirports(airports_file);
    loadPlanes(planes_file);
   loadFlights(flights_file);
   loadPassengers(passengers_file);
   loadCarts(carts_file);
   assignAllCarts();
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

vector<Cart> Airline::getCarts() const
{
   return carts;
}

vector<Passenger> Airline::searchNames(const string& name)
{
   string word;
   set<string> search;
   vector<Passenger> res;
   stringstream s1(name);
   while (getline(s1, word, ' '))
   {
      transform(word.begin(), word.end(), word.begin(), [](unsigned char c){return tolower(c);});
      search.insert(word);
   }
   for (int i = 0; i < passengers.size(); i++)
   {
      vector<string> count;
      stringstream s2(passengers[i].getName());
      set<string> passenger_names;
      while (getline(s2, word, ' '))
      {
         transform(word.begin(), word.end(), word.begin(), [](unsigned char c){return tolower(c);});
         passenger_names.insert(word);
      }
      set_intersection(search.begin(), search.end(), passenger_names.begin(), passenger_names.end(), back_inserter(count));
      if (count.size() == search.size()) res.push_back(passengers[i]);
   }
   return res;
}

vector<PassengerTicket> Airline::getTicketsToFlight(const Flight &flight) const
{
    vector<PassengerTicket> res;
    for (auto & p: passengers)
    {
        if (p.ticketOwned(flight)) res.push_back({p, p.getTicket(flight)});
    }
    return res;
}

bool Airline::checkAirport(const string &name) const
{
   for (auto & a: airports)
   {
      if (a.getName() == name) return true;
   }
   return false;
}

bool Airline::checkFlight(const int& id) const
{
   for (auto & f: flights)
   {
      if (f.getNumber() == id) return true;
   }
   return false;
}

bool Airline::checkPassenger(const int &id) const
{
   for (auto & p : passengers)
   {
      if (p.getId() == id) return true;
   }
   return false;
}

bool Airline::checkPlane(const string &id) const
{
   for (auto & p: planes)
   {
      if (p.getId() == id) return true;
   }
   return false;
}

bool Airline::checkCart(const int& id) const
{
   return findElem(carts, Cart(id, 0, 0, 0)) != -1;
}

Airport* Airline::findAirport(const string &name)
{
   Airport* res;
   for (auto & a: airports)
   {
      if (a.getName() == name)
      {
         res = &a;
         break;
      }
   }
   return res;
}

Flight* Airline::findFlight(const int &id)
{
   Flight* res;
   for (auto & f: flights)
   {
      if (f.getNumber() == id)
      {
         res = &f;
         break;
      }
   }
   return res;
}

Passenger* Airline::findPassenger(const int &id)
{
   Passenger* res;
   for (auto & p: passengers)
   {
      if (p.getId() == id)
      {
         res = &p;
         break;
      }
   }
   return res;
}

Plane* Airline::findPlane(const string &id)
{
   Plane* res;
   for (auto & p: planes)
   {
      if (p.getId() == id)
      {
         res = &p;
         break;
      }
   }
   return res;
}

Cart* Airline::findCart(const int &id)
{
   Cart* cart;
   int i = findElem(carts, Cart(id, 0, 0, 0));
   if (i != -1)
   {
      cart = &carts[i];
   }
   return cart;
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
      string name = line_contents[0];
      set<Transport> s;
      Transport t;
      Date d;
      for(int i=1; i < line_contents.size(); i++){
         vector<Date> v;
         t.type = line_contents[i];
         t.distance = stoi(line_contents[i+1]);
         i+=2;
         while (i<line_contents.size() &&  readDate(line_contents[i], d))
         {
            v.push_back(d);
            i++;
         }
         i--;
         t.time = v;
         s.insert(t);
      }
      airports.push_back(Airport(line_contents[0], s));
   }
   file.close();
   sort(airports.begin(), airports.end());
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
      for (int i = 2; i < line_contents.size(); i++)
      {
         Flight* flight = findFlight(stoi(line_contents[i]));
         bool baggage = false;
         if (line_contents[++i] == "1") baggage = true;
         Ticket ticket(*flight, baggage);
         if (line_contents[++i] == "1") ticket.checkIn();
         passengers[passengers.size() - 1].addTicket(ticket);
      }
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
        flights.back().setPlane(line_contents[7]);
        if (checkPlane(line_contents[7])) findPlane(line_contents[7])->addFlight(flights.back());
    }
    file.close();
    sort(flights.begin(), flights.end());
    return true;
}

bool Airline::loadCarts(const string &file_name)
{
   carts_file = file_name;
   string line;
   vector<string> line_contents;
   ifstream file(carts_file);
   if (!file.is_open()) return false;
   while (getline(file, line))
   {
      line_contents = readLine(line);
      int cart_id = stoi(line_contents[0]);
      int flight_id = stoi(line_contents[4]);
      Cart cart(cart_id, stoi(line_contents[1]), stoi(line_contents[2]), stoi(line_contents[3]));
      cart.setFlight(flight_id);
      Flight* flight = findFlight(flight_id);
      flight->addCart(cart_id);
      for (int i = 5; i < line_contents.size(); i++)
      {
         cart.insert(Baggage(stoi(line_contents[i])));
      }
      carts.push_back(cart);
   }
   file.close();
   sort(carts.begin(), carts.end());
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
//   if (findElem(flights, flight) != -1) return false;
   flights.push_back(flight);
   insertionSort(flights);
   saveFile(flights, flights_file);
   return true;
}

bool Airline::addPassenger(const Passenger &passenger)
{
   //if (findElem(passengers, passenger) != -1) return false;
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

bool Airline::addCart(const Cart& cart)
{
   if (findElem(carts, cart) != -1) return false;
   carts.push_back(cart);
   insertionSort(carts);
   saveFile(carts, carts_file);
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

bool Airline::removeAirport(const string& name)
{
   vector<Airport>::iterator i = airports.begin();
   for (; i != airports.end(); i++)
   {
      if (i->getName() == name) {
         i = airports.erase(i);
         saveFile(airports, airports_file);
         return true;
      }
   }
   return false;
}

bool Airline::removeCart(const int &id)
{
   int i = findElem(carts, Cart(id, 0, 0, 0));
   if (i == -1) return false;
   carts.erase(carts.begin() + i);
   saveFile(carts, carts_file);
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

bool Airline::removeFlight(const int& id)
{
   vector<Flight>::iterator i = flights.begin();
   for (; i != flights.end(); i++)
   {
      if (i->getNumber() == id) {
         i = flights.erase(i);
         saveFile(flights, flights_file);
         return true;
      }
   }
   return false;
}

bool Airline::removePassenger(const Passenger& passenger)
{
   int i = findElem(passengers, passenger);
   if (i == -1) return false;
   passengers.erase(passengers.begin() + i);
   saveFile(passengers, passengers_file);
   return true;
}

bool Airline::removePassenger(const int& id)
{
   vector<Passenger>::iterator i = passengers.begin();
   for (; i != passengers.end(); i++)
   {
      if (i->getId() == id) {
         i = passengers.erase(i);
         saveFile(passengers, passengers_file);
         return true;
      }
   }
   return false;
}

bool Airline::removePlane(const Plane &plane)
{
   int i = findElem(planes, plane);
   if (i == -1) return false;
   planes.erase(planes.begin() + i);
   saveFile(planes, planes_file);
   return true;
}

bool Airline::removePlane(const string& id)
{
   vector<Plane>::iterator i = planes.begin();
   for (; i != planes.end(); i++)
   {
      if (i->getId() == id) {
         i = planes.erase(i);
         saveFile(planes, planes_file);
         return true;
      }
   }
   return false;
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

string Airline::getDateString(string date) const{
    stringstream ss(date), ss2;
    string s;
    int c = 0;
    while(getline(ss, date, '/')){
        c += 1;
        if (c == 3) ss2 << setfill('0') << setw(4) << date;
        else  ss2 << setfill('0') << setw(2) << date;
    }
    ss2 >> s;
    return s;
}

string Airline::getTimeString(string date) const{
    stringstream ss(date), ss2;
    string s;
    while(getline(ss, date, ':')){
        ss2 << setfill('0') << setw(2) << date;
    }
    ss2 >> s;
    return s;
}

bool Airline::readDate(const string &dateString, Date &date)
{
   if(dateString.find(':')==dateString.npos)
   {
      return false;
   }
   date.setHour(stoi(getTimeString(dateString).substr(0,2)));
   date.setMinute(stoi(getTimeString(dateString).substr(2)));
   return true;
}

bool Airline::buyTicket(Flight *flight, vector<GroupMember> group)
{
   bool r = passengers[0].buyTicket(flight, group);
   saveFile(passengers, passengers_file);
   return r;
}

void Airline::assignAllCarts()
{
   for (auto & cart: carts)
   {
      int id = cart.getFlight();
      Flight* flight = findFlight(id);
      flight->addCart(id);
   }
}

void Airline::assignCartFlight(const int &id, const int &flight_id)
{
   int i = findElem(carts, Cart(id, 0, 0, 0));
   carts[i].setFlight(flight_id);
   Flight* flight = findFlight(flight_id);
   flight->addCart(carts[i].getId());
   saveFile(carts, carts_file);
}

bool Airline::insertBaggage(const int& flight_id, const Baggage &bag)
{
   Flight* flight = findFlight(flight_id);
   set<int> flight_carts = flight->getCarts();
   set<int>::iterator it = flight_carts.begin();
   for (; it != flight_carts.end(); it++)
   {
      Cart* cart = findCart(*it);
      if (cart->insert(bag))
      {
         saveFile(carts, carts_file);
         return true;
      }
   }
   return false;
}

bool Airline::checkIn(const int &flight_id, const int &passenger_id)
{
   Flight* flight = findFlight(flight_id);
   Passenger* passenger = findPassenger(passenger_id);
   passenger->checkIn(*flight);
   saveFile(passengers, passengers_file);
   return true;
}

bool Airline::checkIn(const int &flight_id, const int &passenger_id, const double& bag)
{
   if (!insertBaggage(flight_id, bag)) return false;
   checkIn(flight_id, passenger_id);
   saveFile(carts, carts_file);
   return true;
}

int Airline::getCheckedIn(const int& flight_id)
{
   int res = 0;
   for (int i = 0; i < passengers.size(); i++)
   {
      Flight* flight = findFlight(flight_id);
      if (passengers[i].getTicket(*flight).hasCheckedIn()) res++;
   }
   return res;
}

int Airline::flyFlight(const int& flight_id)
{
   int n_passengers = 0;
   for (int i = 0; i < carts.size(); i++)
   {
      if (carts[i].getFlight() == flight_id)
      {
         carts[i].clear();
         carts[i].setFlight(0);
      }
   }
   for (int i = 0; i < passengers.size(); i++)
   {
      if (passengers[i].removeTicket(flight_id)) n_passengers++;
   }
   vector<Flight>::iterator it = flights.begin();
   for (; it != flights.end(); it++)
   {
      if (it->getNumber() == flight_id)
      {
         flights.erase(it);
         break;
      }
   }
   saveFile(passengers, passengers_file);
   saveFile(flights, flights_file);
   saveFile(carts, carts_file);
   return n_passengers;
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
int Airline::findElem(const vector<T>& v, const T& t) const
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