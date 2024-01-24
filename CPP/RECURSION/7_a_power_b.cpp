#include <bits/stdc++.h>
#define ll long long

using namespace std;

ll power(int a, int b){
  if ( b < 1 ) return 1;

  if ( b%2 == 0 ) return power(a, b/2) * power(a, b/2);
  else return a * power(a, b/2) * power(a, b/2);

};


int main()
{
  int a, b;
  cout << "Enter a and b: ";

  cin >> a >> b;

  ll ans = power(a, b);

  cout << a << "^" << b << " = " << ans << "\n";

  return 0;
}