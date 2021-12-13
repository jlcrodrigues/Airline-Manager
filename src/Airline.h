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
       * @param flights - The name of the file containing flights.
       * @param passengers - The name of the file containing passengers.
       * @param planes - The name of the file containing planes.
       */
      Airline(const string& flights, const string& passengers, const string& planes);

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
       * @return  - Returns false if the file doesn't exist and true otherwise.
       */
      bool loadPlanes(const string& file_name);

   private:
      bool writeFlights() const;
      bool writePassengers() const;
      bool writePlanes() const;

      /**
       * Turns a line from a csv file into a vector<string> containing all columns.
       * @param line - A string of the line to be read.
       * @return - Returns a vector containing a string for each column.
       */
      vector<string> readLine(const string& line) const;

      vector<Flight> flights;
      vector<Passenger> passengers;
      vector<Plane> planes;
      string flights_file;
      string passengers_file;
      string planes_file;
};

#endif