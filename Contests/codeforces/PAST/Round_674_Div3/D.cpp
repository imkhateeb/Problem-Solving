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

  map<long long, int> m;
  map<long long, bool> vis;
  vector<int> p(n + 1, 0);

  p[0] = 0;
  m[p[0]]++;
  for (int i = 1; i <= n; i++)
  {
    p[i] = p[i - 1] + v[i - 1];
    m[p[i]]++;
  }

  int count = 0;
  queue<int> q;

  for ( int i = 0; i <= n; i++ ){
    cout << p[i] << " ";
  } cout << endl;

  for (int i = 0; i <= n; i++)
  {
    if (vis[p[i]])
    {
      if (m[p[i]] > 1)
      {
        q.push(p[i]);
        m[p[i]]--;
      }
      else
      {
        vis[p[i]] = false;
      }

      while (q.front() != p[i])
      {
        vis[q.front()] = false;
        q.pop();
      }

      q.pop();
      count++;
    }
    else
    {
      if (m[p[i]] > 1)
      {
        q.push(p[i]);
        m[p[i]]--;
        vis[p[i]] = true;
      }
    }
  }

  cout << count << endl;

  return 0;
}
