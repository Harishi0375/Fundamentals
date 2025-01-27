//
// Created by Nikolay Tsonev on 14/02/2024.
//

#include "WindGauge.h"
#include <iostream>

WindGauge::WindGauge(int period) : period(period), taken(0) {}

void WindGauge::currentWindSpeed(int speed) {
    if (this->taken == this->period) {
        this->windSpeed.pop_front();
        this->windSpeed.push_back(speed);
        return;
    }

    this->windSpeed.push_back(speed);
    this->taken++;

    return;
}

int WindGauge::highest() const {
    int result = 0;

    // iterate through the deque and find the highest
    for (int i = 0; i < this->taken; i++) {
        if (this->windSpeed[i] > result) {
            result = this->windSpeed[i];
        }
    }

    return result;
}

int WindGauge::lowest() const {
    int result = 0;

    // iterate through the deque and find the lowest
    for (int i = 0; i < this->taken; i++) {
        if (this->windSpeed[i] < result) {
            result = this->windSpeed[i];
        }
    }

    return result;
}

int WindGauge::average() const {
    int result = 0;


    for (int i = 0; i < this->taken; i++) {
        result += this->windSpeed[i];
    }

    return result / this->taken;
}

void WindGauge::dump() const {
    for (int i = 0; i < this->taken; i++)
        std::cout << this->windSpeed[i] << " ";
}