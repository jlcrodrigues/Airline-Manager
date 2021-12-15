#include "Flight.h"

using namespace std;

Flight::Flight(const int &number, const Date &departure, const Date &duration, const Airport &origin, const Airport &destination, const int& capacity): capacity(capacity)
{
   this->occupation = capacity;
   this->number = number;
   this->departure = departure;
   this->duration = duration;
   this->origin = origin;
   this->destination = destination;
}

string Flight::getCsv() const
{
   string csv = "";
   csv += to_string(number) + ',';
   csv += departure.toString(departure) + ',';
   csv += duration.toString(duration) + ',';
   csv += origin.getName() + ',';
   csv += destination.getName() + ',';
   csv += to_string(capacity) + '\n';
   return csv;
}

int Flight::getNumber() const
{
   return number;
}

int Flight::getOccupation() const
{
   return occupation;
}

Date Flight::getDeparture() const
{
   return departure;
}

Date Flight::getDuration() const
{
   return duration;
}

int Flight::getCapacity() const
{
   return capacity;
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

bool Flight::operator<(const Flight &f) const
{
   if (sorting_rule == "number")
   {
      if (number == f.getNumber()) return departure < f.getDeparture();
      else return number < f.getNumber();
   }
   else if (sorting_rule == "departure")
   {
      if (departure == f.getDeparture()) return number < f.getNumber();
      return departure < f.getDeparture();
   }
   else if (sorting_rule == "duration")
   {
      if (duration == f.getDuration()) return number < f.getNumber();
      return duration < f.getDuration();
   }
   else if (sorting_rule == "capacity")
   {
      if (capacity == f.getCapacity()) return number < f.getNumber();
      return capacity < f.getCapacity();
   }
   throw (invalid_argument("That rule does not exist."));
   return false;
}

