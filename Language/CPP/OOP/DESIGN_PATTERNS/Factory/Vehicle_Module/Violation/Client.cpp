#include <iostream>

#include "Car.hpp"
#include "Bike.hpp"

using namespace std;

int main()
{

  string vehicalType;
  cout << "Enter the vehical type: ";
  cin >> vehicalType;

  Vehicle *vehicle = nullptr;

  if (vehicalType == "Car")
  {
    vehicle = new Car();
    vehicle->create();
    vehicle->start();
    vehicle->stop();
  }
  else if (vehicalType == "Bike")
  {
    vehicle = new Bike();
    vehicle->create();
    vehicle->start();
    vehicle->stop();
  }
  else
  {
    cout << "Invalid vehical type" << endl;
    cout << "Enter either Car or Bike" << endl;
    cout << "Exiting..." << endl;
    return 1;
  }

  return 0;
}