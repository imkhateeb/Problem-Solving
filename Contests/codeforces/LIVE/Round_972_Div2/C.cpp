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
  ios_base::sync_with_stdio(false);
  cin.tie(NULL);

  let T;
  cin >> T;

  while (T--)
  {
    let n, m, q;
    cin >> n >> m >> q;

    vi b(m);
    for (int i = 0; i < m; i++)
    {
      cin >> b[i];
    }

    sort(all(b));

    while (q--)
    {
      let x;
      cin >> x;

      auto upper = upper_bound(all(b), x);
      auto lower = lower_bound(all(b), x);

      let nextLarger = (upper != b.end()) ? *upper : -1;
      let nextSmaller = (lower != b.begin()) ? *(--lower) : -1;

      if (nextLarger == -1)
      {
        cout << n - nextSmaller << endl;
      }
      else if (nextSmaller == -1)
      {
        cout << nextLarger - 1 << endl;
      }
      else
      {
        cout << (nextLarger - nextSmaller) / 2 << endl;
      }
    }
  }

  return 0;
}

/**
CODE WHICH GAVE TLE INSTAED OF HAVING SIMLIAR TIME COMPLEXITY


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

let nextLargerElementOfX(vi sortedArray, let x)
{
  let n = sortedArray.size();
  let l = 0, r = n - 1;
  let ans = -1;
  while (l <= r)
  {
    let mid = l + (r - l) / 2;
    if (sortedArray[mid] > x)
    {
      ans = sortedArray[mid];
      r = mid - 1;
    }
    else
    {
      l = mid + 1;
    }
  }
  return ans;
}

let nextSmallerElementOfX(vi sortedArray, let x)
{
  let n = sortedArray.size();
  let l = 0, r = n - 1;
  let ans = -1;
  while (l <= r)
  {
    let mid = l + (r - l) / 2;
    if (sortedArray[mid] < x)
    {
      ans = sortedArray[mid];
      l = mid + 1;
    }
    else
    {
      r = mid - 1;
    }
  }
  return ans;
}

int main()
{
  let T;
  cin >> T;
  while (T--)
  {
    let n, m, q;
    cin >> n >> m >> q;

    vi b;
    for (int i = 0; i < m; i++)
    {
      let x;
      cin >> x;
      b.pb(x);
    }

    sort(all(b));

    while (q--)
    {
      let x;
      cin >> x;

      let nextLarger = nextLargerElementOfX(b, x);
      let nextSmaller = nextSmallerElementOfX(b, x);

      if (nextLarger == -1)
      {
        cout << n - nextSmaller << endl;
      }
      else if (nextSmaller == -1)
      {
        cout << nextLarger - 1 << endl;
      }
      else
      {
        cout << (nextLarger - nextSmaller) / 2 << endl;
      }
    }
  }

  return 0;
}

 */
