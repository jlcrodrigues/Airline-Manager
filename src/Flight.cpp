#include "Flight.h"

using namespace std;

Flight::Flight()
{
   this->capacity = plane.getCapacity();
   this->occupation = capacity;
}

Flight::Flight(const Plane& plane) 
{
   this->capacity = plane.getCapacity();
   this->occupation = capacity;
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