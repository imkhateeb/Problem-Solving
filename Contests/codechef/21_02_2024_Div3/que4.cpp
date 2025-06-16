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

    vector <int> binary;
    while ( n > 0 ){
      binary.push_back(n%2);
      n = n/2;
    }

    // pVec(binary);

    vector<int> finalP;

    int x = binary.size();
    int index = 0;

    bool firstOne = false;
    for ( int i = 0; i < x; i++ ){
      
      if ( !firstOne ){
        if ( binary[i] == 1 ){
          firstOne = true;
          index = i;
        }
      } else {
        
        if ( binary[i] == 0 ){
          finalP.push_back(index);
          index = i;
        }

      }
    }

    int p = finalP.size();

    int ans = 0;
    for ( int i = 0; i < p; i++ ){
      ans += pow(2, finalP[i]);
    }

    cout << ans << endl;
  }

  return 0;
}
