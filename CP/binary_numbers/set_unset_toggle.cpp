#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
using namespace std;

void getBinary(int n){
  for ( int i = 10; i >= 0; i-- ){
    cout << ((n >> i) & 1);
  }
}

int main()
{
  int number = 9;
  cout << "Binary of " << number << " is" << endl;
  getBinary(number);
  cout << endl;

  // set 2nd bit
  number = number | (1 << 2);
  cout << "After setting 2nd bit, binary of " << number << " is" << endl;
  getBinary(number);
  cout << endl;

  // unset 3rd bit
  number = number & ~(1 << 3);
  cout << "After unsetting 3rd bit, binary of " << number << " is" << endl;
  getBinary(number);
  cout << endl;

  // toggle 4th bit
  number = number ^ (1 << 4);
  cout << "After toggling 4th bit, binary of " << number << " is" << endl;
  getBinary(number);
  cout << endl;

  // toggle 1st bit
  number = number ^ (1 << 0);
  cout << "After toggling 1st bit, binary of " << number << " is" << endl;
  getBinary(number);
  cout << endl;

  return 0;
}
