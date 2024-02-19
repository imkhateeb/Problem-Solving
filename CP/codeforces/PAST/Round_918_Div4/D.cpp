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

    string s;
    cin >> s;

    string str = "";
    for (int i = 0; i < n; i++)
    {
      if (s[i] == 'a' || s[i] == 'e')
      {
        str.push_back('V');
      }
      else
      {
        str.push_back('C');
      }
    }

    string ans = "";
    string temp = "";

    for (int i = 0; i < n; i++)
    {

      ans.push_back(s[i]);
      if ( i == n-1 ) break;

      if ( str[i] == 'V' ){
        if ( i <= n-3 ){
          if ( str[i+1] == 'C' && str[i+2] == 'V' ){
            ans.push_back('.');
          }
        }
      } else {
        if ( i <= n-2 ){
          if ( str[i+1] == 'C' ){
            ans.push_back('.');
          }
        }
      }
    }

    cout << ans << endl;
  }

  return 0;
}
