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
    let n, m;
    cin >> n >> m;

    bool evenTurn = true;

    for (let i = 0; i < n; i++)
    {
      bool insideEvenTurn = evenTurn;
      for (let j = 0; j < m; j++)
      {
        if (insideEvenTurn)
        {
          cout << "2 ";
        }
        else
        {
          cout << "3 ";
        }
        insideEvenTurn = !insideEvenTurn;
      }
      cout << endl;
      evenTurn = !evenTurn;
    }
  }

  return 0;
}