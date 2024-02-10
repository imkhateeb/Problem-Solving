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
  for (int i = 0; i < v.size(); i++)
  {
    cout << v[i] << " ";
  }
  cout << endl;
}

int main()
{

  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;
    vector<int> v;
    fillVector(v, n);

    vector <int> alphas(26, 0);

    string str = "";

    for ( int i = 0; i < n; i++ ){
      for ( int j = 0; j < 26; j++ ){
        if (alphas[j] == v[i] ){
          str.push_back('a' + j);
          alphas[j] += 1;
          break;
        }
      }
    }

    cout << str << endl;
  }

  return 0;
}
