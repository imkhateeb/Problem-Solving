#include <iostream>
using namespace std;

#include "GUIAbstractFactory.cpp"

int main()
{

  string factoryType;
  cout << "Enter the factory type: ";
  cin >> factoryType;

  IFactory *factory = GUIAbstractFactory::getFactory(factoryType);

  if (!factory)
  {
    cout << "Invalid factory type" << endl;
    return 1;
  }
  else
  {
    IButton *button = factory->createButton();
    ITextBox *textBox = factory->createTextBox();

    button->press();
    textBox->write();
  }
  return 0;
}