#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main()
{
    list<int> a,b;
    vector<list<int>> vector_list;

    a.push_back(1);
    a.push_back(2);
    a.push_back(3);

    b.push_back(4);
    b.push_back(5);

    vector_list.push_back(a);
    vector_list.push_back(b);
    
    // vector<list<int>>::iterator itvec;
    for(auto itvec = vector_list.begin() ; itvec != vector_list.end() ; ++itvec)
    {
        // list<int>::iterator itlist;
        cout << "vector-" << distance(vector_list.begin(), itvec) << ": ";
        for(auto itlist = itvec->begin(); itlist != itvec->end(); ++itlist)
        {
            cout << *itlist << " ";
        }
        cout << endl;
    }
    
}