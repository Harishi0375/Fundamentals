#include <iostream>
#include <vector>

int main()
{
    std::vector<int> arr = {1,2,3,4,5,6};

    //one way to do it
    for(int value : arr)
    {
        std::cout << " " << value;
    }
    std::cout << std::endl;

    //using iterator
    std::vector<int>::iterator itarr;
    for(itarr = arr.begin(); itarr != arr.end(); ++itarr)
    {
       std::cout << " " << *itarr;
    }
    std::cout << std::endl;
    

    return 0;
}