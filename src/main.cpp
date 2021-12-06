#include <iostream>

#include "Flight.h"
#include "Passenger.h"

using namespace std;

int main()
{
   Plane plane = Plane("A310", 310);
   Flight flight = Flight(plane);
   Passenger pa = Passenger("Carlos");
   cout << flight.getOccupation() << endl;
   pa.buyTicket(flight);
   cout << "Ticket bought." << endl;
   cout << flight.getOccupation() << endl;
   return 0;
}