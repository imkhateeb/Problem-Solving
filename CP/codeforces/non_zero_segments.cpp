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
  int n;
  cin >> n;
  vector<int> v;
  fVec(v, n);

  int sum = 0;
  int count = 0;

  int st = 0;
  for (int i = 0; i < n; i++)
  {
    sum += v[i];
    if (sum == 0)
    {
      count++;
      sum = v[i];
    }
    else
    {
      if ((((sum - v[st]) == 0) || ((sum + v[st]) == 0)))
      {
        st++;
        count++;
        sum = v[i];
      }
    }
  }

  while( st != (n-1) )
  {
    
    count++;
    sum -= v[st];
    st++;
  }

  cout << count << endl;
  return 0;
}
