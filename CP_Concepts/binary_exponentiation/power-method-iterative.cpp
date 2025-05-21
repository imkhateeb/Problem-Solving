#include <iostream>
using namespace std;

#define M 1000000007

// O(logb)

int binExpUsingRecursion(int a, int b)
{
  int ans = 1;

  while (b)
  {
    if (b & 1)
    {
      ans = ans * a;
    }
    a = a * a;
    b >>= 1;
  }

  return ans;
}

int main()
{
  // For 3 ^ 13
  cout << binExpUsingRecursion(2, 15) << endl;

  return 0;
}

/*
We can use MOD here also.

IDEA :)
3 ^ 13 = 3 ^ (1101) -> exponent is converted to binary.
3 ^ 13 = 3^8 * 3^4 * 3^0

Complexity -> O(logb)
*/