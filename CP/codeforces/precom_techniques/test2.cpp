#include <bits/stdc++.h>
#define ll long long int
using namespace std;

vector<int> intToBinary(ll a)
{
  vector<int> b;
  while (a != 0)
  {
    int bit = a % 2;
    b.push_back(bit);
    a = a / 2;
  }
  int n = b.size();
  for (int i = 0; i < n / 2; i++)
  {
    swap(b[i], b[n - i - 1]);
  }
  return b;
}

ll getPower(int k){
  ll ans = 1;
  for(int i = 0; i < k; i++){
    ans = ans * 2;
  }
  return ans;
}

int main()
{
  int t;
  cin >> t;
  while (t--)
  {
    ll a, b, r;
    cin >> a >> b >> r;
    vector<int> arr = intToBinary(a);
    vector<int> brr = intToBinary(b);

    int p = arr.size();
    int q = brr.size();

    if (p > q)
    {
      for (int i = 0; i < p - q; i++)
      {
        brr.insert(brr.begin(), 0);
      }
    }
    else if (q > p)
    {
      for (int i = 0; i < q - p; i++)
      {
        arr.insert(arr.begin(), 0);
      }
    }

    // for (int i = 0; i < arr.size(); i++)
    // {
    //   cout << arr[i] << " ";
    // } cout << endl;
    // for (int i = 0; i < arr.size(); i++)
    // {
    //   cout << brr[i] << " ";
    // } cout << endl;

    ll ans = 0;

    int n = arr.size();
    int first1a = 0;
    int first1b = 0;

    bool finalFlag = false;
    for (int i = 0; i < n; i++)
    {
      if ( !finalFlag && (arr[i] == brr[i]) ){
        continue;
      }
      finalFlag = true;
      
      if (a > b && arr[i] == 1 && brr[i] == 0 && first1a == 1)
      {
        ll power = getPower(n - i - 1);
        ll check = power + ans;
        if (r >= check)
        {
          ans = power + ans;
        }
      }
      else if (a < b && arr[i] == 0 && brr[i] == 1 && first1b == 1)
      {
        ll power = getPower(n - i - 1);
        ll check = power + ans;
        if (r >= check)
        {
          ans = power + ans;
        }
      }
      

      if (arr[i] == 1)
      {
        first1a = 1;
      }
      if (brr[i] == 1)
      {
        first1b = 1;
      }
    }
    // cout << "ans: " << ans << endl;
    // cout << a << " " << b << endl;
    ll final = abs((a ^ ans) - (b ^ ans));
    cout << final << endl;
  }

  return 0;
}