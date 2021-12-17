#include <gtest/gtest.h>
#include <gmock/gmock.h>
#include "../src/Airline.h"

using testing::Eq;

TEST(airline, reading)
{
   Airline airline;

   EXPECT_FALSE(airline.loadAirports("test.csv"));
   if (airline.loadAirports("..data/airports.csv"))
   {
      vector<Airport> airports = airline.getAirports();
      EXPECT_EQ(airports.size(), 1);
      EXPECT_EQ(airports[0].getName(), "OPO");
   }

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

TEST(airline, insertions)
{
   Airline airline("../data/airports.csv",
           "../data/flights.csv",
           "..data/passengers.csv",
           "..data/planes.csv");

//   EXPECT_TRUE(airline.addAirport(Airport("OPO")));
//   EXPECT_TRUE(airline.addAirport(Airport("JFK")));
   EXPECT_EQ(airline.getAirports().size(), 2);
   EXPECT_FALSE(airline.addAirport(Airport("OPO")));
}

TEST(airline, deletions)
{
   Airline airline("../data/airports.csv",
                   "../data/flights.csv",
                   "..data/passengers.csv",
                   "..data/planes.csv");

   EXPECT_FALSE(airline.removeAirport(Airport("TEST")));
   airline.addAirport(Airport("TEST"));
   EXPECT_TRUE(airline.removeAirport(Airport("TEST")));
}

TEST(airline, updates) {
   Airline airline("../data/airports.csv",
                   "../data/flights.csv",
                   "..data/passengers.csv",
                   "..data/planes.csv");

   EXPECT_FALSE(airline.updateAirport(Airport("TEST")));
   airline.addAirport(Airport("TEST"));
   EXPECT_TRUE(airline.updateAirport(Airport("TEST")));
}

TEST(airline, sorting)
{
   Airline airline("../data/airports.csv",
                   "../data/flights.csv",
                   "..data/passengers.csv",
                   "..data/planes.csv");

   airline.addPassenger(Passenger(12, "Guilherme"));
   airline.addPassenger(Passenger(20, "Barbosa"));

   EXPECT_EQ(airline.getPassengers()[0].getId(), 20);
   airline.setPassengerOrder("id");
   EXPECT_EQ(airline.getPassengers()[0].getId(), 12);
}

TEST(airline, sorting2)
{
    Airline airline("../data/airports.csv",
                    "../data/flights.csv",
                    "..data/passengers.csv",
                    "..data/planes.csv");

    Airport a("BER");
    Airport a2("BUD");
    Date d(4,2,2025);
    Date d2(10,30);
    Date d3(2,15);
//    airline.addFlight(Flight(9,d,d2,d3,a,a2,650));
//    EXPECT_EQ(airline.getFlights()[0].getDepartureDate().getYear(),2020);
//    airline.setFlightOrder("departure");
//    cout << airline.getFlights()[1].getDepartureDate().getYear();
//    EXPECT_EQ(airline.getFlights()[0].getDuration().getHour(), 1);

}