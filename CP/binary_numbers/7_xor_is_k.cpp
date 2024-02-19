#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define vpii vector<pair<int, int>>

using namespace std;

void fVec(vector<int> &v, int n)
{
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    v.push_back(x);
  }
}

void pVec(vector<int> &v)
{
  int n = v.size();
  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}
/*--------------------------------------------------------------------*/

/*
Array of length n. Find all pairs at indices i, j ( 0 <= i < j < n) has xor k.

Constraints
0 <= T <= 10 ^ 5
0 <= n <= 10 ^ 5
0 <= A[i] <= 10 ^ 9
*/

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n, k;
    cin >> n >> k;

    vector<int> v;
    fVec(v, n);

    map<int, int> m;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
      count += m[v[i] ^ k];
      m[v[i]]++;
    }

    cout << count << endl;
  }

  return 0;
}
