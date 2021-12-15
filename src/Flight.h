#ifndef FLIGHT_H
#define FLIGHT_H

#include "Airport.h"
#include "Cart.h"
#include "Date.h"

#include <queue>

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
      Flight(const int &number, const Date &departure, const Date &duration, const Airport &origin, const Airport &destination, const int& capacity);

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
      Date getDeparture() const;

      /**
       * Getter for the flight's duration.
       * @return - Returns the duration of the flight.
       */
      Date getDuration() const;

      /**
       * Getter for capacity.
       * @return - Returns the capacity of the flight.
       */
      int getCapacity() const;

      /**
         *If there's one available, fills a seat.

         *@return - True if the ticket was bought, false otherwise.
      **/
      bool buyTicket(const int& amount = 1);

      /**
       * Adds a new baggage cart to the flight.

       * @param cart - The cart you want to add.

       * @return Returns true if the cart was added, false otherwise.
       */
      bool addCart(const Cart& cart);

      /**
       * Inserts a new bag to the cart.

       * @param bag The bag to be inserted.
       * @return Returns true if the bag was properly inserted.
       */
      bool insertBaggage(const Baggage& bag);

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
      Date departure;
      Date duration;
      Airport origin;
      Airport destination;
      queue<Cart> carts;
};

#endif