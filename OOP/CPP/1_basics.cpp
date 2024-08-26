#include <iostream>
using namespace std;

class Animal
{
public:
  void makeSound() { cout << "Some sound"; }
};

int main()
{
  Animal dog;
  dog.makeSound();
  return 0;
}