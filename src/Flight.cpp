#include "Flight.h"

using namespace std;

Flight::Flight(const int &number, const string &departure, const string &duration, const Airport &origin, const Airport &destination, const int& capacity): capacity(capacity)
{
   this->occupation = capacity;
   this->number = number;
   this->departure = departure;
   this->duration = duration;
   this->origin = origin;
   this->destination = destination;
}

int Flight::getNumber() const
{
   return number;
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

bool Flight::addCart(const Cart& cart)
{
   if (carts.empty() || carts.front().isFull())
   {
      carts.push(cart);
      return true;
   }
   return false;
}

bool Flight::insertBaggage(const Baggage& bag)
{
   return carts.front().insert(bag);
}