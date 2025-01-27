#include <iostream>
#include <ctime>
#include <cstdlib>
#include <set>

using namespace std;

int main() {
    srand(time(nullptr));
    set<int> drawNum;
    while (drawNum.size() < 6) {
        int randomNumber = rand() % 49 + 1;
        drawNum.insert(randomNumber);
    }
    cout << "Lottery numbers drawn:\n";
    for (int number : drawNum) {
        cout << number << " ";
    }
    cout << endl;
    return 0;
}
