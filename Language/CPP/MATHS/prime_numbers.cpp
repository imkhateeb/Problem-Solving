#include <iostream>
#include <vector>
using namespace std;

const int N = 1e7 + 10;

vector<bool> isPrime(N, 1);

// isPrime[i] -> is i a prime or a non-prime

int main()
{

  isPrime[0] = isPrime[1] = false;

  for (int i = 2; i < N; i++)
  {
    if (isPrime[i] == true)
    {
      for (int j = 2 * i; j < N; j += i)
      {
        isPrime[j] = false;
      }
    }
  }

  for (int i = 0; i <= 100; i++)
  {
    cout << i << ": ";
    if (isPrime[i])
    {
      cout << "Prime" << endl;
    }
    else
    {
      cout << "Not Prime" << endl;
    }
  }
  return 0;
}