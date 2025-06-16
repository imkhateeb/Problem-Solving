#include <bits/stdc++.h>
using namespace std;

fibonacci(int n)
{
  if (n == 0 || n == 1)
    return n;
  int ans = fibonacci(n - 1) + fibonacci(n - 2);

  cout << ans << endl;
  
  return ans;

}

int main()
{
  int n;
  cout << "Enter the number of terms: ";
  cin >> n;

  cout << fibonacci(n) << endl;
  return 0;
}