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
    vector <int> v;
    fillVector(v, n);

    vector <int> freq(n, 0);

    int index = 0;
    for ( int i = 1; i < n; i++ ){
      if ( v[i] == v[i-1] ){
        freq[i] = index;
      } else {
        index = i;
        freq[i] = index;
      }
    }


    int q;
    cin >> q;
    while(q--){
      int l, r;
      cin >> l >> r;

      if ( freq[l-1] == freq[r-1] ){
        cout << -1 << " " << -1 << endl;
      } else {
        cout << freq[r-1] << " " << freq[r-1] + 1 << endl; 
      }
    }
    cout << endl;
  }

  return 0;
}
