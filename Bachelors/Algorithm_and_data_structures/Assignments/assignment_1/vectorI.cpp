#include <iostream>
#include <vector>
#include <string> 

using namespace std;

int main(int argc, char** argv)
{
    vector<string> vstring;
    string word;

    while (cin >> word && word != "END")
    {
        vstring.push_back(word);
    }
    
    cout << endl;

    for (unsigned int i = 0; i < vstring.size(); i++)
    {
        cout << vstring[i]; //using index operator
        if (i < vstring.size() - 1)
        {
            cout << " ";
        }
    }

    cout << endl;

    //comma
    vector<string>::iterator it;
    for (it = vstring.begin(); it != vstring.end(); it++)
    {
        cout << *it;
        if (it != vstring.end() - 1)
        {
            cout << ", ";
        }
    }

    cout << endl;
}
