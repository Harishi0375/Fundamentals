#include <iostream>

template <class T>
T array_search(T arr[],int size,T num)
{
    for (int i = 0; i < num; i++)
    {
        if (arr[i] == num)
        {
            return i;
        }
    }
    return -1;
}

int main()
{
    int arr1[] = {1,2,3,4,5,6};
    float arr2[] = {1.1,2.1,2.3,2.4,5.0};

    std::cout << array_search(arr1,6,5) << std::endl;

    std::cout << array_search<float>(arr2,5,3) << std::endl;

    return 0;
}