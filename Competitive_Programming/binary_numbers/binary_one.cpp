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

void alphaFreq(vector<int> &v, string s)
{
  int n = s.size();
  for (int i = 0; i < n; i++)
  {
    v[s[i] - 'a']++;
  }
}

void getBinary(int n)
{
  for (int i = 31; i >= 0; i--)
  {
    cout << ((n >> i) & 1);
  }
  cout << endl;
}

int countSetBit(int n){
  int count = 0;
  for ( int i = 0; i < 32; i++ ){
    count += ( ( n >> i ) & 1 );
  }
  return count;
}

int main()
{
  int T;
  cin >> T;
  while (T--)
  {
    int n;
    cin >> n;

    // Getting the binary
    getBinary(n);

    // checking if ith bit is set or not
    cout << "4th bit of " << n << " is " << ((n >> 4) & 1) << endl;
    cout << "5th bit of " << n << " is " << ((n >> 5) & 1) << endl;

    // Setting a bit -> OR with set bit with the required bit
    cout << "After Setting 5th bit of " << n << " ";
    getBinary(n | (1 << 5));

    // Unsetting a bit -> AND with unset bit with the required bit( remaining bit should be set)
    cout << "After unsetting 4th bit of " << n << " ";
    getBinary(n & (~(1 << 4)));

    // Toggling a bit -> XOR with 1 with that bit
    // If bit is 0 -> 0 ^ 1 = 1
    // If bit is 1 -> 1 ^ 1 = 0
    cout << "After toggling 5th bit of " << n << " ";
    getBinary(n ^ (1 << 5));
    cout << "After toggling 2th bit of " << n << " ";
    getBinary(n ^ (1 << 2));

    // counting set bits
    cout << "Total set bits in " << n << " is " << countSetBit(n) << endl;

    // Checking if a number is odd or even
    if ( n & 1 ){
      cout << "The number is odd" << endl;
    } else {
      cout << "Number is even" << endl;
    }

    // Checking if a number is square of 2
    if ( n & (n-1) ){
      cout << "Not a square of 2" << endl;
    } else {
      cout << "Square of 2" << endl;
    }
  }

  return 0;
}
