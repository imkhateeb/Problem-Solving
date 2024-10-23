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
    string s1;
    cin >> s1;
    string s2;
    cin >> s2;
    int arr[26] = {0};

    for (int i = 0; i < s1.size(); i++)
    {
      arr[s1[i] - 'a']++;
    }

    for (int i = 0; i < s2.size(); i++)
    {
      arr[s2[i] - 'a']++;
    }

    bool ans = true;

    for (int i = 0; i < 26; i++)
    {
      if (arr[i] == 0)
      {
        ans = false;
        break;
      }
    }

    if (!ans)
    {
      cout << "YES" << endl;
    }
    else
    {
      cout << "NO" << endl;
    }
  }

  return 0;
}