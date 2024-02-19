#include <bits/stdc++.h>
#define ll long long
#define MOD 1000000007
#define pb push_back
#define ppb pop_back
#define mp make_pair
#define ff first
#define ss second
#define all(x) x.begin(), x.end()
#define endl "\n"
#define vi vector<int>
#define vvi vector<vector<int>>
#define vs vector<string>
#define vpii vector<pair<int, int>>

using namespace std;

void fVec(vector<int> &v, int n)
{
  for (int i = 0; i < n; i++)
  {
    int x;
    cin >> x;
    v.push_back(x);
  }
}

void pVec(vector<int> &v)
{
  int n = v.size();
  for (int i = 0; i < n; i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}
/*--------------------------------------------------------------------*/


int main() {
    int t;
    cin >> t;
    while (t--) {
        unordered_map<int, int> freq;
        int a, b, c;
        cin >> a >> b >> c;
        freq[a]++;
        freq[b]++;
        freq[c]++;
        if (freq[a] == 1) cout << a << endl;
        else if (freq[b] == 1) cout << b << endl;
        else cout << c << endl;
    }
    return 0;
}
