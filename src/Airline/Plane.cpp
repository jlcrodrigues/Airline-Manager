#include "Plane.h"

using namespace std;

string Plane::sorting_rule; //id, model, capacity

Plane::Plane(const string& id, const string model, const int&capacity)
{
    this->id = id;
    this->model = model;
    this->capacity = capacity;
}

string Plane::getCsv() const
{
   string csv = "";
   csv += id + ',';
   csv += model + ',';
   csv += to_string(capacity) + '\n';
   return csv;
}

int Plane::getCapacity() const
{
   return capacity;
}

void Plane::addService(const Service &service)
{
    services.push(service);
}

Service Plane::getNextService() {
    Service s = services.front();
    old_services.push_back(services.front());
    services.pop();
    return s;

}

void Plane::addFlight(const Flight &flight) {
    flights.push_back(flight);
}

void Plane::removeFlight(const Flight &flight)
{
    list<Flight>::iterator it;
    for (it = flights.begin(); it != flights.end(); it++)
    {
        if (*it == flight)
        {
            flights.erase(it);
        }
    }
}

list<Flight> Plane::getFlights() {
    return flights;
}

queue<Service> Plane::getServices() {
    return services;
}

string Plane::getId() const
{
   return id;
}

string Plane::getModel() const
{
   return model;
}

vector<Service> Plane::getOldServices() {
    return old_services;
}

bool Plane::operator < (const Plane &p) const
{
   if (sorting_rule == "id")
   {
      if (id == p.getId()) return capacity < p.getCapacity();
      return id < p.getId();
   }
   if (sorting_rule == "model")
   {
      if (model == p.getModel()) return id < p.getId();
      return model < p.getModel();
   }
   if (sorting_rule == "capacity") {
      if (capacity == p.getCapacity()) return id < p.getId();
      return capacity < p.getCapacity();
   }
   throw (invalid_argument("That rule does not exist."));
   return false;
}

