#ifndef APP_H
#define APP_H

#include "Airline.h"

#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <algorithm>
#include <iomanip>

using namespace std;

class App
{
   public:
      App();
      App(const string& airports, const string& flights, const string& passengers, const string& planes, const string& carts);

      void run();
   private:
      Airline airline;
      queue<string> command;
      bool app_run;
      int ITEMS_PER_PAGE;

      /**Clears the cin buffer.**/
      void clearStream() const;

      /**
       * Checks it user input is a integer.
       * @param n - Value to store integer value of string.
       * @param s - String to convert to interger.
       * @return - Returns true if it's possible to convert string to integer. False otherwise.
       */
      bool readNumber(int& n, const string& s) const;

      bool readDate(Date &date, const string s) const;

      bool readDuration(Date &date, const string s) const;

      bool readTime(Date &date, const string s) const;

      bool invalidAirportOrigin(string &aO);

      bool invalidAirportDestination(string &aD);

      void invalidDepartureDate(Date &date, string &s) const;

      void invalidDepartureTime(Date &date, string &s) const;

      void invalidDuration(Date &date, string &s) const;

      bool invalidPlane(string &id) const;

      /**
       * Finds the maximum for each field in a table.
       * @param table - A 2d vector of strings.
       * @return - Returns a vector with the width for each column of the table.
       */
      vector<int> findLength(const vector<vector<string> >& table) const;

      /**
       * Outputs a table from a 2d string vector.
       * @param table - A 2d string vector. The first element is the header.
       * @param page - The page to be displayed (user input).
       */
      void displayTable(vector<vector<string> > table, int page) const;


      bool getOption();

      /**Reads a command from cin stream and stores it word by word in the command queue.**/
      void readCommand();

      /**Processes the command and calls the right actions.**/
      void processCommand();

      /**Processes the rest of the command if the first word was help.**/
      void help();

      /**Outputs a small presentation of the program.**/
      void helpTutorial();

      /**Outputs some command options to manage the tool.**/
      void helpGeneral();

      /**Outputs a series of options for airport operations.**/
      void helpAirport();

      /**Outputs a series of options for cart operations.**/
      void helpCart();

      /**Outputs a series of options for flight operations.**/
      void helpFlight();

      /**Outputs a series of options for passenger operations.**/
      void helpPassenger();

      /**Outputs a series of options for plane operations.**/
      void helpPlane();

      /**Outputs a series of options for ticket operations.**/
      void helpTicket();

      /**See the list of alias.**/
      void alias();

      /**Resize the display windows.**/
      void resize();

      /**
       * Handles the airport commands.
       */
      void airport();

      /**Handles the cart commands.**/
      void cart();

      /**
       * Handles the flight commands.
       */
      void flight();

      /**
       * Handles the passenger commands.
       */
      void passenger();
      /**
* Handles the plane commands.
*/
      void plane();

    /**Handles the ticket commands.**/
      void ticket();

    /**Handles ticket buying.**/
      void buyTicket();

    /**
     * Quits the program
     */
      void quit();

      /**
       * Adds a new airport to the airline.
      **/
      void addAirport();

      /**Adds a cart to the airline.**/
      void addCart();

     /**
      * Adds a new flight to the airline.
      */
      void addFlight();

      /**Adds a new passenger to the airline.**/
      void addPassenger();

      /**
       * Adds a new plane to the airline.
       */
      void addPlane();

      /**
       * Displays the airline's airports.
      **/
      void displayAirport();

      /**
      * Displays the airline's flights.
      */
      void displayFlight();

      void partialDisplayFlight();

      /**Displays the airline's carts.**/
      void displayCart();

      void serviceDisplay();
      void serviceDisplayO();
      /**Displays the airline's passengers.**/
      void displayPassenger();

      /**
       * Displays the airline's planes.
       */
      void displayPlane();

      void displayTicket();

      void displayTicketFlight();

      void displayTicketPassenger();

      /**
      * Edits the details for an existing airport.
      **/
      void editAirport();

      /**
       * Edits the details for an existing flight.
       */
      void editFlight();

      /**Edit an existing cart**/
      void editCart();

      /**Edits the details for an existing passenger.**/
      void editPassenger();

      /**
       * Edits the details for an existing plane.
       */
      void editPlane();

      /**
      * Removes an existing airport.
      **/
      void removeAirport();

      /**
       * Removes an existing flight.
       */
      void removeFlight();

      /**Removes an existing cart.**/
      void removeCart();

      /**Removes an existing passenger.**/
      void removePassenger();

      /**
       * Removes an existing plane.
       */
      void removePlane();

      /**
       * Locates an airport.
      **/
      void findAirport();

      /**Find a cart using id.**/
      void findCart();

      /**
       * Locates a flight.
       */
      void findFlight();

      /**Locates a passenger.**/
      void findPassenger();

      /**Find passengers by name.**/
      void searchPassenger();

      /**
       * Locates a flight.
       */
      void findPlane();

      /**
       * Changes the flight displaying order.
       */
      void sortFlight();

      /**Changes the passenger displaying order.**/
      void sortPassenger();

      /**
       * Changes the plane displaying order.
       */
      void sortPlane();

      void checkIn();

      void assignCart();
      void flyFlight();

      /**
       * Function to attribute a plane to a flight.
       */
      void flightPlane();

      /**
       * Function to display plane's flight history.
       */
      void historyPlane();
      void servicePlane();
      void serviceAdd();
      void serviceNext();
};


#endif //FEUP_AED_APP_H
