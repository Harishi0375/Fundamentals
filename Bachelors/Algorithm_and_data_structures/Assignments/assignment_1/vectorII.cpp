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

    if (vstring.size() > 4) {
        if (!vstring[1].empty() && !vstring[4].empty()) {
            vstring[1].swap(vstring[4]);
        } else {
            cout << "One or more positions are empty to perform the swap" << endl;
        }
    } else {
        cout << "Vector does not have enough elements for swapping" << endl;
    }


    int last_element = distance(vstring.begin(),vstring.end()) - 1;

    vstring[last_element] = "???"; 

    //comma
     << endl;

    vector<string>::iterator it2;
    for (it2 = vstring.begin(); it2 != vstring.end(); it2++)
    {
        cout << *it2;
        if (it2 != vstring.end() - 1)
        {
            cout << "; ";
        }
    }

    cout << endl;

    vector<string>::iterator ditter = vstring.end();
    while(ditter != (vstring.begin()-1))
    {
        cout << *ditter;
        if (--ditter != vstring.begin())
        {
            cout << " ";
        }
    }

    cout << endl;
}
