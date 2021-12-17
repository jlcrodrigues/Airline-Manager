#ifndef EXCEPTION_H
#define EXCEPTION_H

class PassengerNotFound
{
   string message;
public:
   PassengerNotFound(const string& message): message(message) {}
};

#endif
