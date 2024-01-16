#include <iostream>
#include <cassert>
using namespace std;

int main()
{

   unsigned int unsigned_number = 13;
   assert(unsigned_number == 0b1101);
   cout << unsigned_number << endl;

   int positive_signed_number = 13;
   assert(positive_signed_number == 0b1101);
   cout << positive_signed_number << endl;

   int negative_signed_number = -13;
   assert(negative_signed_number == 0b1111'1111'1111'1111'1111'1111'1111'0011);
   cout << negative_signed_number << endl;

   return 0;
}