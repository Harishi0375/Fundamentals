#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    vector<int>intvector;
    for (int i = 1; i < 31; i++)
    {
        intvector.push_back(i);
    }
    intvector.push_back(5);

    reverse(intvector.begin(),intvector.end());

    vector<int>::iterator it;
    for (it = intvector.begin(); it != intvector.end(); ++it)
    {
        cout << *it << " ";
    }

    cout << endl;

    replace(intvector.begin(),intvector.end(), 5, 129);

    cout << "after replace: " << endl; 
    for (it = intvector.begin(); it != intvector.end(); ++it)
    {
        cout << *it << " ";
    }
    cout << endl;

    return 0;
}