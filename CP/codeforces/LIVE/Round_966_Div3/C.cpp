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

void fillVec(vector<let> &v, let n)
{
  for (let i = 0; i < n; i++)
  {
    let x;
    cin >> x;
    v.push_back(x);
  }
}

void printVec(vector<let> &v)
{
  let n = v.size();
  for (let i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

let power(let x, let y)
{
  let res = 1;
  for (let i = 0; i < y; i++)
  {
    res = res * x;
  }
  return res;
}

/*----------------------- MAIN --- CODE ------------------------*/

int main()
{
  let T;
  cin >> T;
  while (T--)
  {
    /*------------------------ VARIABLES -----------------------*/
    let n;
    /*------------------------- INPUTS -------------------------*/
    cin >> n;
    vi v;
    fillVec(v, n);

    let m;
    cin >> m;

    /*--------------------- START --- CODE ---------------------*/

    while (m--)
    {
      string s;
      cin >> s;

      if (s.size() != n)
      {
        cout << "NO" << endl;
        continue;
      }

      unordered_map<char, int> m1;
      unordered_map<int, char> m2;
      bool flag = true;

      for (let i = 0; i < n; i++)
      {
        if (m1[s[i]])
        {
          if (m1[s[i]] != v[i])
          {
            flag = false;
            break;
          }
          else if (!m2[v[i]])
          {
            flag = false;
            break;
          }
          else if (m2[v[i]] != s[i])
          {
            flag = false;
            break;
          }
        }
        else if (m2[v[i]])
        {
          flag = false;
          break;
        }
        else
        {
          m1[s[i]] = v[i];
          m2[v[i]] = s[i];
        }
      }

      if (flag)
      {
        cout << "YES" << endl;
      }
      else
      {
        cout << "NO" << endl;
      }
    }

    /*---------------------- END --- CODE ----------------------*/
  }

  return 0;
}
