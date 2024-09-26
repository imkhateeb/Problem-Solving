#include <iostream>
#include <string>
using namespace std;

class Car
{
private:
  string brand;
  string model;
  int year;

public:
  // Constructor
  Car(string b, string m, int y) : brand(b), model(m), year(y) {}

  // Default Constructor
  Car() : brand("Unknown"), model("Unknown"), year(0) {}

  // Methods
  void displayInfo()
  {
    cout << year << " " << brand << " " << model << endl;
  }

  void accelerate()
  {
    cout << "The " << brand << " " << model << " is accelerating!" << endl;
  }

  // Getter methods
  string getBrand() { return brand; }
  string getModel() { return model; }
  int getYear() { return year; }

  // Setter Mehtods
  void setBrand(string b) { brand = b; }
  void setModel(string m) { model = m; }
  void setYear(int y) { year = y; }
};

int main()
{
  // STATIC ALLOCATION
  // Creating objects
  Car car1("Toyota", "Corolla", 2020);
  Car car2("Tesla", "Model 3", 2021);

  // Using object methods
  car1.displayInfo();
  car2.accelerate();

  // Accessing object data through getter methods
  cout << "Car 1 is a " << car1.getBrand() << endl;
  cout << "Car 2 is a " << car2.getYear() << " model" << endl;

  // DYNAMIC ALLOCATION
  Car *car3 = new Car;
  car3->setBrand("Tata");
  car3->setModel("Nano");
  car3->setYear(2019);

  (*car3).displayInfo();
  car3->accelerate();

  cout << "Size of car1: " << sizeof(car1) << endl;
  cout << "Size of car2: " << sizeof(car2) << endl;
  cout << "Size of car3: " << sizeof(*car3) << endl;

  return 0;
}