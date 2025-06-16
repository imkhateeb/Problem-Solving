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

    int cnt = 0;
    int firstFound = 0;
    int lastFound = n-1;

    for ( int i = 0; i < n; i++ ){
      if ( v[i] == 1 ){
        firstFound = i;
        break;
      }
    }

    for ( int i = n-1; i >= 0; i-- ){
      if ( v[i] == 1 ){
        lastFound = i;
        break;
      }
    }

    for ( int i = firstFound; i <= lastFound; i++ ){
      if ( v[i] == 0 ){
        cnt++;
      }
    }

    cout << cnt << endl;
  }

  return 0;
}
