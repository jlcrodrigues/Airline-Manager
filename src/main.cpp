#include <iostream>

#include "Flight.h"
#include "Plane.h"
#include "Passenger.h"

using namespace std;

int main()
{
    Aeroport aeroport1;
    Aeroport aeroport2;
   Plane plane = Plane("A310", 310);
   Flight flight = Flight(3, "9/12/2021", "3h24", aeroport1, aeroport2, 100);

   Passenger pa = Passenger("Carlos");
   Passenger pa1 = Passenger("Manuel");
   Passenger pa2 = Passenger("Maria");
   vector<struct GroupMember> group = {{pa, true}, {pa1, false}, {pa2, true}};
   pa.buyTicket(flight, group);
   cout << pa.g() << endl << pa1.g() << endl << pa2.g() << endl;
   cout << flight.getOccupation() << endl;
   pa.buyTicket(flight);
   pa.buyTicket(flight, true);
   cout << "Ticket bought." << endl;
   cout << flight.getOccupation() << endl;
   return 0;
}