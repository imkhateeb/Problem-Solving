#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <mutex> // Include <mutex> for std::mutex

class Logger
{
private:
  static Logger *instance;
  static int count;
  static std::mutex mtx; // std::mutex for thread safety
  Logger();

public:
  static Logger *getInstance();
  void Log(std::string msg);
};

#endif
