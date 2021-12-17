#ifndef APP_H
#define APP_H

#include "Airline.h"

#include <iostream>
#include <string>
#include <queue>
#include <sstream>
#include <algorithm>

using namespace std;

class App
{
   public:
      App();
      App(const string& airports, const string& flights, const string& passengers, const string& planes);

      void run();
   private:
      Airline airline;
      queue<string> command;
      bool app_run;
      const int ITEMS_PER_PAGE;

      /**Clears the cin buffer.**/
      void clearStream() const;

      bool readNumber(int& n, const string& s) const;

      /**Reads a command from cin stream and stores it word by word in the command queue.**/
      void readCommand();

      /**Processes the command and calls the right actions.**/
      void processCommand();

      /**Processes the rest of the command if the first word was help.**/
      void help();

      /**Outputs a small presentation of the program.**/
      void helpTutorial();

      /**Outputs a series of options for airport operations.**/
      void helpAirport();

      /**Outputs a series of options for flight operations.**/
      void helpFlight();

      /**Outputs a series of options for passenger operations.**/
      void helpPassenger();

      /**Outputs a series of options for plane operations.**/
      void helpPlane();

      void airport();

      void flight();
      /**
       *
       */
      void addFlight();

      /**
       *
       */
      void selectedFlight();

      void passenger();

      /**Adds a new passenger to the airline.**/
      void addPassenger();

      /**Displays the airline's passengers.**/
      void displayPassenger();

      /**Edits the details for an existing passenger.**/
      void editPassenger();

      /**Removes an existing passenger.**/
      void removePassenger();

      /**Locates a passenger.**/
      void findPassenger();

      /**Changes the passenger displaying order.**/
      void sortPassenger();

      void plane();
      void quit();

      bool partialDisplay(string since, string until);
      void partialDisplayAux(Flight f);
};


#endif //FEUP_AED_APP_H
