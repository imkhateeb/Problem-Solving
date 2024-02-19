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

void pVec(vector<int> &v)
{
  int n = v.size();
  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;

    vector<long long> a;
    for (int i = 0; i < n; i++)
    {
      long long x;
      cin >> x;
      a.push_back(x);
    }

    int front = 1;
    int back = 1;

    for (int i = 0; i < n - 1; i++)
    {
      if (a[i] == a[i + 1])
      {
        front++;
      }
      else
      {
        break;
      }
    }

    for (int i = n - 1; i > 0; i--)
    {
      if (a[i] == a[i - 1])
      {
        back++;
      }
      else
      {
        break;
      }
    }

    int decreaser = 0;
    if (a[0] == a[n - 1])
    {
      if (front + back > n)
      {
        decreaser = n;
      }
      else
      {
        decreaser = front + back;
      }
    }
    else
    {
      decreaser = max(front, back);
    }

    cout << n - decreaser << endl;
  }

  return 0;
}