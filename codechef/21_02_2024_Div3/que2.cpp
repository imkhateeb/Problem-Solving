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
    vector <int> v;
    v.push_back(0);
    for ( int i = 0; i < 22; i++ ){
      int x, y;
      cin >> x >> y;
      int ans = (x + (20*y));
      v.push_back(ans);
    }

    int maxi = INT_MIN;
    int index = 1;

    for ( int i = 1; i <= 22; i++ ){
      if ( v[i] > maxi ){
        maxi = v[i];
        index = i;
      }
    }
    cout << index << endl;
  }

  return 0;
}
