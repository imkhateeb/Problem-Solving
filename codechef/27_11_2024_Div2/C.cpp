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
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  let T;
  cin >> T;
  while (T--)
  {
    let n;
    cin >> n;
    string s;
    cin >> s;

    vector<int> temp;
    int cnt = 1;
    for (int i = 0; i < n - 1; i++)
    {
      if (s[i] == s[i + 1])
      {
        cnt++;
      }
      else
      {
        temp.pb(cnt);
        cnt = 1;
      }
    }
    temp.pb(cnt);

    int size = temp.size();
    int rem = n;
    cnt = 0;

    char last = 'e';

    vector<int> temp2 = temp;
    while (rem != 0)
    {
      cnt++;
      int j = 0;
      vector<int> arr = temp2;
      temp2.clear();
      for (int i = 0; i < arr.size(); i++)
      {
        if (arr[i] > 0)
        {
          arr[i]--;
          temp2.push_back(arr[i]);
          rem--;
          last = (i % 2 == 0) ? 'e' : 'o';
          j = i + 1;
          break;
        }
      }
      for (int i = j; i < arr.size(); i++)
      {
        if (i % 2 == 1)
        {
          if (arr[i] > 0 && last == 'e')
          {
            arr[i]--;
            temp2.push_back(arr[i]);
            rem--;
            last = 'o';
          }
          else
          {
            temp2[temp2.size() - 1] = temp2[temp2.size() - 1] + arr[i];
          }
        }
        else
        {
          if (arr[i] > 0 && last == 'o')
          {
            arr[i]--;
            temp2.push_back(arr[i]);
            rem--;
            last = 'e';
          }
          else
          {
            temp2[temp2.size() - 1] = temp2[temp2.size() - 1] + arr[i];
          }
        }
      }
    }
    cout << cnt << endl;
  }
  return 0;
}