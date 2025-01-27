#include <iostream>
#include <deque>
#include <algorithm>

class WindGauge
{
    private:
        std::deque<int> history;
        int Period;
    public:
        WindGauge(int period = 12);
        void currentWindSpeed(int speed);
        int highest() const;
        int lowest() const;
        int average() const;
        void dump() const;
};

WindGauge::WindGauge(int period) : Period(period) {}

void WindGauge::currentWindSpeed(int Speed)
{
    if (history.max_size() == 0)
    {
        history.pop_back();
        history.push_front(Speed);
    }
    else
    {
        history.push_front(Speed);
    }
}

int WindGauge::highest() const
{
    int largest = 0;
    for (int i = 0; i < history.size(); ++i)
    {
        if (history[i] > largest)
        {
            largest = history[i];
        }
    }
    return largest;
}

int WindGauge::lowest() const
{
    int low = highest();
    for (int i = 0; i < history.size(); ++i)
    {
        if (history[i] < low)
        {
            low = history[i];
        }
    }
    return low;
}

int WindGauge::average() const
{
    int avg = 0;
    for (int i = 0; i < history.size(); ++i)
    {
        avg += history[i];
    }
    return (avg/history.size());
}

void WindGauge::dump() const
{
    std::cout << "high speed: " << highest() << std::endl;
    std::cout << "low speed: " << lowest() << std::endl;
    std::cout << "average speed: " << average() << std::endl; 

    std::cout << "---------------" << std::endl;
}




int main()
{
    WindGauge ex1;
    ex1.currentWindSpeed(15);
    ex1.currentWindSpeed(16);
    ex1.currentWindSpeed(12);
    ex1.currentWindSpeed(15);
    ex1.currentWindSpeed(15);

    ex1.dump();

    ex1.currentWindSpeed(16);
    ex1.currentWindSpeed(17);
    ex1.currentWindSpeed(16);
    ex1.currentWindSpeed(16);
    ex1.currentWindSpeed(20);
    ex1.currentWindSpeed(17);
    ex1.currentWindSpeed(16);
    ex1.currentWindSpeed(15);
    ex1.currentWindSpeed(16);

    ex1.dump();

    return 0;
}