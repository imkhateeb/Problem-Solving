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

    vector<int> a;
    fVec(a, n);

    long long sum = 0;
    for (int i = 0; i < n; i++)
    {
      sum = sum + a[i];
    }

    bool isOne = false;
    for (int i = 0; i < n; i++)
    {
      if (a[i] == 1)
      {
        isOne = true;
        break;
      }
    }

    if (sum % 3 == 0)
    {
      cout << 0 << endl;
    }
    else if ((sum + 1) % 3 == 0)
    {
      cout << 1 << endl;
    }
    else
    {
      if ( n == 1 ){
        cout << 1 << endl;
      } else {
        int flag = 0;
        for ( int i = 0; i < n; i++ ){
          if ( a[i]%3 == 1 ){
            cout << 1 << endl;
            flag = 1;
            break;
          }
        }
        if ( flag == 0 ){
          cout << 2 << endl;
        }

      }
    }
  }

  return 0;
}
