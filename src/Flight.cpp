#include "Flight.h"

using namespace std;

string Flight::sorting_rule = "departure"; //number, departure, duration, capacity

Flight::Flight(const int &number, const Date &departureDate, const Date &departureTime, const Date &duration, const Airport &origin, const Airport &destination, const int& capacity)
{
   this->occupation = capacity;
   this->number = number;
   this->departureDate = departureDate;
   this->departureTime = departureTime;
   this->duration = duration;
   this->origin = origin;
   this->destination = destination;
   this->capacity = capacity;
}

string Flight::getCsv() const
{
   string csv = "";
   csv += to_string(number) + ',';
   csv += departureDate.toString(departureDate) + ',';
   csv += departureTime.toString(departureTime) + ',';
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

Date Flight::getDepartureDate() const
{
   return departureDate;
}

Date Flight::getDepartureTime() const {
    return departureTime;
}

Date Flight::getDuration() const
{
   return duration;
}

Airport Flight::getAirportOrigin() const
{
    return origin;
}

Airport Flight::getAirportDestination() const
{
    return destination;
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

bool Flight::operator<(const Flight &f) const
{
   if (sorting_rule == "number")
   {
      if (number == f.getNumber()) return departureDate < f.getDepartureDate();
      else return number < f.getNumber();
   }
   else if (sorting_rule == "departure")
   {
      if (departureDate == f.getDepartureDate()) return departureTime < f.getDepartureTime();
      return departureDate < f.getDepartureDate();
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

