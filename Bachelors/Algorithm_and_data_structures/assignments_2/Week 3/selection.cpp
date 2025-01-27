#include <iostream>
#include <chrono>
#include <fstream>


// a)
template <class T>
void selection_sort(T array[], int size) {

    for (int i = 0; i < size-1; i++) {
        for (int j = i+1; j < size; j++) {
            if (array[j] < array[i])
                std::swap(array[j], array[i]);
        }
    }

    return;
}

/*
b)
Selection sort is true if 
    A[0:size-1] is sorted in ascending order after the algorithm terminates.
    This for each itteration the sub array A[0:i] must be true:
    with the example of A = {5, 3, 6, 8, 1, 2, 9, 4, 7, 0}, size = 10 

so the loop inveriant is always
A[0:i] is sorted in ascending order
*/


/* 
c)

Case A is a partially sorted array but with the smallest element being the
last one (e.g. 1,2,3,4,5,0 ) n = 6 O(n^2)
*/
int* generate_arrayA(int size) {
    int* result = new int[size];
    for (int i = 0; i < size; i++) {
        result[i] = rand() % 1000 + 1;
    }

    std::sort(result, result + size);
    std::swap(result[size-1], result[0]);

    return result;
}

/*
CASE B is an already sorted array so that the algorithm does not need to do anything 
and gives us an O(n)
*/
int* generate_arrayB(int size) {
    int* result = new int[size];
    for (int i = 0; i < size; i++) {
        result[i] = rand() % 1000 + 1;
    }

    std::sort(result, result + size);
    return result;
}

/*
e)
For my data input size, there is not much of a difference between Big O and Big Omega
In my idea, that is because the algorithm has yet reached the n_0 size from where the 
scalabbility and asymptotic properties of the algorithm can be observed. So it seems like
both worst and best case are similar apart from the spike in Worst case

As for the best case, it shows the asymptotic bound of O(n^2) as the algorithm and is clearly
bounded by n^2 upper and n lower.
*/

int main() {
    // create array of 10 elements of type int
    int array[10] = { 5, 3, 6, 8, 1, 2, 9, 4, 7, 0 };


    // call the selection_sort function
    selection_sort(array, 10);
    

    for (const int i : array)
        std::cout << i << " ";

    int* meow = generate_arrayA(10);

    std::cout << "\nCASE A BEfORE" << std::endl;

    for (int i = 0; i < 10; i++)
        std::cout << meow[i] << " ";

    std::cout << "\nCASE A AFTER" << std::endl;

    selection_sort(meow, 10);

    for (int i = 0; i < 10; i++)
        std::cout << meow[i] << " ";

    int* meow2 = generate_arrayA(10);

    std::cout << "\nCASE B BEFORE" << std::endl;

        for (int i = 0; i < 10; i++)
        std::cout << meow2[i] << " ";

    selection_sort(meow2, 10);

    std::cout << "\nCASE B AFTER" << std::endl;

    for (int i = 0; i < 10; i++)
        std::cout << meow2[i] << " ";

    delete[] meow;
    delete[] meow2;


    // std::ofstream file("DataB.txt");

    // for (int i = 0; i < 8000; i++) {
    //     int* meow = generate_arrayB(i);
    //     // measure time here
    //     auto start = std::chrono::high_resolution_clock::now();
    //     selection_sort(meow, i);
    //     auto end = std::chrono::high_resolution_clock::now();

    //     file<< i << " " << std::chrono::duration_cast<std::chrono::milliseconds>(end - start).count() << std::endl;

    //     delete[] meow;
    // }

    return 0;
}