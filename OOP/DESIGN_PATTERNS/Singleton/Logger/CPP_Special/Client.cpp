#include <iostream>
#include <thread> // Include <thread> for std::thread
#include "Logger.hpp"

void user1Logs()
{
  Logger *logger1 = Logger::getInstance();
  logger1->Log("Message from logger1");
}

void user2Logs()
{
  Logger *logger2 = Logger::getInstance();
  logger2->Log("Message from logger2");
}

int main()
{
  std::thread t1(user1Logs); // std::thread for multithreading
  std::thread t2(user2Logs);

  t1.join();
  t2.join();

  return 0;
}
