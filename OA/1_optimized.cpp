#include <iostream>
#include <vector>
#include <set>
#include <algorithm>

using namespace std;

int main()
{
  int n, q, c;
  cin >> n >> q >> c;

  vector<int> A(n);
  for (int i = 0; i < n; ++i)
  {
    cin >> A[i];
  }

  vector<vector<int>> P(q, vector<int>(c));
  for (int i = 0; i < q; ++i)
  {
    for (int j = 0; j < c; ++j)
    {
      cin >> P[i][j];
    }
  }

  // Precomputation
  vector<int> prefix_distinct(n + 1, 0);
  vector<int> suffix_distinct(n + 1, 0);
  set<int> distinct;

  for (int i = 0; i < n; ++i)
  {
    distinct.insert(A[i]);
    prefix_distinct[i + 1] = distinct.size();
  }

  distinct.clear();
  for (int i = n - 1; i >= 0; --i)
  {
    distinct.insert(A[i]);
    suffix_distinct[i] = distinct.size();
  }

  int sum_of_answers = 0;

  for (int i = 0; i < q; ++i)
  {
    int l = P[i][0] - 1;
    int r = P[i][1] - 1;

    int distinct_count = prefix_distinct[l] + suffix_distinct[r + 1];
    sum_of_answers += distinct_count;
  }

  cout << sum_of_answers << endl;

  return 0;
}