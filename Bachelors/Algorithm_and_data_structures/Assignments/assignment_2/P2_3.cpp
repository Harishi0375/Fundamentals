#include <headerfile.h>
#include <iostream>


//contains both the contains both the cpp files in one 

WindGuage::WindGuage(int period) : period(period) {}

void WindGuage::currentWindSpeed(int speed) {
    history.push_back(speed);
    if (history.size() > period) {
        history.erase(history.begin());
    }
}

int WindGuage::highest() const {
    return *max_element(history.begin(), history.end());
}

int WindGuage::lowest() const {
    return *min_element(history.begin(), history.end());
}

int WindGuage::average() const {
    int sum = 0;
    for (int speed : history) {
        sum += speed;
    }
    return sum / history.size();
}

void WindGuage::dump() const {
    cout << "Lowest: " << lowest() << endl;
    cout << "Highest: " << highest() << endl;
    cout << "Average: " << average() << endl;
}


int main() {
    WindGuage gauge;

    // Adding five wind speeds
    gauge.currentWindSpeed(15);
    gauge.currentWindSpeed(16);
    gauge.currentWindSpeed(12);
    gauge.currentWindSpeed(15);
    gauge.currentWindSpeed(15);

    // Dump the gauge
    gauge.dump();

    // Adding ten more wind speeds
    gauge.currentWindSpeed(16);
    gauge.currentWindSpeed(17);
    gauge.currentWindSpeed(16);
    gauge.currentWindSpeed(16);
    gauge.currentWindSpeed(20);
    gauge.currentWindSpeed(17);
    gauge.currentWindSpeed(16);
    gauge.currentWindSpeed(15);
    gauge.currentWindSpeed(16);
    gauge.currentWindSpeed(20);

    // Dump the gauge again
    gauge.dump();

    return 0;
}