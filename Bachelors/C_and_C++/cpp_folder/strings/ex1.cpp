// Michael Dawson, Beginning C++ Through Game Programming
// String Tester
// Demonstrates string objects

#include <iostream>
#include <string>

using namespace std;

int main()
{
    string word1 = "Game";
    string word2("Over");
    string word3(3, '!'); //seems cool

    string phrase = word1 + " " + word2 + word3;
    cout << "The phrase is: " << phrase << "\n\n";

    cout << "The phrase has " << phrase.size() << " characters in it.\n\n";

    cout << "The character at position 0 is: " << phrase[0] << "\n\n";

    cout << "Changing the character at position 0.\n";
    phrase[0] = 'L';
    cout << "The phrase is now: " << phrase << "\n\n";

	for (unsigned int i = 0; i < phrase.size(); ++i)
	{
        cout << "Character at position " << i << " is: " << phrase[i] << endl;
	}

    cout << "\nThe sequence 'Over' begins at location "; 
    cout << phrase.find("Over") << endl;

    if (phrase.find("eggplant") == string::npos)
	{
        cout << "'eggplant' is not in the phrase.\n\n";
	}

    phrase.erase(4, 5); //erase from position to how many
    cout << "The phrase is now: " << phrase << endl;

    phrase.erase(4); //from position 4 and after all erased
    cout << "The phrase is now: " << phrase << endl;

    phrase.erase(); //erases everything
    cout << "The phrase is now: " << phrase << endl;

    if (phrase.empty()) //returns true or false
	{
        cout << "\nThe phrase is no more.\n";
	}

	return 0;
}