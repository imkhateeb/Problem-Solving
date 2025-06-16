#ifndef vehicle_hpp
#define vehicle_hpp

class Vehicle
{
public:
  virtual void create() = 0;
  virtual void start() = 0;
  virtual void stop() = 0;
};

/**
 * TO CREATE A MODULE FOR VEHICLE
 * 1. COMPILE ALL THE MODULES
 * g++ -c Vehicle.cpp Car.cpp Bike.cpp VehicleFactory.cpp

 * 2. CREATE A STATIC LIBRARY
 * ar ru libvehicle.a Car.o Bike.o VehicleFactory.o

 * 3. CREATE A CLIENT
 * 4. COMPILE THE CLIENT
 * g++ -o smartClient client.cpp libvehicle.a

  * 5. RUN THE CLIENT
 */

#endif