#include <iostream>
#include <deque>

using namespace std;

int main()
{
    deque<float>dequeA;

    float value;
    cin >> value;
    while(value != 0)
    {
        if (value > 0)
        {
            dequeA.push_back(value);
        }else{
            dequeA.push_front(value);
        }
        cin >> value;
    }

    deque<float>::iterator itA = dequeA.begin();
    cout << "deque A: " << endl;
    while (itA != dequeA.end())
    {
        cout << *itA << " ";
        ++itA;
    }

    cout << endl;

    cout << "------------------------------" << endl; //empty line

    itA = dequeA.begin() + (dequeA.size() / 2);
    dequeA.insert(itA, 0);

    for (itA = dequeA.begin(); itA != dequeA.end(); itA++)
    {
        cout << *itA;
        if (itA != dequeA.end() - 1)
        {
            cout << "; ";
        }
    }

    return 0;
}