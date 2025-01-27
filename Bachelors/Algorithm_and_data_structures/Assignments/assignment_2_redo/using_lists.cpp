#include <iostream>
#include <list>
#include <fstream>
#include <algorithm>

using namespace std;

int main()
{
    list<int> A,B;
    int num;
    while (cin >> num && num > 0)
    {
        A.push_back(num);
        B.push_front(num);
    }

    list<int>::iterator itA = A.begin();
    list<int>::iterator itB = B.begin();
    
    cout << "List A: " << endl;
    while (itA != A.end())
    {
        cout << *itA << " ";
        ++itA;
    }

    ofstream outFile("listB.txt");

    if (outFile.is_open())
    {
        while (itB != B.end())
        {
            outFile << *itB << " ";
            ++itB;
        }
        outFile.close();
    }
    
    cout << endl;

    //swaping elements
    swap(A.front(),A.back());
    swap(B.front(),B.back());

    // append the first element and then pop the first element
    A.push_back(A.front());
    A.pop_front();

    B.push_back(B.front());
    B.pop_front();


    cout << "list A" << endl;
    list<int>::iterator NewitA;
    for (NewitA = A.begin(); NewitA != A.end(); ++NewitA)
    {
        cout << *NewitA;
        if (next(NewitA) != A.end())
            cout << ", ";
        ++NewitA;
    }

    cout << endl;

    cout << "list B" << endl;
    list<int>::iterator NewitB;
    for (NewitB = B.begin(); NewitB != B.end(); ++NewitB)
    {
        cout << *NewitB;
        if (next(NewitB) != B.end())
            cout << ", ";
        ++NewitB;
    }


    cout << endl;

    A.merge(B);

    A.sort();

    itA = A.begin(); // Resetting iterator to the beginning

    cout << "List A: " << endl;
    while (itA != A.end())
    {
        cout << *itA << " ";
        ++itA;
    }

    cout << endl;

    return 0;



    

    

}