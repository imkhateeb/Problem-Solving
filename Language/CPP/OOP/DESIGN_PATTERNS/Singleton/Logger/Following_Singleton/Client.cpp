#include <iostream>

#include "Logger.hpp"

int main()
{

  Logger *logger1 = Logger::getInstance();
  logger1->Log("Message from logger1");

  Logger *logger2 = Logger::getInstance();
  logger2->Log("Message from logger2");

  return 0;
}