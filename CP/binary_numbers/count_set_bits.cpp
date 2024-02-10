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
  int number = 13;
  cout << "Binary of " << number << " is" << endl;
  getBinary(number); // 00000001101
  cout << endl;

  int count = 0;
  while ( number > 0 ){
    count += (number & 1);
    number >>= 1;
  }

  cout << "Number of set bits are " << count << endl; // 3

	// Built in function to count set bits
	cout << "Number of set bits are " << __builtin_popcount(15) << endl;

  return 0;
}