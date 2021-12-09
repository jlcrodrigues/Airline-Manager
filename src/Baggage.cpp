#include "Baggage.h"

Baggage::Baggage(const Passenger& owner, const double& weight): owner(owner)
{
   this->weight = weight;
}