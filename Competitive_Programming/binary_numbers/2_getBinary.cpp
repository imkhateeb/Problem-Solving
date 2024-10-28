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
  cout << "Binary of " << number << " is ";
  getBinary(number);
  cout << endl;

  int i = 2;
  
  // check whether ith bit is set or not
  if ( ((1 << i) & number) != 0 ){
    cout << "Bit is set" << endl;
  } else {
    cout << "Bit is not set" << endl;
  }

  return 0;
}
