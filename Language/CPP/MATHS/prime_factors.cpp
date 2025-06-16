#include <iostream>
#include <vector>
using namespace std;

int main()
{

  int n;
  cin >> n;

  vector<int> prime_factors;

  int iterations = 0;

  for (int i = 2; i <= n; i++)
  {
    if (n % i == 0)
    {
      while (n % i == 0)
      {
        prime_factors.push_back(i);
        n /= i;
        iterations++;
      }
    }
    else
    {
      iterations++;
    }
  }

  cout << "Iterations: " << iterations << endl;

  cout << "Prime factors: ";

  for (int i = 0; i < prime_factors.size(); i++)
  {
    cout << prime_factors[i] << " ";
  }
  cout << endl;
  return 0;
}