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
#define vll vector<long long>
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

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;

    vi a;
    fVec(a, n);

    vi b;
    fVec(b, n);

    vpii c;
    for (int i = 0; i < n; i++)
    {
      c.pb(mp(a[i], b[i]));
    }

    sort(all(c));

    for (int i = 0; i < n; i++)
    {
      cout << c[i].ff << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
      cout << c[i].ss << " ";
    }
    cout << endl;
  }

  return 0;
}
