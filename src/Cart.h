#ifndef CART_H
#define CART_H

#include "Baggage.h"

#include <vector>
#include <stack>

using namespace std;

class Cart
{
public:
   /**Cart's default constructor.**/
   Cart() = default;

   /**
      *Constructor for Cart.

      *@param carriages - The number of carriages in the cart.
      *@param piles - The number of piles per carriage.
      *@param bags - The number of bags in a pile.
   **/
   Cart(const int& carriages, const int& piles , const int& bags);

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

private:
   int n_stacks;
   int bags_per_stack;
   vector<stack<Baggage> > contents; //this vector should be size n_stacks
};

#endif