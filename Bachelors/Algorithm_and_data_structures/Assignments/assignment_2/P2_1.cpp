#include <iostream>
#include <list>
#include <fstream>

using namespace std;

// Meaningful names
list<int> listA;
list<int> listB;

int main()
{
    int num;
    cin >> num;
    while (num > 0)
    {
        listA.push_back(num);
        listB.push_front(num);
        cin >> num;
    }

    cout << endl;

    list<int>::iterator itA = listA.begin();
    list<int>::iterator itB = listB.begin();

    cout << "List A: " << endl;
    while (itA != listA.end())
    {
        cout << *itA << " ";
        ++itA;
    }

    cout << endl;

    ofstream outFile("listB.txt");

    if (outFile.is_open())
    {
        itB = listB.begin(); // Resetting iterator to the beginning
        while (itB != listB.end())
        {
            outFile << *itB << " ";
            ++itB;
        }
        outFile.close();
    }
    else
    {
        cout << "error" << endl;
        exit(1);
    }

    cout << "------------------------------------------------" << endl; //empty line

    if (!listA.empty())
    {
        int firstA = listA.front();
        listA.pop_front();
        listA.push_back(firstA);
    }

    if (!listB.empty())
    {
        int firstB = listB.front();
        listB.pop_front();
        listB.push_back(firstB);
    }

    itA = listA.begin(); // Resetting iterator to the beginning
    itB = listB.begin(); // Resetting iterator to the beginning

    cout << "List A: " << endl;
    while (itA != listA.end())
    {
        cout << *itA;
        if (next(itA) != listA.end())
            cout << ", ";
        ++itA;
    }

    cout << endl;

    cout << "List B: " << endl;
    while (itB != listB.end())
    {
        cout << *itB;
        if (next(itB) != listB.end())
            cout << ", ";
        ++itB;
    }

    cout << "------------------------------------------------" << endl; //empty line

    listA.merge(listB);

    listA.sort();

    itA = listA.begin(); // Resetting iterator to the beginning

    cout << "List A: " << endl;
    while (itA != listA.end())
    {
        cout << *itA << " ";
        ++itA;
    }

    cout << endl;

    return 0;
}


