//
// Created by Nikolay Tsonev on 14/02/2024.
//

#ifndef WEEK_2_WINDGAUGE_H
#define WEEK_2_WINDGAUGE_H

#include <deque>

class WindGauge {
public:
    WindGauge(int period = 12);
    void currentWindSpeed(int speed);
    int highest() const;
    int lowest() const;
    int average() const;
    void dump() const;
private:
    int period;
    int taken;
    std::deque<int> windSpeed;
};


#endif //WEEK_2_WINDGAUGE_H
