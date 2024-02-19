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

void alphaFreq(vector<int> &v, string s)
{
  int n = s.size();
  for (int i = 0; i < n; i++)
  {
    v[s[i] - 'a']++;
  }
}

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n, x;
    cin >> n >> x;
  }

  return 0;
}
