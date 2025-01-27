#include "Heap.h"

// Function to heapify a subtree rooted at index i
void heapify(std::vector<int>& arr, int n, int i) {
    int largest = i; 
    int left = 2 * i + 1;
    int right = 2 * i + 2; 

    
    if (left < n && arr[left] > arr[largest])
        largest = left;

    if (right < n && arr[right] > arr[largest])
        largest = right;

    
    if (largest != i) {
        std::swap(arr[i], arr[largest]);

        heapify(arr, n, largest);
    }
}

// Main function to do heap sort
void heapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        heapify(arr, n, i);

    
    for (int i = n - 1; i > 0; i--) {
        
        std::swap(arr[0], arr[i]);

        
        heapify(arr, i, 0);
    }
}

// modified heap algorithm
void bottomUpHeapSort(std::vector<int>& arr) {
    int n = arr.size();

    // Build max heap
    for (int i = n / 2 - 1; i >= 0; i--) {
        heapify(arr, n, i);
    }

    // Bottom-up heap sort
    for (int i = n - 1; i > 0; i--) {
        // Float the new root all the way down to a leaf level
        std::swap(arr[0], arr[i]);

        int j = 0;
        while (true) {
            int left = 2 * j + 1;
            int right = 2 * j + 2;
            int maxIndex = j;

            if (left < i && arr[left] > arr[maxIndex]) 
                maxIndex = left;
            
            if (right < i && arr[right] > arr[maxIndex]) 
                maxIndex = right;
            
            // Heap property satisfied
            if (maxIndex == j) {
                break; 
            }

            std::swap(arr[j], arr[maxIndex]);
            j = maxIndex;
        }
    }
}

// print an array
void printArray(const std::vector<int>& arr) {
    for (const int i : arr)
        std::cout << i << " ";
    std::cout << std::endl;
}
