#ifndef CART_H
#define CART_H

#include "Baggage.h"

#include <string>
#include <vector>
#include <stack>
#include <queue>

using namespace std;

class Cart
{
public:
   /**Cart's default constructor.**/
   Cart() = default;

   /**
      *Constructor for Cart.
      *@param id - The carts id.
      *@param carriages - The number of carriages in the cart.
      *@param piles - The number of piles per carriage.
      *@param bags - The number of bags in a pile.
   **/
   Cart(const int& id, const int& carriages, const int& piles , const int& bags);

   /**
    * Getter for the id.
    * @return - Returns the cart id.
    */
   int getId() const;

   /**
    * Getter for the carriage number.
    * @return - Integer with the amount of carriages.
    */
   int getCarriages() const;

   /**
    * Getter for the pile number.
    * @return - Integer with the number of piles.
    */
   int getPiles() const;

   /**
    * Getter for the size of a pile.
    * @return - Integer with the amount of bags per pile.
    */
   int getPileSize() const;

   /**
    * Getter for the flight id.
    * @return - Integer with the id of the flight the carts assigned.
    */
   int getFlight() const;

   /**
    * Get a string formatted to be written into memory.
    * @return - Returns a string with the cart data separated by commas.
    */
   string getCsv() const;

   /**
    * Get a vector containing all the baggage's in the cart.
    * @return - Returns a vector with all the cart's luggage.
    */
   queue<Baggage> getBags() const;

   /**
    * Get the current occupation of the cart.
    * @return - An integer with the percentage of the cart's occupation.
    */
   int getOccupation() const;

   /**
    * Changes the flight Id.
    * @param id - The id a flight.
    */
   void setFlight(const int& id);

   /**
      *Inserts a bag in the cart if there's enough room.

      *@param bag - The bag to be inserted.

      *@return - Return true if the bag was inserted, false otherwise.
   **/
   bool insert(const Baggage& bag);

   /**
      *Checks if the Carts is at it's maximum capacity.

      *@return - True if the cart is full, false otherwise.
   **/
   bool isFull() const;

   /**Remove every bag in the cart.**/
   void clear();

   /**
    * Less than operator for Cart.
    * @param c - A cart object.
    * @return - Return id < c.id.
    */
   bool operator < (const Cart& c) const;

private:
   int id;
   int flight_id;
   int n_carriages;
   int n_stacks;
   int n_piles;
   int bags_per_stack;
   vector<stack<Baggage> > contents; //this vector should be size n_stacks
};

#endif