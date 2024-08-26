#include <iostream>
#include <string>

using namespace std;

class Animal
{
private:
  int age;

protected:
  string name;

public:
  Animal(int age, string name)
  {
    this->age = age;
    this->name = name;
  }

  // setter function
  void setAge(int age)
  {
    age = age;
  }

  // getter function
  int getAge()
  {
    return age;
  }

  // member functions
  void introduce()
  {
    cout << "I am " << name << " and I am " << age << " years old." << endl;
  }
};

class Dog : public Animal
{
public:
  Dog(int age, string name) : Animal(age, name)
  {
    cout << "Dog constructor called" << endl;
  }

  void bark()
  {
    cout << "Woof! Woof!" << endl;
  }
};

int main()
{
  Animal animal(10, "Generic Animal");
  animal.introduce();
}