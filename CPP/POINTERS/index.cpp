// Basics

#include <bits/stdc++.h>
using namespace std;
int main()
{

  // int *ptr; // a bad practice of initializing a pointer

  // 1 and 2 is same
  int i = 100; // ---- 1
  int *ptr = &i;
  // OR
  int *p = 0; // ---- 2
  p = &i;
  cout << int(ptr) << " , " << int(p) << " - " << *ptr << " , " << *p << endl;

  int num = 5;
  int *ptr1 = &num;
  cout << ptr1 << " - "; // Address
  cout << *ptr1 << endl; // Value

  char ch = 'K';
  char *ptr2 = &ch;
  cout << ptr2 << " - ";
  cout << *ptr2 << endl;

  double db = 5.5;
  double *ptr3 = &db;
  cout << int(ptr3) << " - ";
  cout << *ptr3 << endl;

  // Size of integers and pointers
  cout << "Size of integer is - " << sizeof(num) << endl;
  cout << "Size of pointer is - " << sizeof(ptr1) << endl;
  cout << "Size of pointer is - " << sizeof(ptr2) << endl;
  cout << "Size of pointer is - " << sizeof(ptr3) << endl;
  return 0;
}