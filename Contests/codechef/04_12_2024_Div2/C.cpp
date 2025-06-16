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
    let n;
    cin >> n;
    string s;
    cin >> s;
    string p;
    cin >> p;
    unordered_map<char, char> m;

    for (let i = 0; i < 26; i++)
    {
      m[p[i]] = p[26 - i - 1];
      m[p[26 - i - 1]] = p[i];
    }

    let cnt = 0;
    char last = s[0];
    bool flag = true;

    let freq[26] = {0};

    for (let i = 0; i < n; i++)
    {
      freq[s[i] - 'a']++;
    }

    for (let i = 1; i < n; i++)
    {
      freq[s[i] - 'a']--;
      if (s[i] < last)
      {
        if (m[s[i]] < last)
        {
          flag = false;
          break;
        }
        else
        {
          last = m[s[i]];
          cnt++;
        }
      }
      else
      {
        if (m[s[i]] > last)
        {
          bool isContain = false;
          for(let i = 'a' i <= s[i]; i++){
            
          }
          if (m[s[i]] < s[i])
          {
            last = m[s[i]];
            cnt++;
          }
        }
        else
        {
          last = m[s[i]];
        }
      }
    }

    if (!flag)
    {
      cout << -1 << endl;
    }
    else
    {
      cout << cnt + 1 << endl;
    }
  }

  return 0;
}
