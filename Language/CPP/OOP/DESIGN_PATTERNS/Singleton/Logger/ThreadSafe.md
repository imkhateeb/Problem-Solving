This code demonstrates a thread-safe Singleton design pattern implementation in C++ for a `Logger` class. Here's a breakdown of how it works:

### Key Concepts:

1. **Singleton Pattern**: Ensures that only one instance of `Logger` exists in the system. The `Logger` class has a private constructor and a static method `getInstance()` to control instance creation.
2. **Thread-Safety**: The code uses a `mutex` to synchronize access to the instance creation process, ensuring that only one thread can create the `Logger` instance at any given time.

### Logger.hpp:

- The `Logger` class has a private constructor to prevent direct instantiation.
- The `getInstance()` method ensures the singleton property.
- A `mutex` is used to lock the code section where the instance is created.

### Logger.cpp:

- The static pointer `instance` is initialized to `NULL` (or `nullptr` in modern C++).
- The `getInstance()` method implements lazy initialization (the `Logger` object is created only when it is first needed).
- A double-checked locking mechanism is used for thread safety:
  - The first `if (!instance)` check avoids unnecessary locking once the `Logger` instance is created.
  - The second check after acquiring the lock ensures that no other thread has created the instance while waiting to acquire the lock.
- The `Log()` method is used to output messages to the console.

### Client.cpp:

- Two threads (`t1` and `t2`) call `getInstance()` to log messages. Since `Logger` is a singleton, both threads will use the same instance.

### Suggestions:

1. **Memory Management**: The singleton object is created dynamically, but there is no mechanism to clean it up (e.g., using a destructor or smart pointers). This could cause a memory leak. To address this, you can implement the cleanup either using a static destructor or by using smart pointers.
2. **Improving Mutex Handling**: Using `std::lock_guard` or `std::unique_lock` for managing the mutex is preferred over manually locking and unlocking to avoid potential issues like forgetting to release the lock in case of exceptions.

### Suggested Improvements:

1. **Replace manual mutex lock/unlock with `std::lock_guard`:**

```cpp
Logger *Logger::getInstance()
{
  if (!instance)
  {
    lock_guard<mutex> lock(mtx);  // Automatically locks and unlocks the mutex
    if (instance == NULL)
    {
      instance = new Logger();
    }
  }
  return instance;
}
```

2. **Use `nullptr` instead of `NULL` in modern C++:**

```cpp
Logger *Logger::instance = nullptr;
```

This improves the code clarity and adheres to modern C++ standards.

### Complete Example with Suggested Changes:

#### Logger.hpp

```cpp
#ifndef LOGGER_H
#define LOGGER_H
#include <string>
#include <mutex>

class Logger
{
private:
  static Logger *instance;
  static int count;
  static std::mutex mtx;
  Logger();

public:
  static Logger *getInstance();
  void Log(std::string msg);
};

#endif
```

#### Logger.cpp

```cpp
#include <iostream>
#include "Logger.hpp"

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
    std::lock_guard<std::mutex> lock(mtx);  // Use lock_guard for RAII mutex handling
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
```

#### Client.cpp

```cpp
#include <iostream>
#include <thread>
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
  std::thread t1(user1Logs);
  std::thread t2(user2Logs);

  t1.join();
  t2.join();

  return 0;
}
```

This ensures proper mutex handling and adherence to modern C++ practices.
