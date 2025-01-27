#include <vector>
#include <iostream>
#include <string>

int main()
{
    std::vector<std::string> stringv;
    std::string data;

    while (std::cin >> data && data != "END")
    {
        stringv.push_back(data);

    }

    if ((stringv[1].empty() || stringv[4].empty()) == false)
    {
        stringv[1].swap(stringv[4]);
    }

    int last_element = distance(stringv.begin(),stringv.end()) - 1;

    stringv[last_element] = "???"; 

    std::vector<std::string>::iterator it;
    for (it = stringv.begin(); it != stringv.end(); it++)
    {
        std::cout << *it;
        if (it != stringv.end() - 1)
        {
            std::cout << ", ";
        }
    }

    std::cout << std::endl;

    return 0;
    
}