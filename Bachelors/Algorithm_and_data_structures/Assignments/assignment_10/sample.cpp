#include <vector>
#include <iostream>
#include <algorithm>
#include <functional>

void operator<<(std::ostream &s, const std::vector<int> &vec)
{
    for(const auto& v : vec)
    {
        s << v << " ";
    }

    s << "\n";
}
std::vector<int> heapSort(const std::vector<int> &input)
{
    std::vector<int> output{input};

    std::function<void(const size_t&, const int& maxIdx)> heapify;

    heapify = [&](const size_t& size, const size_t& maxIdx){

        size_t maxIndex = maxIdx;

        size_t leftIndex = 2 * maxIndex + 1;
        size_t rightIndex = 2 * maxIndex + 2;

        if(leftIndex < size && output[maxIndex] < output[leftIndex])
        {
            maxIndex = leftIndex;
        }

        if(rightIndex < size && output[maxIndex] < output[rightIndex])
        {
            maxIndex = rightIndex;
        }

        if(maxIndex != maxIdx)
        {
            std::swap(output[maxIdx], output[maxIndex]);
            heapify(size, maxIndex);
        }
    };

    for (int index = input.size() / 2 - 1; index >= 0; index--)
        heapify(input.size(), index);

    for (int index = input.size()  - 1; index >= 0; index--)
    {
        std::swap(output[0], output[index]);
        heapify(index, 0);
    }


    return output;
}


std::vector<int> heapSort1(const std::vector<int> &input)
{
    std::vector<int> output{input};

    std::function<void(const size_t&, const int& maxIdx)> heapify;

    heapify = [&](const size_t& size, const size_t& currentIndex){

        size_t Largest = currentIndex;

        size_t leftIndex = 2 * Largest + 1;
        size_t rightIndex = 2 * Largest + 2;

        if(leftIndex < size && output[Largest] < output[leftIndex])
        {
            Largest = leftIndex;
        }

        else if(rightIndex < size && output[Largest] < output[rightIndex])
        {
            Largest = rightIndex;
        }

        if(Largest != currentIndex)
        {
            std::swap(output[currentIndex], output[Largest]);
            heapify(size, Largest);
        }
    };

    for (int index = (input.size() / 2) - 1; index >= 0; --index)
    {
        heapify(input.size(), index);
    }
    for (int index = input.size() - 1; index >= 0;--index)
    {
        std::swap(output[0], output[index]);
        heapify(index, 0);

    }


    return output;
}

int main()
{
    std::vector<int> input = {4, 2, 1, 5, 3, 2, 7};
    std::vector<int> expected = {1, 2, 2, 3, 4, 5, 7};
    std::vector<int> output = heapSort(input);

    std::cout << "output: \n";
    std::cout << output;
    std::cout << "expected: \n";
    std::cout << expected;
}