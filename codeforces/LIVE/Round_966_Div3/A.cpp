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

    /*--------------------- START --- CODE ---------------------*/

    string str = "";

    while (n)
    {
      char ch = (char)('0' + (n % 10));
      str.push_back(ch);

      n /= 10;
    }

    reverse(str.begin(), str.end());

    if (str.size() <= 2)
    {
      cout << "NO" << endl;
    }
    else
    {
      if (str[0] == '1' && str[1] == '0')
      {
        if (str.size() == 3)
        {
          if ((str[2] - '0') >= 2)
          {
            cout << "YES" << endl;
          }
          else
          {
            cout << "NO" << endl;
          }
        }
        else
        {
          if (str[2] == '0')
          {
            cout << "NO" << endl;
          }
          else
          {
            cout << "YES" << endl;
          }
        }
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
