#include "Plane.h"

using namespace std;

Plane::Plane() : capacity(0)
{

}

Plane::Plane(const string& id, const int&capacity): id(id), capacity(capacity)
{

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
    return services.front();
}

void Plane::addFlight(const Flight &flight) {
    flights.push_back(flight);
}
