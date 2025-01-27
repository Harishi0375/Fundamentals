#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <set>

int main()
{
    std::vector<int> intv;
    int num;
    while (std::cin >> num && num >= 1 && num <= 30)
    {
        intv.push_back(num);
    }
    
    intv.push_back(5);
    std::list<int> intl;

    std::set<int> sint;
    sint.
    

    intv.reserve(intv.size());

    std::vector<int>::iterator itv;
    for (itv = intv.begin(); itv != intv.end(); ++itv)
    {
        std::cout << *itv << " ";

    }
    std::cout << std::endl;

    replace(intv.begin(),intv.end(), 5, 129);
    for (itv = intv.begin(); itv != intv.end(); ++itv)
    {
        std::cout << *itv << " ";

    }

    return 0;
}