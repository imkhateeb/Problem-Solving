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
    int T;
    cin >> T;
    while (T--) {
        int n;
        cin >> n;

        vector<string> a;

        for (int i = 0; i < n; i++) {
            string s;
            cin >> s;
            a.push_back(s);
        }

        int firstRow = -1;
        int lastRow = -1;

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j] == '1' && firstRow == -1) {
                    firstRow = j;
                    break;
                }
                if (a[i][j] == '1' && firstRow != -1) {
                    lastRow = j;
                    break;
                }
            }
        }

        if (firstRow == lastRow) {
            cout << "SQUARE" << endl;
        } else {
            cout << "TRIANGLE" << endl;
        }
    }

    return 0;
}
