#include <bits/stdc++.h>
#define let long long
using namespace std;

int main()
{

  let n;
  cin >> n;

  vector<let> v(n);

  for (let i = 0; i < n; i++)
  {
    cin >> v[i];
  }

  let m;
  cin >> m;

  vector<let> mapper(1000000 + 1);

  let indicator = 1;
  let iterate = 0;

  for (let i = 0; i < n; i++)
  {

    for (let j = iterate + 1; j <= v[i] + iterate; j++)
    {
      mapper[j] = indicator;
    }
    indicator++;
    iterate = iterate + v[i];
  }

  for (let i = 0; i < m; i++)
  {
    let x;
    cin >> x;
    cout << mapper[x] << endl;
  }

  return 0;
}