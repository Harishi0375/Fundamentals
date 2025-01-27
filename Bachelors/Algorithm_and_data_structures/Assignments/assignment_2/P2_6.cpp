#include <iostream>
#include <fstream>
#include <sstream>
#include <map>
#include <string>

using namespace std;

int main() {
    ifstream file("data.txt");
    if (!file) {
        cout << "error";
        exit(1);
    }

    map<string, string> nameBirthdayMap;

    string line;
    while (getline(file, line)) {
        istringstream iss(line);
        string firstName, lastName, birthday;
        iss >> firstName >> lastName >> birthday;
        string fullName = firstName + " " + lastName;
        nameBirthdayMap[fullName] = birthday;
    }

    file.close();

    string queryName;
    cout << "Enter a name to query: ";
    getline(cin, queryName);

    if (nameBirthdayMap.find(queryName) != nameBirthdayMap.end()) {
        cout << "Birthday date for " << queryName << ": " << nameBirthdayMap[queryName] << endl;
    } else {
        cout << "Name not found!" << endl;
    }

    return 0;
}
