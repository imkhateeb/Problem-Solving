#include <iostream>
#define MOD 1000000007
#define ll long long
#define N 1001
using namespace std;
long long prefix_sum[N][N];
/*
Constraints
1 <= N <= 10^3
1 <= A[i][j] <= 10^9
1 <= Q <= 10^5
1 <= L, R <= N
*/

/*
Time complexity: O(N*N) + O(Q*N*N) = 10 ^ 5 * 10 ^ 6 = 10 ^ 11
*/

int main()
{
  int n;
  cin >> n;
  int num;
  for (int i = 0; i <= n; i++)
  {
    for (int j = 0; j <= n; j++)
    {
      if (i == 0 || j == 0)
      {
        prefix_sum[i][j] = 0;
      }
      else
      {
        cin >> num;
        prefix_sum[i][j] = prefix_sum[i - 1][j] + prefix_sum[i][j - 1] - prefix_sum[i - 1][j - 1] + num;
      }
    }
  }

  int q;
  cin >> q;
  while (q--)
  {
    int a, b, c, d;
    cin >> a >> b >> c >> d;
    long long sum = 0;
    sum = prefix_sum[c][d] - prefix_sum[a - 1][d] - prefix_sum[c][b - 1] + prefix_sum[a - 1][b - 1];
    cout << sum << endl;
  }
  return 0;
}