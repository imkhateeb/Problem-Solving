#include <bits/stdc++.h>
using namespace std;

void print(int n)
{
  // Base Case - if n = 1, print 1
  if (n == 1)
  {
    cout << 1 << " ";
    return;
  };

  // Induction Hypothesis - print(n - 1) -> print 1 to n - 1
  print(n - 1);

  // Induction Step - print n
  cout << n << " ";
}

void print(int n, int index)
{
  // Base Case - if index = n, print n
  if (index == n)
  {
    cout << n << " ";
    return;
  };

  // Induction Step - print index
  cout << index << " ";

  // Induction Hypothesis - print(n, index + 1) -> print index + 1 to n
  print(n, index + 1);
};

void reversePrint(int n){
  // Base Case - if n = 1, print 1
  if( n == 1 ) {
    cout << 1 << " ";
    return;
  }

  // Induction Step - print n
  cout << n << " ";

  // Induction Hypothesis - reversePrint(n - 1) -> print n - 1 to 1
  reversePrint(n - 1);
}

int main()
{
  int n;
  cout << "Enter the number of elements: ";
  cin >> n;

  // Hypothesis - print(n) -> print 1 to n
  print(n); cout << endl;

  // Hypothesis - print(n, 1) -> print 1 to n
  print(n, 1); cout << endl;

  // Hypothesis - reversePrint(n) -> print n to 1
  reversePrint(n);

  return 0;
}