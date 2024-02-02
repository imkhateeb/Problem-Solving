#include <iostream>

using namespace std;

int main()
{
  string s1 = "Hello";
  string s2 = "world!";
  string s3 = "hello";
  string s4 = "Hello";

  string ans = s1 + " " + s2;
  cout << ans << endl; // Hello world!

  if (s1 == s2)
  {
    cout << "Equal" << endl;
  }
  else
  {
    cout << "Not Equal" << endl;
  }

  if (s1 == s3)
  {
    cout << "Equal" << endl;
  }
  else
  {
    cout << "Not Equal" << endl;
  }

  if (s1 == s4)
  {
    cout << "Equal" << endl;
  }
  else
  {
    cout << "Not Equal" << endl;
  }

  return 0;
}