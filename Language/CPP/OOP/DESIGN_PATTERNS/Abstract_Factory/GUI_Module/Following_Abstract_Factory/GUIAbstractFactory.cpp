#include <iostream>
using namespace std;
#include "GUIFactory.cpp"

class GUIAbstractFactory
{
public:
  static IFactory *getFactory(string factoryType)
  {
    if (factoryType == "Windows")
    {
      return new WindowsFactory();
    }
    else if (factoryType == "Mac")
    {
      return new MacFactory();
    }
    else
    {
      return nullptr;
    }
  }
};