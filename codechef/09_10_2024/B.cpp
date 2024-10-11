#include <bits/stdc++.h>
#define let long long
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define endl "\n"
#define vi vector<let>
#define vvi vector<vector<let>>
#define vs vector<string>
#define vpii vector<pair<let, let>>
using namespace std;

int main()
{
  let T;
  cin >> T;
  while (T--)
  {
    let N;
    cin >> N;

    if (N % 4 == 0)
    {
      cout << (N / 4) * (N / 4) << endl;
    }
    else if (N == (((N / 4) * 4) + 1))
    {
      cout << (N / 4) * (N / 4) << endl;
    }
    else
    {
      cout << (N / 4) * (N / 4 + 1) << endl;
    }
  }

  return 0;
}