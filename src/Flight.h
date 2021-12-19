#ifndef FLIGHT_H
#define FLIGHT_H

#include "Airport.h"
#include "Cart.h"
#include "Date.h"

#include <queue>
#include <set>

class Flight
{
   public:
      static string sorting_rule;

      /**Flight's default constructor.**/
      Flight() = default;

      /**
         *Constructor for Ticket.

         *@param capacity - The capacity for this flight.
      **/
      Flight(const int &number, const Date &departureDate, const Date &departureTime, const Date &duration, const Airport &origin, const Airport &destination, const int& capacity);

      /**
       * Turns the object data into a csv row in order to be used later.
       * @return - Returns a string representing a csv row with the class attributes.
       */
      string getCsv() const;

      /**
       * Getter for number.

       * @return Returns the member number.
       */
      int getNumber() const;

      /**
         *Getter for occupation.

         *@return - The flight's current occupation.
      **/
      int getOccupation() const;

      /**
       * Getter for the departure date.
       * @return Returns the date when the plane takes off.
       */
      Date getDepartureDate() const;

      /**
      * Getter for the departure date.
       * @return Returns the date when the plane takes off.
      */
      Date getDepartureTime() const;

      /**
       * Getter for the flight's duration.
       * @return - Returns the duration of the flight.
       */
      Date getDuration() const;

      /**
       * Getter for origin Airport
       * @return - Returns origin Airport
       */
      Airport getAirportOrigin() const;

      /**
      * Getter for destination Airport
      * @return - Returns destination Airport
      */
      Airport getAirportDestination() const;

      /**
       * Getter for capacity.
       * @return - Returns the capacity of the flight.
       */
      int getCapacity() const;

      /**
       * Getter for the carts set.
       * @return - Returns a set containg assigned carts.
       */
      set<int> getCarts() const;

      /**
       * Adds a new cart to the carts id list.
       * @param id - The id of the cart.
       */
      void addCart(const int& id);

      /**
         *If there's one available, fills a seat.

         *@return - True if the ticket was bought, false otherwise.
      **/
      bool buyTicket(const int& amount = 1);

      /**
       * Flight's < operator.
       * @param f1 - A flight object.
       * @return - Returns true if the flight's number is lower.
       */
      bool operator < (const Flight& f) const;

private:
   int capacity;
      int occupation;
      int number;
      Date departureDate;
      Date departureTime;
      Date duration;
      Airport origin;
      Airport destination;
      set<int> carts;
};

#endif