#ifndef _QUICK_H_
#define _QUICK_H_

/*
    choses last element as partition and smaller as the index
    then itterate through the array and splits the array in 2, left which
    is smaller than the partion and right, which is larger than the patition
*/
int lomutoPartition(int arr[], int low, int high);
int hoarePartition(int arr[], int low, int high);
int medianOfThree(int arr[], int low, int high);
int medianOfThreePartition(int arr[], int low, int high);
void quickSort(int arr[], int low, int high, int (*part)(int[], int, int));
int* createArray(int n);

#endif // _QUICK_H_