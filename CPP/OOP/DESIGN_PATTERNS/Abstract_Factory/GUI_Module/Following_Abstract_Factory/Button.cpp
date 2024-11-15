#include <iostream>

using namespace std;

class IButton
{
public:
  virtual void press() = 0;
};

class WindowsButton : public IButton
{
public:
  void press()
  {
    cout << "Windows Button pressed" << endl;
  }
};

class MacButton : public IButton
{
public:
  void press()
  {
    cout << "Mac Button pressed" << endl;
  }
};