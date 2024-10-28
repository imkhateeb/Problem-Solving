#ifndef vehiclefactory_hpp
#include <iostream>

#include "Car.hpp"
#include "Bike.hpp"
#include "Truck.hpp"

using namespace std;

class VehicleFactory
{
public:
  static Vehicle *getVehicle(string vehicalType);
};

#endif