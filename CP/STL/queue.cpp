#include <iostream>
#include <queue>

int main() {
    std::queue<int> myQueue;

    // Push elements into the queue
    myQueue.push(10);
    myQueue.push(20);
    myQueue.push(30);

    // Access the front and back elements
    std::cout << "Front of queue: " << myQueue.front() << std::endl;
    std::cout << "Back of queue: " << myQueue.back() << std::endl;

    // Pop element from the queue
    myQueue.pop();

    // Check if the queue is empty
    if (!myQueue.empty()) {
        std::cout << "Queue is not empty. Size: " << myQueue.size() << std::endl;
    }


    return 0;
}
