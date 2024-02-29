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

    int curr = v[0];
    for ( int i = 1; i < n; i++ ){
      if ( v[i] > curr ){
        curr = v[i];
      } else if ( v[i] == curr ){
        curr = 2 * v[i];
      } else {

        int factor = ((curr/v[i]) + 1);

        curr = factor*v[i];
      }
    }

    cout << curr << endl;
  }

  return 0;
}
