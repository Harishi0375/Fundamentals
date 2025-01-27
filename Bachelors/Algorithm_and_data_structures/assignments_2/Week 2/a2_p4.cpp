//
// Created by Nikolay Tsonev on 14/02/2024.
//

#include <iostream>
#include <vector>
#include <algorithm>

int main() {

    // init and fill the vec
    std::vector<int> vint;

    for (int i=1; i < 31; i++)
        vint.push_back(i);

    vint.push_back(5);

    // reverser qand print it
    std::reverse(vint.begin(), vint.end());

    std::vector<int>::iterator vitor;
    for (vitor = vint.begin(); vitor != vint.end(); vitor++)
        std::cout << *vitor << " ";

    std::cout << std::endl;


    // replace all 5s with 129 and print the result
    std::replace(vint.begin(), vint.end(), 5, 129);


    for (vitor = vint.begin(); vitor != vint.end(); vitor++)
        std::cout << *vitor << " ";

    return 0;
}
