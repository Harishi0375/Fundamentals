#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <iostream>
#include <vector>


// ANSWER FOR PROBLEM 6.2 (A)
void maxHeapify(std::vector<int>& A, int i, int heapSize) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest;

    if (l < heapSize && A[l] > A[i]) {
        largest = l;
    } else {
        largest = i;
    }

    if (r < heapSize && A[r] > A[largest]) {
        largest = r;
    }

    if (largest != i) {
        std::swap(A[i], A[largest]);
        maxHeapify(A, largest, heapSize);
    }
}

void buildMaxHeap(std::vector<int>& A) {
    for (int i = A.size() / 2 - 1; i >= 0; --i) {
        maxHeapify(A, i, A.size());
    }
}

void heapSort(std::vector<int>& A) {
    buildMaxHeap(A);
    int heapSize = A.size();

    for (int i = A.size() - 1; i >= 1; --i) {
        std::swap(A[0], A[i]);
        --heapSize;
        maxHeapify(A, 0, heapSize);
    }
}



// ANSWER FOR PROBLEM 6.2(B)
void maxHeapify(std::vector<int>& A, int i, int heapSize) {
    int l = 2 * i + 1;
    int r = 2 * i + 2;
    int largest;

    if (l < heapSize && A[l] > A[i]) {
        largest = l;
    } else {
        largest = i;
    }

    if (r < heapSize && A[r] > A[largest]) {
        largest = r;
    }

    if (largest != i) {
        std::swap(A[i], A[largest]);
        maxHeapify(A, largest, heapSize);
    }
}

void buildMaxHeap(std::vector<int>& A) {
    for (int i = A.size() / 2 - 1; i >= 0; --i) {
        maxHeapify(A, i, A.size());
    }
}

void bottomUpHeapify(std::vector<int>& A, int i, int heapSize) {
    int parent = (i - 1) / 2;

    while (i > 0 && A[i] > A[parent]) {
        std::swap(A[i], A[parent]);
        i = parent;
        parent = (i - 1) / 2;
    }
}

void bottomUpHeapSort(std::vector<int>& A) {
    buildMaxHeap(A);

    for (int i = A.size() - 1; i >= 1; --i) {
        std::swap(A[0], A[i]);
        maxHeapify(A, 0, i);
        bottomUpHeapify(A, i, i);
    }
}
#endif