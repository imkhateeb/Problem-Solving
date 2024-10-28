#ifndef truck_hpp
#define truck_hpp

#include "Vehicle.hpp"

class Truck : public Vehicle
{
public:
  void create();
  void start();
  void stop();
};

#endif