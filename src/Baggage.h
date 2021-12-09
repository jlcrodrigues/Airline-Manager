#ifndef BAGGAGE_H
#define BAGGAGE_H

#include "Passenger.h"

class Baggage
{
   public:
      /**Baggage's default constructor.**/
      Baggage() {};

      /**
       * Constructor for cart.

       * @param owner - The passenger who the bag belongs to.
       */
      Baggage(const double& weight);

   private:
   double weight;
};

#endif