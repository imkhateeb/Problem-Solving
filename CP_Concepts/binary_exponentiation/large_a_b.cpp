#include <iostream>

using namespace std;

/**
a <= 10^18
b <= 10^9
M <= 10^9
 */

// O(logb)

#define M 1000000007

int binaryExponentiation(long long a, long long b)
{
  long long ans = 1;

  // This will make a < M or in the range of int.(<= 10^9)
  a = a % M;

  while (b)
  {
    if (b & 1)
    {
      ans = (ans * a) % M;
    }
    a = (a * a) % M;
    b >>= 1;
  }

  return ans;
}

int main()
{

  cout << binaryExponentiation(1233409809, 23422) << endl;

  return 0;
}