#include "Heap.h"
#include <chrono>
#include <fstream>

using namespace std::chrono;

std::vector<int> rand_gen(int size) {
    std::vector<int> result(size, 0);

    std::srand(time(0)); 

    std::generate(result.begin(), result.end(), rand);

    return result; 
}


int main() {
    std::cout << "Hello World\n";
    std::ofstream regular_heap("Regular_heap_sort.csv");
    std::ofstream bottom_up_heap("bottom_up_heap_sort.csv");

    for (int i = 0; i < 20000; i++) {
        auto start = high_resolution_clock::now();
        
        std::vector<int> meow = rand_gen(i);

        heapSort(meow);

        auto end = high_resolution_clock::now();

        auto duration = duration_cast<milliseconds>(end - start).count();
        
        regular_heap << i <<  "," << duration << std::endl;
    }

    for (int i = 0; i < 20000; i++) {
        auto start = high_resolution_clock::now();
        
        std::vector<int> meow = rand_gen(i);
        bottomUpHeapSort(meow);

        auto end = high_resolution_clock::now();


        auto duration = duration_cast<milliseconds>(end - start).count();
        
        bottom_up_heap << i <<  "," << duration << std::endl;
    }

    regular_heap.close();
    bottom_up_heap.close();

    return 0;
}