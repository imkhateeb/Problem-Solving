#ifndef logger_h
#define logger_h
#include <string>

using namespace std;

class Logger
{
private:
  static Logger *instance;
  static int count;
  Logger();

public:
  static Logger *getInstance();
  void Log(string msg);
};

#endif