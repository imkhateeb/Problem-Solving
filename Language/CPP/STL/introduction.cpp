#include <bits/stdc++.h>
using namespace std;

int main()
{
   // Initializing an empty vector
   vector <int> v1;

   // Initializing a vector of length 5 with every value 100
   vector <int> v2(5, 100);
   for ( int i = 0; i < 5; i++ ){
      cout << v2[i] << " ";
   }cout << endl;

   // Initializing a vector of 10 element with every element as 0
   vector <int> v3(10);
   for ( int i = 0; i < 10; i++ ){
      cout << v3[i] << " ";
   }cout << endl;

   // vector of pair
   vector <pair<string, int>> vp1;
   for ( int i = 0; i < 3; i++ ){
      cout << "Enter your name: ";
      string name;
      cin >> name;
      cout << "Input your marks: ";
      int marks;
      cin >> marks;

      vp1.emplace_back(name, marks);
   }
   for( int i = 0; i < 3; i++ ){
      cout << "Marks of " << vp1[i].first << " is: " << vp1[i].second << endl;
   }


   return 0;
}