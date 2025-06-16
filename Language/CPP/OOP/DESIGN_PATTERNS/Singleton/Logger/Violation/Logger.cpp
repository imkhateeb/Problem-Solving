#include <iostream>

#include "Logger.hpp"

using namespace std;

Logger::Logger()
{
  cout << "Instance of Logger created successfully" << endl;
}

void Logger::Log(string msg)
{
  cout << msg << endl;
}