#include <iostream>
#include <sstream>

int main() {
    // Using std::ostringstream to concatenate strings
    std::ostringstream oss;
    oss << "Hello, ";
    oss << "world!";
    std::string result = oss.str();
    std::cout << result << std::endl;

    // Using std::istringstream to parse strings
    std::string input = "123 456";
    int num1, num2;
    std::istringstream iss(input);
    iss >> num1 >> num2;
    std::cout << "Sum: " << num1 + num2 << std::endl;

    return 0;
}
