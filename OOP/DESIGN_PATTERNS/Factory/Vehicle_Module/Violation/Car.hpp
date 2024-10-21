#ifndef car_hpp
#define car_hpp

#include "Vehicle.hpp"

class Car : public Vehicle
{
public:
  void create();
  void start();
  void stop();
};

#endif