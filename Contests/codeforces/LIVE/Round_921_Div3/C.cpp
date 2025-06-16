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

long long power(long long a, long long b)
{
  long long result = 1;
  for (long long i = 0; i < b; ++i)
  {
    result *= a;
  }
  return result;
}

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    long long a, b, l;
    cin >> a >> b >> l;

    long long cnt = 0;
    long long k = l;

    while (k % a == 0 && k > 0)
    {
      cnt++;
      k = k / a;
    }

    long long factorA = cnt;

    cnt = 0;
    k = l;
    while (k % b == 0 && k > 0)
    {
      cnt++;
      k = k / b;
    }
    long long factorB = cnt;

    long long ans = 0;

    map<int, bool> m;

    for (long long i = 0; i <= factorA; i++)
    {
      for (long long j = 0; j <= factorB; j++)
      {
        long long temp = (power(a, i)) * (power(b, j));
        if (l % temp == 0)
        {
          long long x = l / temp;
          if (m[x] == false)
          {
            m[x] = true;
            ans++;
          }
        }
      }
    }

    cout << ans << endl;
  }

  return 0;
}
