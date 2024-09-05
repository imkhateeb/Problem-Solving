#include <bits/stdc++.h>
using namespace std;

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

    vector <long long> v;
    for ( int i = 0; i < n; i++ ){
      long long x;
      cin >> x;
      v.push_back(x);
    }

    long long sum = 0;
    for ( int i = 0; i < n; i++ ){
      sum += v[i];
    }
    
    long long factor = sum / n;

    long long ans = 0;
    int flag = 1;
    for ( int i = 0; i < n; i++ ){
      if ( v[i] > factor ){
        ans = ans + (v[i] - factor);
      } else {
        ans = ans - (factor - v[i]);
      }

      if ( ans < 0 ){
        flag = 0;
        break;
      }
    }

    if ( flag == 1 ){
      cout << "YES" << endl;
    } else {
      cout << "NO" << endl;
    }
  }

  return 0;
}
