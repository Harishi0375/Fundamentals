#include <vector>
#include <iostream>
#include <string>

int main(int argc, char** argv)
{
    std::vector<std::string>vstring;
    std::string data;
    while (std::cin >> data && data != "END")
    {
        vstring.push_back(data);
    }
    
    for (unsigned int i = 0; i < vstring.size(); i++)
    {
        std::cout << vstring[i]; //using index operator
        if (i < vstring.size() - 1)
        {
            std::cout << " ";
        }
    }
    
    std::cout << std::endl;

    //comma
    std::vector<std::string>::iterator it;
    for (it = vstring.begin(); it != vstring.end(); it++)
    {
        std::cout << *it;
        if (it != vstring.end() - 1)
        {
            std::cout << ", ";
        }
    }

    std::cout << std::endl;
    
    
}