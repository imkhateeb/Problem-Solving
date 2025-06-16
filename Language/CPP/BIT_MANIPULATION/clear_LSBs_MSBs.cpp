#include <bits/stdc++.h>
using namespace std;

void getBinary(int n)
{
  for (int i = 10; i >= 0; i--)
  {
    cout << ((n >> i) & 1);
  }
}

int main()
{

  /*
    clear all LSB's till ith bit
    For example, if n = 59 (111011), i = 4, then the answer would be 110000.

    To do so we need a mask which has all 1's till ith bit and 0's after that.
    Which is 110000. We will take & of n and mask, then we will get the answer.

    mask = ~((1 << i) - 1)
    -> ~((1 << 4) - 1)
    -> ~(010000 - 1)
    -> ~(001111)
    -> 110000
  */

  int n = 59;
  int i = 4;
  getBinary(n); // 111011
  cout << endl;
  int mask = ~((1 << i) - 1); // 110000
  cout << "After clearing all LSB's till " << i << "th bit, binary of " << n << " is ";
  getBinary(n & mask); // 110000
  cout << endl;

  /*
    clear all MSB's till ith bit
    For example, if n = 59 (111011), i = 3, then the answer would be 001011.

    To do so we need a mask which has all 0's before ith bit and 1's from that.
    Which is 001111. We will take & of n and mask, we will get the answer.

    mask = ((1 << (i+1)) - 1)
    -> ((1 << 4) - 1)
    -> (10000 - 1)
    -> 01111
  */

  i = 3;
  mask = (1 << (i + 1)) - 1;
  cout << "After clearing all MSB's till " << i << "th bit, binary of " << n << " is ";
  getBinary(n & mask);
  cout << endl;
  return 0;
}