#include <iostream>

using namespace std;

#define M 1000000007

/**
a <= 10^18
b <= 10^9
M <= 10^18
 */

// O((logb) ^ b)

long long binaryMultiply(long long a, long long b)
{
  long long ans = 0;

  while (b)
  {
    if (b & 1)
    {
      ans = (ans + a) % M;
    }
    a = (a + a) % M;
    b >>= 1;
  }

  return ans;
}

long long binaryExponentiation(long long a, long long b)
{
  long long ans = 1;

  while (b)
  {
    if (b & 1)
    {
      ans = binaryMultiply(ans, a);
    }
    a = binaryMultiply(a, a);
    b >>= 1;
  }

  return ans;
}

int main()
{
  long long a, b;
  cin >> a >> b;

  cout << binaryExponentiation(a, b) << endl;

  return 0;
}