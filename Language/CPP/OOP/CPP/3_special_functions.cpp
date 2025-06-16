#include <iostream>
#include <string>
using namespace std;

class Person
{
private:
  string name;
  int age;

public:
  // Constructor
  Person(string n, int a) : name(n), age(a)
  {
    cout << "Constructor called for " << name << endl;
  }

  // Default Constructor
  Person()
  {
    this->name = "Unknown";
    this->age = 0;
    cout << "Default Constructor called for " << name << endl;
  }

  Person(string name)
  {
    this->name = name;
    this->age = 0;
    cout << "Single Parameter constructor called with name " << name << endl;
  }

  Person(int age)
  {
    this->age = age;
    this->name = "Unknown";
    cout << "Single Parameter constructor called with age " << age << endl;
  }

  // Destructor
  ~Person()
  {
    cout << "Destructor called for " << name << endl;
  }

  void introduce()
  {
    cout << "Hi, I'm " << name << " and I'm " << age << " years old." << endl;
  }

  // Setters
  void setName(string newName)
  {
    name = newName;
  }
  void setAge(int newAge)
  {
    age = newAge;
  }

  // Getters
  string getName()
  {
    return name;
  }
  int getAge()
  {
    return age;
  }
};

int main()
{
  {
    Person p1("Alice", 30); // Stack allocation
    p1.introduce();

    Person *p2 = new Person("Bob", 25); // Heap allocation
    p2->introduce();

    Person p3("Charlie"); // Stack allocation
    p3.introduce();

    Person p4(35); // Stack allocation
    p4.introduce();

    Person p5; // Stack allocation
    p5.introduce();

    delete p2; // Manual destruction and deallocation

    // If we will not delete p2, then destructor will not be called

    // p1's destructor will be called automatically here
  }

  // Neither p1 nor p2 exist here
  return 0;
}

/*
If you didn't call delete p2:
 - The destructor for p2 would never be called.
 - The memory allocated for p2 would never be freed, causing a memory leak.
 - Only p1's destructor would be called automatically.
*/
