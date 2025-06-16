#include <iostream>

using namespace std;

class CopyAssignment
{
public:
  int health;
  char level;

  void getHealth()
  {
    cout << "Health is: " << health << endl;
  }

  void getLevel()
  {
    cout << "Level is: " << level << endl;
  }
};

int main()
{

  CopyAssignment ca1;
  ca1.health = 80;
  ca1.level = 'A';

  CopyAssignment ca2 = ca1; // all values of ca1 will be assigned to ca2

  cout << "Health of ca2 is: " << ca2.health << endl;
  cout << "Level of ca2 is: " << ca2.level << endl;
}