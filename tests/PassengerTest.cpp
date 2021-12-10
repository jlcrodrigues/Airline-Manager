#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Airline.h"

using testing::Eq;

Flight getFlight()
{
   Airport airport1;
   Airport airport2;
   return Flight(3, "9/12/2021", "3h24", airport1, airport2, 100);
}

Plane getPlane()
{
   return Plane("A310", 310);
}

TEST(passenger, buyTicket)
{
   Plane plane = getPlane();
   Flight flight = getFlight();
   Flight flight_full(4, "9/12/2021", "3h24", Airport(), Airport(), 1);
   Passenger pa = Passenger("Carlos");
   Passenger pa1 = Passenger("Manuel");
   Passenger pa2 = Passenger("Maria");
   Passenger pa3 = Passenger("Pedro");
   vector<struct GroupMember> group = {{pa1, false}, {pa2, true}};

   //Buying a single ticket
   pa.buyTicket(flight);
   EXPECT_EQ(flight.getOccupation(), 99);
   EXPECT_EQ(pa.g(), 1);

   //Buying a ticket to a full flight
   pa.buyTicket(flight_full);
   EXPECT_FALSE(pa1.buyTicket(flight_full));

   //Buying a group ticket
   pa1.buyTicket(flight, group);
   EXPECT_EQ(flight.getOccupation(), 97);
   EXPECT_EQ(pa1.g(), 1);
   EXPECT_EQ(pa2.g(), 1);

   //Buying 2 tickets to the same flight
   EXPECT_FALSE(pa.buyTicket(flight));
   vector<struct GroupMember> group2 = {{pa3, false}, {pa, true}};
   EXPECT_FALSE(pa3.buyTicket(flight, group2));

}

TEST(passenger, checkIn)
{
   Flight flight = getFlight();
   Passenger pa1 = Passenger("Maria");
   Passenger pa2 = Passenger("Carlos");
   pa1.buyTicket(flight, true);
   pa2.buyTicket(flight, false);

   EXPECT_THROW(pa1.checkIn(flight), invalid_argument);
   EXPECT_TRUE(pa1.checkIn(flight, 10));
   EXPECT_THROW(pa2.checkIn(flight, 10), invalid_argument);
   EXPECT_TRUE(pa2.checkIn(flight));
}
