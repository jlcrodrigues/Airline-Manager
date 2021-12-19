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
#include <algorithm>
#include <functional>

using namespace std;

struct PassengerTicket
{
    Passenger passenger;
    Ticket ticket;
};

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
       * @param planes - The name of the file containing planes.
       * @param carts - The name of the file containing carts.
       */
      Airline(const string& airports, const string& flights, const string& passengers, const string& planes, const string& carts);

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
       * Getter fot the carts vector.
       * @return - Returns a vector containing all the airline's carts.
       */
      vector<Cart> getCarts() const;

      /**
       * Get all the passengers who have a ticket to a flight.
       * @param flight - The flight to be searched.
       * @return - Returns a vector of PassengerTicket.
       */
      vector<PassengerTicket> getTicketsToFlight(const Flight& flight) const;

      /**
       * Looks for the existence of an airport.
       * @param name - The name of the airport to be found.
       * @return - Returns true if hte airport was find and false if it doesn't exist.
       */
      bool checkAirport(const string& name) const;

      /**
       * Looks for the existence of a flight.
       * @param id - The id of the flight to be found.
       * @return - Returns true if the flight was found and false if it doesn't exist- Returns true if the flight was found and false if it doesn't exist
       */
      bool checkFlight(const int& id) const;

      /**
       * Looks for the existence of a passenger.
       * @param id - The id you want to look for.
       * @return - Returns true if the passenger belongs to the airline and false otherwise.
       */
      bool checkPassenger(const int& id) const;

      /**
       * Looks for the existence of a plane.
       * @param id - The id of the plane to be found.
       * @return - Returns true if the plane exists and false otherwise.
       */
      bool checkPlane(const string& id) const;

      /**
       * Looks for the existence of a cart.
       * @param id - The id of the cart to be found.
       * @return - Return true if the cart exists and false otherwise.
       */
      bool checkCart(const int& id) const;

      /**
       * Looks for an airport by name.
       * @param name - The name you want to look for.
       * @return - Returns an existing airport's object.
       */
      Airport* findAirport(const string& name);

      /**
       * Looks for a flight by id.
       * @param id - The id of the flight to be searched.
       * @return - Returns an existing flight's object.
       */
      Flight* findFlight(const int& id);

      /**
       * Looks for a passenger by id.
       * @param id - The id of the passenger to be searched.
       * @return - Returns an existing passenger's object.
       */
      Passenger* findPassenger(const int& id);

      /**
       * Looks for a passenger by id.
       * @param id - The id of the plane to be searched.
       * @return - Returns an existing plane's object.
       */
      Plane* findPlane(const string& id);

      /**
       * Looks for a cart by id.
       * @param id - The id of the cart to be searched.
       * @return - Returns a pointer to a Cart.
       */
      Cart* findCart(const int& id);

      /**
       * Fills the airports vector with airports from a file.
       * @param file_name - The name of the file containing the airports.
       * @return - Returns false if the file doesn't exist and true otherwise.
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
       * Fills the carts vector with carts from a file.
       * @param file_name - The name of the file containing the carts.
       * @return - Returns false if the file doesn't exist and true otherwise.
       */
      bool loadCarts(const string& file_name);

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

      /**
       * Adds a cart to the list.
       * @param cart - The cart to be added.
       * @return - Return false if the cart already exists, false otherwise.
       */
      bool addCart(const Cart& cart);

      /**
       * Removes an existing airport.
       * @param airport - The airport to be removed.
       * @return - Returns false if the airport doesn't exist and true otherwise.
       */
      bool removeAirport(const Airport& airport);

      /**
       * Removes an existing airport.
       * @param name - The name of the airport to be removed.
       * @return - Returns false if the airport doesn't exist and true otherwise.
       */
      bool removeAirport(const string& name);

      /**
       * Removes an existing car by id.
       * @param id - The id of the cart to be removed.
       * @return - Returns true if the operation was successful and false if the cart was not found.
       */
      bool removeCart(const int& id);

      /**
       * Removes an existing flight.
       * @param flight - The flight to be removed.
       * @return - Returns false if the flight doesn't exist and true otherwise.
       */
      bool removeFlight(const Flight& flight);

      /**
       * Removes an existing flight.
       * @param id - The id of the flight to be removed.
       * @return - Returns false if the flight doesn't exist and true otherwise.
       */
      bool removeFlight(const int& id);

      /**
       * Removes an existing passenger.
       * @param passenger - The passenger to be removed.
       * @return - Returns false if the passenger doesn't exist and true otherwise.
       */
      bool removePassenger(const Passenger& passenger);

      /**
       * Removes an existing passenger by id.
       * @param id - The id of the passenger being removed.
       * @return - Returns true if the passenger was remove and false if it doesn't exist.
       */
      bool removePassenger(const int& id);

      /**
       * Removes an existing plane.
       * @param plane - The plane to be removed.
       * @return - Returns false if the plane doesn't exist and true otherwise.
       */
      bool removePlane(const Plane& plane);

      /**
       * Removes an existing plane.
       * @param id - The id of the plane to be removed.
       * @return - Returns false if the plan doesn't exist and true otherwise.
       */
      bool removePlane(const string& id);

      /**
       * Changes an existing airport's value.
       * @param airport - The airport to be updated.
       * @return - Returns false if the airport doesn't exist and true otherwise.
       */
      bool updateAirport(const Airport& airport);

      /**
       * Changes an existing flight's value.
       * @param flight - The flight to be updated.
       * @return - Returns false if the flight doesn't exist and true otherwise.
       */
      bool updateFlight(const Flight& flight);

      /**
       * Changes an existing passenger's value.
       * @param passenger - The passenger to be updated.
       * @return - Returns false if the passenger doesn't exist and true otherwise.
       */
      bool updatePassenger(const Passenger& passenger);

      /**
       * Changes an existing plane's value.
       * @param plane - The plane to be updated.
       * @return - Returns false if the plane doesn't exist and true otherwise.
       */
      bool updatePlane(const Plane& plane);

      /**
       * Re-sorts flights according to a new sorting rule.
       * @param rule - What you want to sort by. Can either be number, departure, duration or capacity.
       */
      void setFlightOrder(const string& rule);

      /**
       * Re-sorts passengers according to a new sorting rule.
       * @param rule - What you want to sort by. Can either be id or number.
       */
      void setPassengerOrder(const string& rule);

      /**
       * Re-sorts planes according to a new sorting rule.
       * @param rule - What you want to sort by. Can either be id, model or capacity.
       */
      void setPlaneOrder(const string& rule);

      /**
       * Displays all of the existing flights.
       */
      void displayAllFlights();

      /**
      * Returns string of date for constructor
      * @param date - date to manipulate
      * @return - Returns date in correct format
      */
      string getDateString(string date) const;

    /**
     * Returns string of time for constructor
     * @param date - time to manipulate
     * @return - Returns time in correct format
     */
      string getTimeString(string date) const;

      /**
       * Checks if string is a possible date and converts it to a date.
       * @param dateString - String with the possible date.
       * @param date - Receives the new date.
       * @return - Returns true if the string is a possible date and false otherwise.
      **/
      bool readData(const string &dateString, Date &date);

      /**
       *
       * @param flight
       * @param group
       * @return
       */
      bool buyTicket(Flight* flight, vector<GroupMember> group);

      /**Assigns the correct carts to each flight**/
      void assignAllCarts();

      /**
       * Assigns a flight to a cart;
       * @param id - The cart id.
       * @param flight_id - The flight id.
       */
      void assignCartFlight(const int& id, const int& flight_id);

      /**
       * Adds a new bag to one of the flight's assigned carts.
       * @param bag - A bag object.
       * @return - Return true if the operation was successful.
       */
      bool insertBaggage(const int& flight_id, const Baggage& bag);

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
      int findElem(const vector<T>& v, const T& t) const;

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
      vector<Cart> carts;
      string airports_file;
      string flights_file;
      string passengers_file;
      string planes_file;
      string carts_file;
};

#endif