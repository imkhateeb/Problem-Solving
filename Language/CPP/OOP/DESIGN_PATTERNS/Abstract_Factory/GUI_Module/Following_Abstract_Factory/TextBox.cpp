#include <iostream>

using namespace std;

class ITextBox
{
public:
  virtual void write() = 0;
};

class WindowsTextBox : public ITextBox
{
public:
  void write()
  {
    cout << "Windows TextBox written" << endl;
  }
};

class MacTextBox : public ITextBox
{
public:
  void write()
  {
    cout << "Mac TextBox written" << endl;
  }
};
