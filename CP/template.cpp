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
  }

  return 0;
}
