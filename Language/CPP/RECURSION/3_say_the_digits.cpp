#include <bits/stdc++.h>
using namespace std;

string words[] = {"zero", "one", "two", "three", "four", "five", "six", "seven", "eight", "nine"};

string say_the_digits(int n)
{
  if ( n < 10 ) return words[n];

  int last_digit = n % 10;

  return say_the_digits(n / 10) + " " + words[last_digit];
}
int main()
{
  int n;
  cout << "Enter the number: ";
  cin >> n;

  string str_words = say_the_digits(n);
  cout << str_words << endl;
  return 0;
}