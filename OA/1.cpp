#include <iostream>
#include <vector>
#include <set>
#include <unordered_set>

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

  int sum_of_answers = 0;

  for (int i = 0; i < q; ++i)
  {
    int l = P[i][0];
    int r = P[i][1];

    --l;
    --r;

    unordered_set<int> distinct_elements;
    for (int j = 0; j < l; ++j)
    {
      distinct_elements.insert(A[j]);
    }
    for (int j = r + 1; j < n; ++j)
    {
      distinct_elements.insert(A[j]);
    }

    sum_of_answers += distinct_elements.size();
  }

  cout << sum_of_answers << endl;

  return 0;
}
