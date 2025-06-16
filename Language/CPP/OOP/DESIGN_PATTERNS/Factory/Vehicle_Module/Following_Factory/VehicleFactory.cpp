#include "VehicleFactory.hpp"

Vehicle *VehicleFactory::getVehicle(string vehicalType)
{
  if (vehicalType == "Car")
  {
    return new Car();
  }
  else if (vehicalType == "Bike")
  {
    return new Bike();
  }
  else if (vehicalType == "Truck")
  {
    return new Truck();
  }
  else
  {
    cout << "Invalid vehical type" << endl;
    cout << "Enter either Car or Bike" << endl;
    cout << "Exiting..." << endl;
    return nullptr;
  }
}
