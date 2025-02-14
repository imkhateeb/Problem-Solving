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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  let T;
  cin >> T;
  while (T--)
  {
    let n;
    cin >> n;
    string s;
    cin >> s;

    int r1 = 0, g1 = 0, b1 = 0;
    for (let i = 0; i < n; i += 3)
    {
      if (s[i] == 'R')
        r1++;
      else if (s[i] == 'G')
        g1++;
      else
        b1++;
    }

    int r2 = 0, g2 = 0, b2 = 0;
    for (let i = 1; i < n; i += 3)
    {
      if (s[i] == 'R')
        r2++;
      else if (s[i] == 'G')
        g2++;
      else
        b2++;
    }

    int r3 = 0, g3 = 0, b3 = 0;
    for (let i = 2; i < n; i += 3)
    {
      if (s[i] == 'R')
        r3++;
      else if (s[i] == 'G')
        g3++;
      else
        b3++;
    }

    int rgb = r1 + g2 + b3;
    int rbg = r1 + b2 + g3;
    int grb = g1 + r2 + b3;
    int gbr = g1 + b2 + r3;
    int brg = b1 + r2 + g3;
    int bgr = b1 + g2 + r3;

    string ans = "";

    int maxi = max({rgb, rbg, grb, gbr, brg, bgr});

    if (maxi == rgb)
    {
      ans = "RGB";
    }
    else if (maxi == rbg)
    {
      ans = "RBG";
    }
    else if (maxi == grb)
    {
      ans = "GRB";
    }
    else if (maxi == gbr)
    {
      ans = "GBR";
    }
    else if (maxi == brg)
    {
      ans = "BRG";
    }
    else if (maxi == bgr)
    {
      ans = "BGR";
    }
    else
    {
      ans = "RGB";
    }

    int cnt = 0;
    for (int i = 0; i < n; i++)
    {
      if (s[i] != ans[i % 3])
      {
        cnt++;
      }
    }

    cout << cnt << endl;
  }
  return 0;
}