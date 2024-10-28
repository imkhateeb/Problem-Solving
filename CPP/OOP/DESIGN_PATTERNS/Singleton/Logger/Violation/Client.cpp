#include <iostream>
#include "Logger.hpp"
using namespace std;

int main()
{

  Logger *logger1 = new Logger();
  logger1->Log("This msg will get Logged.");

  cout << endl;

  Logger *logger2 = new Logger();
  logger2->Log("This msg is Logged again.");

  return 0;
}