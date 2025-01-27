#include <iostream>

// Class template for a generic pair
template <typename T1, typename T2>
class Pair {
public:
    T1 first;
    T2 second;

    Pair(T1 a, T2 b) : first(a), second(b) {}
};

template <class T>
T testdata(T data[],int num)
{
    num = data[0];
    for (int i = 1; i < 5; i++)
    {
        num += data[i];
    }
    return num;
}

int main() {
    Pair<int, double> myPair(5, 3.14);
    std::cout << "First: " << myPair.first << ", Second: " << myPair.second << std::endl;

    int data[] = {1,2,3,4,5};
    int num = 0;
    std::cout << "test" << std::endl;
    std::cout << "return value is: " << testdata(data, num) << std::endl;

    return 0;
}


