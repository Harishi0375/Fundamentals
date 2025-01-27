#include <iostream>
#include <vector>
#include <algorithm>
#include <chrono>
#include <fstream>

void merge(std::vector<int> &arr, int p, int q, int r);
void insertionSort(std::vector<int> &arr, int p, int r);
void mergeSort(std::vector<int> &arr, int p, int r, int k);


std::vector<int> bestCase(int size);
std::vector<int> worstCase(int size);
std::vector<int> averageCase(int size);

int interval = 100000;
const int k = 90;


int main() {
    std::ofstream best("best_case_90.txt");
    std::ofstream worst("worst_case_90.txt");
    std::ofstream avg("avg_case_90.txt");

    for (int i = 0; i < 10000; i += 10) {
        std::vector<int> best_case = bestCase(i);
        auto start = std::chrono::high_resolution_clock::now();
        int endv = static_cast<int>(std::distance(best_case.begin(), best_case.end()));
        mergeSort(best_case, 0, endv , k);
        auto end = std::chrono::high_resolution_clock::now();
        using namespace std::chrono;
        best << i << " " << duration_cast<milliseconds>(end - start).count() << std::endl;
    }

    best.close();

    for (int i = 0; i < 10000; i += 10) {
        std::vector<int> worst_case = worstCase(i);
        auto start = std::chrono::high_resolution_clock::now();
        int endv = static_cast<int>(std::distance(worst_case.begin(), worst_case.end()));
        mergeSort(worst_case, 0, endv, k);
        auto end = std::chrono::high_resolution_clock::now();
        using namespace std::chrono;
        worst << i << " " << duration_cast<milliseconds>(end - start).count() << std::endl;
    }

    worst.close();

    for (int i = 0; i < 10000; i += 10) {
        std::vector<int> avg_case = bestCase(i);
        auto start = std::chrono::high_resolution_clock::now();
        int endv = static_cast<int>(std::distance(avg_case.begin(), avg_case.end()));
        mergeSort(avg_case, 0, endv , k);
        auto end = std::chrono::high_resolution_clock::now();
        using namespace std::chrono;
        avg << i << " " << duration_cast<milliseconds>(end - start).count() << std::endl;
    }

    avg.close();

}


void insertionSort(std::vector<int> &arr, int p, int r) {
    for (int j = p + 1; j <= r; j++) {
        int key = arr[j];
        int i = j - 1;
        while (i > p - 1 && arr[i] > key) {
            arr[i + 1] = arr[i];
            i--;
        }
        arr[i + 1] = key;
    }

    return;
}

// helper func 
void merge(std::vector<int> &arr, int p, int q, int r) {
    std::vector<int> left, right;
    
    for (int i = p; i <= q; i++)
        left.push_back(arr[i]);
    
    for (int i = q + 1; i <= r; i++)
        right.push_back(arr[i]);

    left.push_back(interval);
    right.push_back(interval);
    
    int i = 0, j = 0;
    for (int k = p; k <= r; k++) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        } else {
            arr[k] = right[j];
            j++;
        }
    }
}

void mergeSort(std::vector<int> &arr, int p, int r, int k) {
    if (r - p + 1 <= k) {
        insertionSort(arr, p, r);
        return;
    }
    
    int q = (p + r - 1) / 2;
    
    mergeSort(arr, p, q, k);
    
    mergeSort(arr, q + 1, r, k);
    
    merge(arr, p, q, r);

    return; 
}

// best case is an already sorted array
std::vector<int> bestCase(int n) {
    std::vector<int> arr;
    for (int i = 0; i < n; i++)
        arr.push_back(rand() % 100);

    std::sort(arr.begin(), arr.end());
    return arr;
}

// worst case would be an array in the reverse order
std::vector<int> worstCase(int n) {
    std::vector<int> arr;
    for (int i = 0; i < n; i++)
        arr.push_back(rand() % 100);

    std::sort(arr.begin(), arr.end(), std::greater<int>());
    return arr;
}

// average case is just random  numebers with no particular order
std::vector<int> averageCase(int n) {
    std::vector<int> arr;
    for (int i = 0; i < n; i++)
        arr.push_back(rand() % 100);

    return arr;
}