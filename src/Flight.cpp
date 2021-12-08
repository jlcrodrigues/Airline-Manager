#include "Flight.h"


using namespace std;

Flight::Flight()
{
   this->capacity = plane.getCapacity();
   this->occupation = capacity;
}

Flight::Flight(const Plane &plane, const int &number, const string &departure, const string &duration, const Aeroport &origin, const Aeroport &destination)
{
   this->capacity = plane.getCapacity();
   this->occupation = capacity;
   this->number = number;
   this->departure = departure;
   this->duration = duration;
   this->origin = origin;
   this->destination = destination;
}

int Flight::getOccupation() const
{
   return occupation;
}

bool Flight::buyTicket(const int& amount)
{
   if (0 <= occupation - amount)
   {
      occupation -= amount;
      return true;
   }
   return false;

}