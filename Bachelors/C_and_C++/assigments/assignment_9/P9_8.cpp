/*
  CH-230-A
  a9_p8.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
using namespace std;

void subtract_max(int *arr, int n) {
    int max = arr[0];
    for (int i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }

    std::cout << "new array: ";
    for (int i = 0; i < n; i++) {
        arr[i] = arr[i] - max;
        std::cout << arr[i];
        if (i != n - 1) {
            std::cout << ", ";
        }
    }
    std::cout << std::endl;
}

void deallocate(int *arr)
{
   delete[] arr; //deallocation
}

int main()
{
    int n;
    std::cout << "enter size of array: ";
    std::cin >> n;

    int *a = new int[n]; //dynamic allocation of memory

    std::cout << "enter values for your array:" << std::endl;
    for (int i = 0; i < n; i++)
    {
        std::cin >> a[i];
    }

    subtract_max(a,n);
    deallocate(a);
}