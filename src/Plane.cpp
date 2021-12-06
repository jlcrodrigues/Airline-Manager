#include "Plane.h"

using namespace std;

Plane::Plane(): capacity(0), id("")
{
}

Plane::Plane(const string& id, const int&capacity): id(id), capacity(capacity)
{

}

int Plane::getCapacity() const
{
   return capacity;
}