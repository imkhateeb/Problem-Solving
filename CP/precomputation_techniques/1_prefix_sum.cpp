#include <iostream>
#define MOD 1000000007
#define ll long long
#define N 1000001
using namespace std;
int arr[N];
long long prefix_sum[N];
/*
Constraints
1 <= N <= 10^5
1 <= A[i] <= 10^9
1 <= Q <= 10^5
1 <= L, R <= N
*/

/*
Time complexity: O(N) + O(Q) = 10 ^ 5 + 10 ^ 5 = 2 * 10 ^ 5
*/

int main()
{
  int n;
  cin >> n;
  for (int i = 1; i <= n; i++)
  {
    cin >> arr[i];
    prefix_sum[i] = prefix_sum[i - 1] + arr[i];
  }

  int q;
  cin >> q;
  while (q--)
  {
    int l, r;
    cin >> l >> r;
    cout << prefix_sum[r] - prefix_sum[l - 1] << endl;
  }
  return 0;
}