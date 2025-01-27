#include "fib.h"
#include <iostream>
#include <fstream>
#include <chrono>


// programtically check time for any file and any fib func
// checks also if the time limit has been exceeded or if number is negative
// to prevent pointless computation as then there is prolly a data overflow
void measure_time(std::ofstream& file, long long int (*func)(int), int time_limit) {
    // so this namespace is local
    using namespace std::chrono;

    file << "i,result,miliseconds" << std::endl;
    for (int i = 0; i < 300; i++) {
        auto start = high_resolution_clock::now();
        long long int result = func(i);
        auto end = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(end - start).count();
        if (time_limit < duration || result < 0)
            return; 
        
        file << i << "," << result << "," << duration << std::endl;
    }

    return;
}

int main() {
    const int time_limt = 3; // milliseconds

    std::ofstream naive("naiv_data.csv");
    std::ofstream bottom("bottom_data.csv");
    std::ofstream closed("closed_data.csv");
    std::ofstream matrix("matrix_data.csv");
    
    measure_time(naive, naiv_fib, time_limt);
    measure_time(bottom, bottom_up_fib, time_limt);
    measure_time(closed, closed_fib, time_limt);
    measure_time(matrix, matrix_fib, time_limt);

    return 0;
}