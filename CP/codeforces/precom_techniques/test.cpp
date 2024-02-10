#include <bits/stdc++.h>
#define MOD 1000000007
using namespace std;

const int N = 1e7 + 10;
long long freq_array[N] = {0};

// Constraints
// 1 <= N <= 10^5
// 1 <= Q <= 10^5
// 1 <= A[i] <= 10^7

int main()
{
  int n;
  cin >> n;

  int num;
  for (int i = 0; i < n; i++)
  {
    cin >> num;
    freq_array[num]++;
  }

  int q;
  cin >> q;
  while (q--)
  {
    int x;
    cin >> x;
    cout << freq_array[x] << endl;
  }

  return 0;
}