#include <iostream>
#include "Logger.hpp"

Logger *Logger::instance = NULL;
int Logger::count = 0;

Logger::Logger()
{
  count++;
  std::cout << "Logger created" << std::endl;
  std::cout << "Logger count: " << count << std::endl;
  std::cout << std::endl;
}

Logger *Logger::getInstance()
{
  if (instance == NULL)
  {
    instance = new Logger();
  }
  return instance;
}

void Logger::Log(std::string msg)
{
  std::cout << msg << std::endl;
}