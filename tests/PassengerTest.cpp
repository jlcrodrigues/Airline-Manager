#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Airline.h"

using testing::Eq;

TEST(passenger, buyTicket)
{
   Aeroport aeroport1;
   Aeroport aeroport2;
   Plane plane = Plane("A310", 310);
   Flight flight = Flight(3, "9/12/2021", "3h24", aeroport1, aeroport2, 100);
   Passenger pa = Passenger("Carlos");
   Passenger pa1 = Passenger("Manuel");
   Passenger pa2 = Passenger("Maria");
   vector<struct GroupMember> group = {{pa, true}, {pa1, false}, {pa2, true}};
   
   pa.buyTicket(flight);
   EXPECT_EQ(flight.getOccupation(), 99);
   pa.buyTicket(flight, group);
   EXPECT_EQ(flight.getOccupation(), 96);

}