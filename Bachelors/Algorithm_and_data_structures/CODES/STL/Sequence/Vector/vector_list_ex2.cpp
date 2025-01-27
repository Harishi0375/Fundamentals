#include <iostream>
#include <vector>
#include <list>

using namespace std;

int main() {
    vector<list<int>> myVector = {{1, 2, 3}, {4, 5, 6}, {7, 8, 9}};
    
    // Printing the elements of the vector
    for (auto it = myVector.begin(); it != myVector.end(); ++it) {
        cout << "List at index ";
        cout << distance(myVector.begin(), it);
        cout << ": ";
        for (auto i : *it) {
            cout << i << " ";
        }
        cout << endl;
    }
    
    return 0;
}
