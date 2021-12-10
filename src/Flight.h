#ifndef FLIGHT_H
#define FLIGHT_H

#include "Airport.h"
#include "Cart.h"

#include <queue>

class Flight
{
   public:

      /**Flight's default constructor.**/
      Flight() = default;

      /**
         *Constructor for Ticket.

         *@param capacity - The capacity for this flight.
      **/
      Flight(const int &number, const string &departure, const string &duration, const Airport &origin, const Airport &destination, const int& capacity);

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

   private:
      int capacity;
      int occupation;
      int number;
      string departure;
      string duration;
      Airport origin;
      Airport destination;
      queue<Cart> carts;
};

#endif