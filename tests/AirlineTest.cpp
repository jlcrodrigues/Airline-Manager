#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Airline.h"

using testing::Eq;

TEST(airline, reading)
{
   Airline airline;

   EXPECT_FALSE(airline.loadFlights("test.csv"));
   if (airline.loadFlights("../data/flights.csv"))
   {
      vector<Flight> flights = airline.getFlights();
      EXPECT_EQ(flights.size(), 1);
      EXPECT_EQ(flights[0].getNumber(), 1);
   }

   EXPECT_FALSE(airline.loadPassengers("test.csv"));
   if (airline.loadPassengers("..data/flights.csv"))
   {
      vector<Passenger> passengers = airline.getPassengers();
      EXPECT_EQ(passengers.size(), 1);
      EXPECT_EQ(passengers[0].getId(), 1);
   }

   EXPECT_FALSE(airline.loadPlanes("test.csv"));
   if (airline.loadPlanes("..data/flights.csv"))
   {
      vector<Plane> planes = airline.getPlanes();
      EXPECT_EQ(planes.size(), 1);
      EXPECT_EQ(planes[0].getCapacity(), 100);
   }
}
