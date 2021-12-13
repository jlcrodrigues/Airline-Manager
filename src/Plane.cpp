#include "Plane.h"

using namespace std;

Plane::Plane() : capacity(0)
{

}

Plane::Plane(const string& id, const int&capacity): id(id), capacity(capacity)
{

}

string Plane::getCsv() const
{
   string csv = "";
   csv += id + ',';
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

list<Flight> Plane::getFlights() {
    return flights;
}

queue<Service> Plane::getServices() {
    return services;
}

vector<Service> Plane::getOldServices() {
    return old_services;
}
