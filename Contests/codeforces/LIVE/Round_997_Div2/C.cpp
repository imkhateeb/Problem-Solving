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

// Function to generate the sequence
vi generatePattern(let n)
{
  vi pattern;
  vi base = {7, 3, 5}; // Example base pattern, can be modified

  for (let i = 0; i < n; i++)
  {
    pattern.pb(base[i % base.size()] + (i % 2 == 0 ? n : 0)); // Modify as per rules
  }

  return pattern;
}

int main()
{
  let t;
  cin >> t;
  while (t--)
  {

    let n;
    cin >> n;

    vi result = generatePattern(n);

    // Output the pattern
    for (let num : result)
    {
      cout << num << " ";
    }
    cout << endl;
  }

  return 0;
}
