#include <iostream>
#include <tuple>

int main() {
    // Creating a tuple
    std::tuple<int, double, std::string> myTuple(42, 3.14, "hello");

    // Accessing elements of the tuple using std::get
    int intValue = std::get<0>(myTuple);
    double doubleValue = std::get<1>(myTuple);
    std::string stringValue = std::get<2>(myTuple);

    // Printing the elements
    std::cout << "Tuple values: " << intValue << ", " << doubleValue << ", " << stringValue << std::endl;

    return 0;
}
