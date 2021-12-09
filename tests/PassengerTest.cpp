#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Airline.h"

using testing::Eq;

TEST(passenger, buyTicket)
{
   Airport airport1;
   Airport airport2;
   Plane plane = Plane("A310", 310);
   Flight flight = Flight(3, "9/12/2021", "3h24", airport1, airport2, 100);
   Passenger pa = Passenger("Carlos");
   Passenger pa1 = Passenger("Manuel");
   Passenger pa2 = Passenger("Maria");
   Passenger pa3 = Passenger("Pedro");
   vector<struct GroupMember> group = {{pa1, false}, {pa2, true}};

   //Buying a single ticket
   pa.buyTicket(flight);
   EXPECT_EQ(flight.getOccupation(), 99);
   EXPECT_EQ(pa.g(), 1);

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
