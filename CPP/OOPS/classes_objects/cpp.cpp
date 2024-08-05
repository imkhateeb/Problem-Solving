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
  Car(string b, string m, int y)
  {
    brand = b;
    model = m;
    year = y;
  };

  // Method
  void displyInfo()
  {
    cout << "Brand: " << brand << endl;
    cout << "Model: " << model << endl;
    cout << "Year: " << year << endl;
  };

  void accelerate()
  {
    cout << brand << " " << model << " Accelerating..." << endl;
  };

  // Getters
  string getBrand()
  {
    return brand;
  };
  string getModel()
  {
    return model;
  };
  int getYear()
  {
    return year;
  };
};

int main()
{
  Car car1("Toyota", "Corolla", 2020);
  Car car2("Tesla", "Model S", 2021);

  // using object methods
  car1.displyInfo();
  car2.accelerate();

  // Accessing using dot operator
  cout << "Year of first car: " << car1.getYear() << endl;

  // using getters
  cout << "Brand of first car: " << car1.getBrand() << endl;
  cout << "Model of second car: " << car2.getModel() << endl;
  return 0;
}