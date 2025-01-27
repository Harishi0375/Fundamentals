#include <iostream>
#include <deque>

int main()
{
    std::deque<float> A;
    float value;
    while (std::cin >> value && value != 0)
    {
        if (value > 0)
        {
            A.push_front(value);
        }
        else
        {
            A.push_back(value);
        }
    }
    std::cout << std::endl;

    // A.push_back(A.front());
    // A.pop_front();

    for (auto itd = A.begin(); itd != A.end(); ++itd)
    {
        std::cout << *itd << " ";
    }
    std::cout << std::endl;

    auto itd = A.begin() + (A.size() / 2);
    A.insert(itd, 0);

    for (auto itd2 = A.begin(); itd2 != A.end(); ++itd2)
    {
        std::cout << *itd2;
        if (std::next(itd2) != A.end())
            std::cout << "; ";
    }
    std::cout << std::endl;

    return 0;
}
