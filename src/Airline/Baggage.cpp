#include "Baggage.h"

Baggage::Baggage(const double& weight)
{
   this->weight = weight;
}

int Baggage::getWeight() const
{
   return weight;
}