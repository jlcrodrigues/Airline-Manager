#ifndef PLANE_H
#define PLANE_H

#include <string>

using namespace std;

class Plane
{
   public:

      /*Plane's default constructor.*/
      Plane();

      /*
         Constructor for plane.

         @param id - The license number.
         @param capacity - Plane's capacity.
      */
      Plane (const string& id, const int&capacity);

      /*
         Getter for capacity.

         @return - Returns the plane's capacity.
      */
      int getCapacity() const;

   private:

      const string id;
      const int capacity;
};

#endif