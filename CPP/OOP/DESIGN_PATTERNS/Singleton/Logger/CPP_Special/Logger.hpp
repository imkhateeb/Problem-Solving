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

  // To avoid unwanted instantiation we have to make copy constructor and equal to operator overloading also as private.
  Logger(const Logger &);
  Logger operator=(const Logger &);

  // In C++ also take care of equal to delete

public:
  static Logger *getInstance();
  void Log(std::string msg);
};

#endif
