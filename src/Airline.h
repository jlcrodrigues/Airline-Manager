#ifndef AIRLINE_H
#define AIRLINE_H

#include "Airport.h"
#include "Baggage.h"
#include "Cart.h"
#include "Flight.h"
#include "Passenger.h"
#include "Plane.h"
#include "Service.h"
#include "Ticket.h"

#include <vector>
#include <string>
#include <fstream>
#include <sstream>

using namespace std;

class Airline
{
   public:
      /**Airline's default constructor. Sets the file names to default values but does not load any data.**/
      Airline();

      /**
       * This constructor sets the file names and loads the data.
       * @param airports - The name of the file containing airports.
       * @param flights - The name of the file containing flights.
       * @param passengers - The name of the file containing passengers.
       * @param planes - The of the file containing planes.
       */
      Airline(const string& airports, const string& flights, const string& passengers, const string& planes);

      /**
       * Getter for the airports vector.
       * @return - Returns a vector containing all the airline's airport.
       */
      vector<Airport> getAirports() const;

      /**
       * Getter for the flight vector.
       * @return - Returns a vector containing all the airline's flights.
       */
      vector<Flight> getFlights() const;

      /**
       * Getter for the passengers vector.
       * @return - Returns a vector containing all the airline's passengers.
       */
      vector<Passenger> getPassengers() const;

      /**
       * Getter for the planes vector.
       * @return - Returns a vector containing all the airline's planes.
       */
      vector<Plane> getPlanes() const;

      /**
       * Fills the airports vector with airports from a file.
       * @param file_name - The name of the file containing the airports.
       * @return - Returns false if the file doens't exist and true otherwise.
       */
      bool loadAirports(const string& file_name);

      /**
       * Fills the flights vector with flights from a file.
       * @param file_name - The name of the file containing the flights.
       * @return - Returns false if the file doesn't exist and true otherwise.
       */
      bool loadFlights(const string& file_name);

      /**
       * Fills the passengers vector with passengers from a file.
       * @param file_name - The name of the file containing the passengers.
       * @return - Returns false if the file doesn't exist and true otherwise.
       */
      bool loadPassengers(const string& file_name);

      /**
       * Fills the planes vector with planes from a file.
       * @param file_name - The name of the file containing the planes.
       * @return - Returns false if the file doesn't exist and true otherwise.
       */
      bool loadPlanes(const string& file_name);

      /**
       * Adds an airport to the list.
       * @param airport - The airport to be added.
       * @return - Returns false if the airport already exists, true otherwise.
       */
      bool addAirport(const Airport& airport);

      /**
       * Adds a flight to the list.
       * @param flight - The Flight to be added.
       * @return - Returns false if the flight already exists, true otherwise.
       */
      bool addFlight(const Flight& flight);

      /**
       * Adds a passenger to the list.
       * @param passenger - The passenger to be added.
       * @return - Return false if the passenger already exists, true otherwise.
       */
      bool addPassenger(const Passenger& passenger);

      /**
       * Adds a plane to the list.
       * @param plane - The plane to be added.
       * @return - Return false if the plane already exists, true otherwise.
       */
      bool addPlane(const Plane& plane);

   private:
      /**
       * Sorts a vector using the Insertion Sort algorithm.
       * @tparam T - Any object with a < operator implemented.
       * @param v - The vector to be sorted.
       */
      template<typename T>
      void insertionSort(vector<T>& v);

      /**
       * Finds if a certain object is part of a vector.
       * @tparam T - Any object with a < operator implemented.
       * @param v - The vector to be searched.
       * @param t - The object to be found.
       * @return - Returns true if the object is in the vector and false otherwise.
       */
      template<typename T>
      bool isIn(const vector<T>& v, const T& t);

      /**
       * Turns a line from a csv file into a vector<string> containing all columns.
       * @param line - A string of the line to be read.
       * @return - Returns a vector containing a string for each column.
       */
      vector<string> readLine(const string& line) const;

      /**
       * Writes a member-vector into a file.
       * @tparam T - Type t needs to have a getCsv() method implemented;
       * @param values - The vector to be written.
       * @param file_name - The path of the file to be written.
       */
      template<typename T>
      void saveFile(const vector<T>& values, const string& file_name) const;

      vector<Airport> airports;
      vector<Flight> flights;
      vector<Passenger> passengers;
      vector<Plane> planes;
      string airports_file;
      string flights_file;
      string passengers_file;
      string planes_file;
};

#endif