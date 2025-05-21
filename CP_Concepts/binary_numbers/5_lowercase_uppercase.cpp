#include <bits/stdc++.h>
using namespace std;

void getBinary(int n)
{
  for (int i = 10; i >= 0; i--)
  {
    cout << ((n >> i) & 1);
  }
}

int main()
{

  for (int i = 'A'; i <= 'E'; i++)
  {
    cout << (char)i << " ";
    getBinary(i);
    cout << endl;
  }
	/*
		A 00001000001
		B 00001000010
		C 00001000011
		D 00001000100
		E 00001000101
	*/

  for (int i = 'a'; i <= 'e'; i++)
  {
    cout << (char)i << " ";
    getBinary(i);
    cout << endl;
  }
	/*
		a 00001100001
		b 00001100010
		c 00001100011
		d 00001100100
		e 00001100101
	*/

	// We can see binary of skii of upper-case and lower-case only differ in 5th bit
	// If 5th bet is set it will be lower-case otherwise upper-case, rest of the configurations are same.

  // Conversion of capital to small and vice versa
  char ch1 = 'A';
  cout << ch1 << " After conversion - " << (char)(ch1 | (1 << 5)) << endl;
  char ch2 = 'a';
  cout << ch2 << " After conversion - " << (char)(ch2 & ~(1 << 5)) << endl;
	/*
		A After conversion a
		a After conversion A
	*/

  // One more to convert uppercase to lowercase
  char ch3 = 'K';
  cout << ch3 << " After conversion - " << (char)(ch3 | ' ') << endl;
  // bcz ' ' is 32 and 32 is 00100000, so 5th bit is set and it will convert to lower case

  // One more to convert lowercase to uppercase
  char ch4 = 'z';
  cout << ch4 << " After conversion - " << (char)(ch4 & '_') << endl;
  // bcz '_' is 95 and 95 is 01011111, so 5th bit is unset and it will convert to upper case

  return 0;
}