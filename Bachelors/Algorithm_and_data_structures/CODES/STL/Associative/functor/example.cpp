#include <iostream>

// Functor class
class MyFunctor {
public:
    // Overloaded function call operator
    int operator()(int x, int y) {
        return x + y;
    }
};

int main() {
    // Create an instance of the functor
    MyFunctor myFunctor;

    // Call the functor as if it were a function
    int result = myFunctor(3, 4);

    std::cout << "Result: " << result << std::endl; // Output: 7

    return 0;
}
