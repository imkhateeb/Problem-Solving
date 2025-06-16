#include <iostream>
using namespace std;

#include "Button.cpp"
#include "TextBox.cpp"

class IFactory
{
public:
  virtual IButton *createButton() = 0;
  virtual ITextBox *createTextBox() = 0;
};

class WindowsFactory : public IFactory
{
public:
  IButton *createButton()
  {
    return new WindowsButton();
  }

  ITextBox *createTextBox()
  {
    return new WindowsTextBox();
  }
};

class MacFactory : public IFactory
{
public:
  IButton *createButton()
  {
    return new MacButton();
  }

  ITextBox *createTextBox()
  {
    return new MacTextBox();
  }
};