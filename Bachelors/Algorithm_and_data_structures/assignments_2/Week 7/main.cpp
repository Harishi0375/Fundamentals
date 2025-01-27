#include <iostream>
#include <fstream>
#include <chrono>
#include "quick.h"


using namespace std::chrono;

int main() { 
    const int totalData = 100000;
    const int arrayrSize = 1000;
    std::ofstream lomuto("lomuto.csv");
    std::ofstream hoare("hoare.csv");
    std::ofstream median("median_3.csv");


    int **bigData = new int*[totalData];

    for (int i = 0; i < totalData; i++) {
        bigData[i] = createArray(arrayrSize);
    }

    // Copy big data twice cuz quicksort will sort the array
    int **bigDataCopy1 = new int*[totalData];
    int **bigDataCopy2 = new int*[totalData];

    for (int i = 0; i < totalData; i++) {
        bigDataCopy1[i] = new int[arrayrSize];
        bigDataCopy2[i] = new int[arrayrSize];
        std::copy(bigData[i], bigData[i] + arrayrSize, bigDataCopy1[i]);
        std::copy(bigData[i], bigData[i] + arrayrSize, bigDataCopy2[i]);
    }
    
    for (int i = 0; i < totalData; i++) {
        auto start = high_resolution_clock::now();
        quickSort(bigData[i], 1, arrayrSize-1, lomutoPartition);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start).count();
        lomuto << i << "," << duration << std::endl;
    }

    for (int i = 0; i < totalData; i++) {
        auto start = high_resolution_clock::now();
        quickSort(bigDataCopy1[i], 1, arrayrSize-1, hoarePartition);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start).count();
        hoare << i << "," << duration << std::endl;
    }

    for (int i = 0; i < totalData; i++) {
        auto start = high_resolution_clock::now();
        quickSort(bigDataCopy2[i], 1, arrayrSize-1, medianOfThreePartition);
        auto stop = high_resolution_clock::now();
        auto duration = duration_cast<milliseconds>(stop - start).count();
        median << i << "," << duration << std::endl;
    }
    
    return 0;

}