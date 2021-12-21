/*#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Airline/Airline.h"

using testing::Eq;

Flight getFlight()
{
   Airport airport1;
   Airport airport2;
   return Flight(3, Date(11, 2, 2020), Date(16,0), Date(2,0), airport1, airport2, 100);
}

Plane getPlane()
{
   return Plane("83598", "A310", 310);
}

TEST(passenger, buyTicket)
{
   Plane plane = getPlane();
   Flight flight = getFlight();
   Flight flight_full(4, Date(4,4,2010), Date(3,20), Date(2,30), Airport(), Airport(), 1);
   Passenger pa = Passenger(12341234, "Carlos");
   Passenger pa1 = Passenger(24525, "Manuel");
   Passenger pa2 = Passenger(123412, "Maria");
   Passenger pa3 = Passenger(324234, "Pedro");
   vector<struct GroupMember> group = {{pa1, false}, {pa2, true}};

   //Buying a single ticket
   pa.buyTicket(flight);
   EXPECT_EQ(flight.getOccupation(), 99);
   EXPECT_EQ(pa.getTickets().size(), 1);

   //Buying a ticket to a full flight
   pa.buyTicket(flight_full);
   EXPECT_FALSE(pa1.buyTicket(flight_full));

   //Buying a group ticket
   pa1.buyTicket(flight, group);
   EXPECT_EQ(flight.getOccupation(), 97);
   EXPECT_EQ(pa1.getTickets().size(), 1);
   EXPECT_EQ(pa2.getTickets().size(), 1);

   //Buying 2 tickets to the same flight
   EXPECT_FALSE(pa.buyTicket(flight));
   vector<struct GroupMember> group2 = {{pa3, false}, {pa, true}};
   EXPECT_FALSE(pa3.buyTicket(flight, group2));

}

TEST(passenger, checkIn)
{
   Flight flight = getFlight();
   Passenger pa1 = Passenger(23, "Maria");
   Passenger pa2 = Passenger(234, "Carlos");
   pa1.buyTicket(flight, true);
   pa2.buyTicket(flight, false);

   EXPECT_THROW(pa1.checkIn(flight), invalid_argument);
   //EXPECT_TRUE(pa1.checkIn(flight, 10)); not working atm
   //EXPECT_THROW(pa2.checkIn(flight, 10), invalid_argument);
   //EXPECT_TRUE(pa2.checkIn(flight));
}
*/