#include <bits/stdc++.h>
using namespace std;

/*
Que →
Starting with a 1 indexed array of zeroes and a list of operations, for each operation add a value to each the array element (say c) between two given(say a(a >= 0), b(b < n))( b >= a) indices, inclusive. Once all operations have been performed return the maximum value of the array.

Constraints →
1 ≤ T ≤ 10^2
1 ≤ N ≤ 2*10^5
1 ≤ Q ≤ 10^7
1 ≤ c ≤ 10^9
*/

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, q;
    cin >> n >> q;

    vector<int> d(n, 0);
    while (q--)
    {
      int a, b, c;
      cin >> a >> b >> c;
      d[a] += c;
      d[b + 1] -= c;
    }

    long long prefix_sum[n];
    prefix_sum[0] = d[0];
    for (int i = 1; i < n; i++)
    {
      prefix_sum[i] = prefix_sum[i - 1] + d[i];
    }

    long long maxi = *max_element(prefix_sum, prefix_sum + n);
    cout << maxi << endl;
  }
  return 0;
}