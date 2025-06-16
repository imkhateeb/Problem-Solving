#ifndef bike_hpp
#define bike_hpp

#include "Vehicle.hpp"

class Bike : public Vehicle
{
public:
  void create();
  void start();
  void stop();
};

#endif