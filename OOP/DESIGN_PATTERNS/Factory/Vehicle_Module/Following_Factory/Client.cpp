#include <iostream>

#include "VehicleFactory.hpp"

using namespace std;

int main()
{

  string vehicalType;
  cout << "Enter the vehical type: ";
  cin >> vehicalType;

  Vehicle *vehicle = nullptr;

  vehicle = VehicleFactory::getVehicle(vehicalType);

  if (!vehicle)
  {
    return 1;
  }
  else
  {
    vehicle->create();
    vehicle->start();
    vehicle->stop();
  }

  return 0;
}