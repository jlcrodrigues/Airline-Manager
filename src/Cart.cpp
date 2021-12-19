#include "Cart.h"

Cart::Cart(const int& id, const int& carriages, const int& piles , const int& bags)
{
   this->id = id;
   n_carriages = carriages;
   n_piles = piles;
   n_stacks = carriages * piles;
   bags_per_stack = bags;
   flight_id = 0;
}

int Cart::getId() const
{
   return id;
}

string Cart::getCsv() const
{
   string csv;
   csv += to_string(id) + ',' + to_string(n_carriages) + ',';
   csv += to_string(n_piles) + ',' + to_string(bags_per_stack) + ',';
   csv += to_string(flight_id);
   queue<Baggage> bags = getBags();
   while (!bags.empty())
   {
      csv += ',' + to_string(bags.front().getWeight());
   }
}

queue<Baggage> Cart::getBags() const
{
   queue<Baggage> bags;
   vector<stack<Baggage> > temp = contents;
   for (int i = 0; i < temp.size(); i++)
   {
      stack<Baggage> aux;
      while (!temp[i].empty())
      {
         aux.push(temp[i].top());
         temp[i].pop();
      }
      while (!aux.empty())
      {
         bags.push(aux.top());
         aux.pop();
      }
   }
   return bags;
}

void Cart::setFlight(const int& id)
{
   flight_id = id;
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

bool Cart::operator<(const Cart &c) const
{
   return id < c.getId();
}