#include "quick.h"
#include <algorithm>

int lomutoPartition(int arr[], int low, int high) {
    int pivot = arr[low];
    int i = low;

    for (int j = low+1; j <= high; j++) {
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }

    std::swap(arr[low], arr[i]);

    }

    return i;
}

int hoarePartition(int arr[], int low, int high) {

    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;

    while (true) {
        do { 
            i++; 
        } while (arr[i] < pivot); 

        // Find rightmost element smaller than 
        // or equal to pivot 
        do { 
            j--; 
        } while (arr[j] > pivot); 

        // If two pointers met. 
        if (i >= j) 
            return j; 

        std::swap(arr[i], arr[j]); 
    }
}

int medianOfThree(int arr[], int low, int high) {
    int mid = low + (high - low) / 2;

    if (arr[low] > arr[mid])
        std::swap(arr[low], arr[mid]);
    if (arr[low] > arr[high])
        std::swap(arr[low], arr[high]);
    if (arr[mid] > arr[high])
        std::swap(arr[mid], arr[high]);

    // Median is at 'mid'
    return arr[mid];
}

// Partitioning function
int medianOfThreePartition(int arr[], int low, int high) {
    int pivot = medianOfThree(arr, low, high);
    int i = low - 1;

    for (int j = low; j <= high; j++) {  // Changed loop condition to j <= high
        if (arr[j] <= pivot) {
            i++;
            std::swap(arr[i], arr[j]);
        }
    }
    std::swap(arr[i + 1], arr[high]);
    return i + 1;
}


void quickSort(int arr[], int low, int high, int (*part)(int[], int, int)) {
    if (low > high)
        return;

    int pivot = part(arr, low, high);

    quickSort(arr, low, pivot-1, part);
    quickSort(arr, pivot+1, high, part);

    return;
}

int* createArray(int n) {
    int* arr = new int[n];
    srand(time(0)); // Seed the random number generator

    for (int i = 0; i < n; i++) {
        arr[i] = rand();
    }

    return arr;
}