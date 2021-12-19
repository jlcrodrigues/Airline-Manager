#ifndef BAGGAGE_H
#define BAGGAGE_H

using namespace std;

class Baggage
{
   public:
      /**Baggage's default constructor.**/
      Baggage() = default;

      /**
       * Constructor for cart.

       * @param weight - The baggage's weight.
       */
       Baggage(const double& weight);

       /**
        * Get the weight of the baggage.
        * @return - Returns an int with the weight of the baggage.
        */
       int getWeight() const;

   private:
      double weight;
};

#endif