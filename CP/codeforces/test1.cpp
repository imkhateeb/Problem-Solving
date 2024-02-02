#include <bits/stdc++.h>

using namespace std;

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    int n;
    cin >> n;
    vector<int> a;
    vector<int> b;

    for (int i = 0; i < n; i++)
    {
      int num;
      cin >> num;
      a.push_back(num);
    }
    for (int i = 0; i < n; i++)
    {
      int num;
      cin >> num;
      b.push_back(num);
    }

    for (int i = 0; i < n; i++)
    {
      if (a[i] == b[i] && a[i] != i + 1)
      {
        swap(a[i], a[a[i] - 1]);
        swap(b[i], b[b[i] - 1]);
      }
    }

    for (int i = 0; i < n; i++)
    {
      if ((a[i] + b[i]) > (2 * (i + 1)))
      {
        int avg = ((a[i] + b[i]) / 2);

        if (a[avg - 1] != b[avg - 1])
        {
          swap(a[i], a[avg - 1]);
          swap(b[i], b[avg - 1]);
        }
      }
    }

    for (int i = 0; i < n; i++)
    {
      cout << a[i] << " ";
    }
    cout << endl;

    for (int i = 0; i < n; i++)
    {
      cout << b[i] << " ";
    }
    cout << endl;
  }

  return 0;
}