#ifndef APP_H
#define APP_H

#include "../src/Airline/Airline.h"

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
      /**App default constructor.**/
      App();

      /**
       * App construct with custom files.
       * @param airports - The name of the file containing airports.
       * @param flights - The name of the file containing flights.
       * @param passengers - The name of the file containing passengers.
       * @param planes - The name of the file containing planes.
       * @param carts - The name of the file containing carts.
       */
      App(const string& airports, const string& flights, const string& passengers, const string& planes, const string& carts);

      /**Links the app together. From reading to processing the commands.**/
      void run();
   private:
      Airline airline;
      queue<string> command;
      bool app_run;
      int ITEMS_PER_PAGE;

      ///////////////////////// Utility /////////////////////////

      /**Clears the cin buffer.**/
      void clearStream() const;

      /**
       * Checks it user input is a integer.
       * @param n - Value to store integer value of string.
       * @param s - String to convert to interger.
       * @return - Returns true if it's possible to convert string to integer. False otherwise.
       */
      bool readNumber(int& n, const string& s) const;

      /**
       * Checks if user input is a valid date.
       * @param date - date to store date value of string
       * @param s - string to convert to date
       * @return - Returns true if it's possible to convert string to date. False otherwise.
       */
      bool readDate(Date &date, const string s) const;

    /**
     * Checks if user input is a valid duration.
     * @param date - date to store duration value of string
     * @param s - string to convert to duration
     * @return - Returns true if it's possible to convert string to duration. False otherwise.
     */
      bool readDuration(Date &date, const string s) const;

    /**
     * Checks if user input is a valid time.
     * @param date - date to store time value of string
     * @param s - string to convert to time
     * @return - Returns true if it's possible to convert string to time. False otherwise.
     */
      bool readTime(Date &date, const string s) const;

      /**
       * Function to call when user input is an invalid origin airport. Infinite loop that breaks when input is valid or user wants to go to menu.
       * @param aO - string of origin airport id
       * @return - Returns true if origin airport is valid. False when user inputs 'menu'
       */
      bool invalidAirportOrigin(string &aO);

    /**
     * Function to call when user input is an invalid destination airport. Infinite loop that breaks when input is valid or user wants to go to menu.
     * @param aO - string of destination airport id
     * @return - Returns true if destination airport is valid. False when user inputs 'menu'
     */
      bool invalidAirportDestination(string &aD);

      /**
       * Function to call when user input is an invalid departure date. Infinite loop that breaks when input is valid.
       * @param date - date to attribute the values of user input
       * @param s - string to store user input
       */
      void invalidDepartureDate(Date &date, string &s) const;

    /**
     * Function to call when user input is an invalid departure time. Infinite loop that breaks when input is valid.
     * @param date - date to attribute the values of user input
     * @param s - string to store user input
     */
      void invalidDepartureTime(Date &date, string &s) const;

    /**
     * Function to call when user input is an invalid duration. Infinite loop that breaks when input is valid.
     * @param date - date to attribute the values of user input
     * @param s - string to store user input
     */
      void invalidDuration(Date &date, string &s) const;

      /**
       * Function to call when input is an invalid plane. Infinite loop that breaks when input is valid or user wants to go back to menu.
       * @param id - string to store user input
       * @return - Returns true if id plane input is valid. False when user input is 'menu'
       */
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

      /**Reads a yes or no answer.**/
      bool getOption();

      /**Reads a command from cin stream and stores it word by word in the command queue.**/
      void readCommand();

      /**Processes the command and calls the right actions.**/
      void processCommand();

       ///////////////////////// Help /////////////////////////

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

       ///////////////////////// General /////////////////////////

      /**See the list of alias.**/
      void alias();

      /**Resize the display windows.**/
      void resize();

      /**Quits the program**/
      void quit();

      ///////////////////////// Airport /////////////////////////

      /**Handles the airport commands.*/
      void airport();

      /**Displays the airline's airports.**/
      void displayAirport();

      /**Displays the airline's airports.**/
      void addAirport();

      /**Edits the details for an existing airport.**/
      void editAirport();

      /**Removes an existing airport.**/
      void removeAirport();

      /**Locates an airport.**/
      void findAirport();

      ///////////////////////// Cart /////////////////////////

      /**Handles the cart commands.**/
      void cart();

      /**Displays the airline's carts.**/
      void displayCart();

      /**Adds a cart to the airline.**/
      void addCart();

      /**Edit an existing cart**/
      void editCart();

      /**Removes an existing cart.**/
      void removeCart();

      /**Find a cart using id.**/
      void findCart();

      /**Assign a cart to a flight.**/
      void assignCart();

       ///////////////////////// Flight /////////////////////////

      /**Handles the flight commands.*/
      void flight();

      /**Displays the airline's flights.*/
      void displayFlight();

       /**Displays the airline's flights between a time frame.*/
      void partialDisplayFlight();

      /**Adds a new flight to the airline.**/
      void addFlight();

      /**Edits the details for an existing flight.**/
      void editFlight();

      /**Removes an existing flight.**/
      void removeFlight();

      /**Locates a flight.**/
      void findFlight();

      /**Changes the flight displaying order.**/
      void sortFlight();

      /**Make a flight take off.**/
      void flyFlight();

      /**Function to attribute a plane to a flight.**/
      void flightPlane();

       ///////////////////////// Passenger /////////////////////////

      /**Handles the passenger commands.**/
      void passenger();

      /**Displays the airline's passengers.**/
      void displayPassenger();

      /**Adds a new passenger to the airline.**/
      void addPassenger();

      /**Edits the details for an existing passenger.**/
      void editPassenger();

      /**Removes an existing passenger.**/
      void removePassenger();

      /**Locates a passenger.**/
      void findPassenger();

      /**Find passengers by name.**/
      void searchPassenger();

      /**Changes the passenger displaying order.**/
      void sortPassenger();

      /**Check in a passenger into a flight.**/
      void checkIn();

      ///////////////////////// Plane /////////////////////////

      /**Handles the plane commands.**/
      void plane();

      /**Displays the airline's planes.**/
      void displayPlane();

      /**Adds a new plane to the airline.**/
      void addPlane();

      /**Edits the details for an existing plane.**/
      void editPlane();

      /**Removes an existing plane.**/
      void removePlane();

      /**Locates a flight.**/
      void findPlane();

      /**Changes the plane displaying order.**/
      void sortPlane();

      /**Displays plane's future services.**/
      void serviceDisplay();

      /**Displays plane's completed services.**/
      void serviceDisplayO();

      /**Function to display plane's flight history.**/
      void historyPlane();

      /**
       * Handles the plane services commands.*
       */
      void servicePlane();

      /**
       * Adds a new service to a plane.*
       */
      void serviceAdd();

      /**
       * Marks next service in queue as completed, removes it and adds to old services vector.*
       */
      void serviceNext();

      ///////////////////////// Ticket /////////////////////////

      /**Handles the ticket commands.**/
      void ticket();

      /**Manages the ticket displaying options.**/
      void displayTicket();

      /**Displays the tickets purchase for a flight.**/
      void displayTicketFlight();

      /**Displays tickets owned by a passenger.**/
      void displayTicketPassenger();

      /**Handles ticket buying.**/
      void buyTicket();

};


#endif //FEUP_AED_APP_H
