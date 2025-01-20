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
    vector<vi> decks(n);
    for (let i = 0; i < n; i++)
    {
      vector<let> deck;
      for (let j = 0; j < m; j++)
      {
        let card;
        cin >> card;
        deck.pb(card);
      }
      sort(all(deck));
      decks[i] = deck;
    }

    // for (let i = 0; i < n; i++)
    // {
    //   for (let j = 0; j < m; j++)
    //   {
    //     cout << decks[i][j] << " ";
    //   }
    //   cout << endl;
    // }

    bool flag = false;

    for (int i = 0; i < n; i++)
    {
      for (int j = 0; j < m - 1; j++)
      {
        if ((decks[i][j] + n) != decks[i][j + 1])
        {
          flag = true;
          break;
        }
      }
      if (flag)
        break;
    }

    if (flag)
    {
      cout << -1 << endl;
    }
    else
    {
      vector<int> ans(n, 0);
      for (int i = 0; i < n; i++)
      {
        ans[decks[i][0]] = i + 1;
      }

      for (int i = 0; i < n; i++)
      {
        cout << ans[i] << " ";
      }
      cout << endl;
    }
  }

  return 0;
}
