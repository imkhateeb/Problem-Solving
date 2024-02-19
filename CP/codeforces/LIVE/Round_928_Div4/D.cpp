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

const int N = 2147483647;

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

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;

    vi v;
    fVec(v, n);

    int cnt = 0;
    map<int, int> m;

    for (int i = 0; i < n; i++)
    {
      if (m[v[i]] == 0)
      {
        m[v[i] ^ N]++;
      }
      else
      {
        m[v[i]]--;
        cnt++;
      }
    }

    cout << n - cnt << endl;
  }
  return 0;
}