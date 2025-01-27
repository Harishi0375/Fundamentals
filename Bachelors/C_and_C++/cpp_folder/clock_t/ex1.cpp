#include <iostream>
#include <ctime>
using namespace std;

int main() {
    clock_t start, end;

    start = clock(); // Record the starting time

    int a = 5;
    int result = a*a;
    cout << result << endl;

    end = clock();   // Record the ending time

    double cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
    std::cout << "CPU time used: " << cpu_time_used << " seconds." << std::endl;

    return 0;
}
