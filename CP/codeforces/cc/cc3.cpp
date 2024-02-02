#include <bits/stdc++.h>
#define ll long long int
using namespace std;

void fillVector(int n, vector<int> &v)
{
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    v.push_back(x);
  }
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n, q;
    cin >> n >> q;
    string s;
    cin >> s;
    char ch[q];
    for (int i = 0; i < q; i++)
    {
      cin >> ch[i];
    }

    int count = 1;
    int maxi = 1;

    vector <int> v;

    for (int i = 0; i < n - 1; i++)
    {
      if (s[i] == s[i + 1])
      {
        count++;
      }
      else
      {
        maxi = max(maxi, count);
        count = 1;
      }
      if (i == n - 2)
      {
        maxi = max(maxi, count);
      }
    }

    v.push_back(maxi);

    for (int i = -1; i < q - 1; i++)
    {
      s.push_back(ch[i+1]);
      if (s[n + i] == s[n + i + 1])
      {
        count++;
        maxi = max(maxi, count);
      }
      else
      {
        maxi = max(maxi, count);
        count = 1;
      }
      v.push_back(maxi);
    }
    
    for ( int i = 0; i <= q; i++ ){
      cout << v[i] << " ";
    } cout << endl;
  }
  return 0;
}
