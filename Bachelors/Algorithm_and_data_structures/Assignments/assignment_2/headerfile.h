#ifndef HEADERFILE_H
#define HEADERFILE_H

#include <vector>
using namespace std;

class WindGuage{
    private:
        vector<int> history;
        int period;
    public:
        WindGuage(int period = 12);
        void currentWindSpeed(int speed);
        int highest() const;
        int lowest() const;
        int average() const;
        void dump() const;
        WindGuage(int period);
};

#endif