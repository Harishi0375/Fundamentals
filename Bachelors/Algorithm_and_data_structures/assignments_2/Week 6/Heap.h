#ifndef HEAP_H
#define HEAP_H

#include <vector>
#include <iostream>


void heapify(std::vector<int>& arr, int n, int i);
void heapSort(std::vector<int>& arr);
void printArray(const std::vector<int>& arr);
void bottomUpHeapSort(std::vector<int>& arr);

#endif // HEAP_H
