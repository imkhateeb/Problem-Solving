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
    int n, q;
    cin >> n >> q;

    vi v;
    fVec(v, n);

    vector<long long> prefixSum(n+1, 0);
    vector<long long> oneZero(n+1, 0);

    for ( int i = 0; i < n; i++ ){

      prefixSum[i+1] = prefixSum[i] + v[i];
      if ( v[i] == 1 ){
        oneZero[i+1] = oneZero[i] + 2;
      } else {
        oneZero[i+1] = oneZero[i] + 1;
      }

    }


    while (q--)
    {
      int l, r;
      cin >> l >> r;

      long long sum = prefixSum[r] - prefixSum[l-1];
      int mini = oneZero[r] - oneZero[l-1];

      if ( sum >= mini && l != r ){
        cout << "YES" << endl;
      } else {
        cout << "NO" << endl;
      }
    }

  }

  return 0;
}

