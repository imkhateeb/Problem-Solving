#include <bits/stdc++.h>

#define ll long long
#define pb push_back

using namespace std;

vector<int> generatePrimes(int n, vector <int> &v)
{
  vector<bool> isPrime(n + 1, true);
  vector<int> primes;

  for (int p = 2; p * p <= n; ++p)
  {
    if (isPrime[p])
    {
      for (int i = p * p; i <= n; i += p)
        isPrime[i] = false;
    }
  }

  for (int p = 2; p <= n; ++p)
  {
    if (isPrime[p])
      primes.push_back(p);
  }
  return primes;
}

int main()
{
  int t;
  cin >> t;

  while (t--)
  {

    // My code
    int x, q;
    cin >> x >> q;
    vector<int> factors;
    generatePrimes(x, factors);

    int ans = 0;
    int mini
  }

  return 0;
}