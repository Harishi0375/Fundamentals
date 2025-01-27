#include <iostream>
#include <vector>
#include <headerfile.h>

int main() {
    std::vector<int> arr {16, 4, 10, 14, 7, 9, 3, 2};
    bottomUpHeapSort(arr);

    std::cout << "Sorted array: ";
    for (int num : arr) {
        std::cout << num << " ";
    }
    std::cout << std::endl;

    return 0;
}
