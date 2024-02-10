#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007

using namespace std;

void fillVector(vector<int> &v, int n)
{
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    v.push_back(x);
  }
}

void printVector(vector<int> &v)
{
  int n = v.size();
  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

void alphaFreq(vector<int> &v, string s)
{
  int n = s.size();
  for (int i = 0; i < n; i++)
  {
    v[s[i] - 'a']++;
  }
}

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;
    string s;
    cin >> s;

    int first = 0;
    int last = n - 1;
    bool lfound = false;
    bool rfound = false;

    int st = 0;
    int en = n - 1;
    while (st <= en)
    {
      if (s[st] == 'B' && !lfound)
      {
        lfound = true;
        first = st;
      }
      if (s[en] == 'B' && !rfound)
      {
        rfound = true;
        last = en;
      }
      if (lfound && rfound)
      {
        break;
      }
      if (!lfound)
      {

        st++;
      }
      if (!rfound)
      {

        en--;
      }
    }

    cout << last - first + 1 << endl;
  }

  return 0;
}
