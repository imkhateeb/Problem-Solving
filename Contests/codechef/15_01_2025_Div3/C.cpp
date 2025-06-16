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
    let n, k;
    cin >> n >> k;

    vi v(n);
    vector<int> freq(21, 0);
    for (int i = 0; i < n; i++)
    {
      int x;
      cin >> x;
      v[i] = x;
      freq[x]++;
    }

    vector<int> temp1 = freq;
    vector<int> temp2 = freq;
    bool first = false;
    bool second = false;

    int maxi = *max_element(freq.begin(), freq.end());
    if (maxi == freq[k])
    {
      cout << 0 << endl;
      continue;
    }

    for (int i = 0; i < n; i++)
    {
      temp1[v[i]]--;
      int maxi = *max_element(temp1.begin(), temp1.end());
      if ((temp1[k] > 0) && (maxi == temp1[k]))
      {
        first = true;
        break;
      }
    }

    for (int i = n - 1; i >= 0; i--)
    {
      temp2[v[i]]--;
      int maxi = *max_element(temp2.begin(), temp2.end());
      if ((temp2[k] > 0) && (maxi == temp2[k]))
      {
        second = true;
        break;
      }
    }

    if (first || second)
    {
      cout << 1 << endl;
    }
    else
    {
      cout << 2 << endl;
    }
  }

  return 0;
}
