#include <iostream>
#include <deque>

int main() {
    // Declare a deque of integers
    std::deque<int> myDeque;

    // Insert elements at the back of the deque
    myDeque.push_back(10);
    myDeque.push_back(20);
    myDeque.push_back(30);

    // Insert elements at the front of the deque
    myDeque.push_front(5);
    myDeque.push_front(15);

    // Access elements
    std::cout << "Front element: " << myDeque.front() << std::endl;
    std::cout << "Back element: " << myDeque.back() << std::endl;

    // Remove elements from the front and back of the deque
    myDeque.pop_front();
    myDeque.pop_back();

    // Print all elements in the deque
    std::cout << "Elements in the deque: ";
    for (int elem : myDeque) {
        std::cout << elem << " ";
    }
    std::cout << std::endl;

    // Check if deque is empty
    if (myDeque.empty()) {
        std::cout << "Deque is empty" << std::endl;
    } else {
        std::cout << "Deque is not empty" << std::endl;
    }

    // Get the size of the deque
    std::cout << "Size of the deque: " << myDeque.size() << std::endl;

    return 0;
}
