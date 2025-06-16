#include <iostream>
#include "Logger.hpp"
#include <mutex> // Include <mutex> here as well

Logger *Logger::instance = nullptr;
int Logger::count = 0;
std::mutex Logger::mtx;

Logger::Logger()
{
  count++;
  std::cout << "Logger created" << std::endl;
  std::cout << "Logger count: " << count << std::endl;
  std::cout << std::endl;
}

Logger *Logger::getInstance()
{
  if (!instance)
  {
    std::lock_guard<std::mutex> lock(mtx); // std::lock_guard for thread-safe access
    if (instance == nullptr)
    {
      instance = new Logger();
    }
  }
  return instance;
}

void Logger::Log(std::string msg)
{
  std::cout << msg << std::endl;
}
