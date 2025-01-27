#include <typeinfo>
#include <vector>
#include <iostream>

using namespace std;

int main()
{
    vector<int>myVecint = {1};
    vector<double>myDoubleInt = {1.1};

    decltype(myVecint[0]+myDoubleInt[0])myDouble = 1;
    
    cout << typeid(myDouble).name() << endl;
}