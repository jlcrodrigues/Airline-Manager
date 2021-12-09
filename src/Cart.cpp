#include "Cart.h"

Cart::Cart()
{
   n_stacks = 0; bags_per_stack = 0;
}

Cart::Cart(const int& carriages, const int& piles , const int& bags)
{
   n_stacks = carriages * piles;
   bags_per_stack = bags;
}

bool Cart::insert(const Baggage& bag)
{
   int i = 0;
   for (i; i < contents.size(); i++)
   {
      if (bags_per_stack <= contents[i].size()) continue;
      contents[i].push(bag);
      return true;
   }
   if (i < n_stacks)
   {
      stack<Baggage> temp;
      temp.push(bag);
      contents.push_back(temp);
      return true;
   }
   return false;
}

bool Cart::isFull() const
{
   if(contents.size() == n_stacks)
   {
      return contents[contents.size() - 1].size() == bags_per_stack;
   }
   return false;
}