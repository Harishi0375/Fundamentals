#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

/* lis() returns the length of the longest increasing
subsequence in arr[] of size n and also prints the LIS */
void lis(int arr[], int n)
{
    vector<int> lis(n, 1); // Initialize LIS values for all indexes
    vector<int> prev(n, -1); // To keep track of previous indices for LIS

    /* Compute optimized LIS values in bottom up manner */
    for (int i = 1; i < n; i++) {
        for (int j = 0; j < i; j++) {
            if (arr[i] > arr[j] && lis[i] < lis[j] + 1) {
                lis[i] = lis[j] + 1;
                prev[i] = j; // Track the previous index
            }
        }
    }

    /* Find the maximum of all LIS values */
    int maxIndex = 0;
    for (int i = 1; i < n; i++) {
        if (lis[i] > lis[maxIndex]) {
            maxIndex = i;
        }
    }

    // Reconstruct the LIS
    vector<int> sequence;
    for (int i = maxIndex; i >= 0; i = prev[i]) {
        sequence.push_back(arr[i]);
        if (prev[i] == -1) {
            break;
        }
    }

    // The sequence is built in reverse order, so reverse it
    reverse(sequence.begin(), sequence.end());

    // Print the LIS length and sequence
    cout << "Length of LIS is " << lis[maxIndex] << endl;
    cout << "The LIS is: ";
    for (int i = 0; i < sequence.size(); i++) {
        cout << sequence[i] << " ";
    }
    cout << endl;
}

/* Driver program to test above function */
int main()
{
    int arr[] = {3,4,5,6,7,1,2,3,20};
    int n = sizeof(arr) / sizeof(arr[0]);
    lis(arr, n);
    return 0;
}

