#ifndef logger_h
#define logger_h
#include <string>

class Logger
{
private:
  static Logger *instance;
  static int count;
  Logger();

public:
  static Logger *getInstance();
  void Log(std::string msg);
};

#endif