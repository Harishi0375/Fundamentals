//
// Created by Nikolay Tsonev on 14/02/2024.
//

#include <iostream>
#include "WindGauge.h"

int main() {

    WindGauge w;


    w.currentWindSpeed(15);
    w.currentWindSpeed(16);
    w.currentWindSpeed(12);
    w.currentWindSpeed(15);
    w.currentWindSpeed(15);

    w.dump();

    std::cout << std::endl;
    // should remove the first few elements
    w.currentWindSpeed(16);
    w.currentWindSpeed(17);
    w.currentWindSpeed(16);
    w.currentWindSpeed(16);
    w.currentWindSpeed(20);
    w.currentWindSpeed(17);
    w.currentWindSpeed(16);
    w.currentWindSpeed(15);
    w.currentWindSpeed(16);
    w.currentWindSpeed(20);

    w.dump();




    return 0;
}

