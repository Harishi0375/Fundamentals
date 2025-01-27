/*
  CH-230-A
  a9_p9.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
#include <string>
#include <cstdlib> //for rand() and srand()
#include <ctime> //for time()
using namespace std;

bool isConsonant(const char ch)
{
    //returns true if a is not a vowel
    return (ch != 'a' && ch != 'e' && ch != 'i' && ch != 'o' && ch != 'u' && ch != 'A' && ch != 'E' && ch != 'I' && ch != 'O' && ch != 'U');
}

std::string vowelToUnderscore(const std::string word)
{
    std::string newWord = word;
    for (size_t i = 0; i < word.size(); i++) 
    {
        if (isConsonant(word[i]))
        {
            continue;
        }
        newWord[i] = '_';
    }
    return newWord;
}

int main()
{
    std::string arr[] = {"computer","television","keyboard","laptop","mouse","book","garbled","instant","history","therapy","hunting","vibrant","display","blurred","finding","goddamn","setting","stratum"};
    srand(static_cast<size_t>(time(0))); //init random number generator
    int randIndex = (rand() % (16)); //16 because array size

    int count = 1;
    while (1)
    {
        std::string newWord = vowelToUnderscore(arr[randIndex]); 
        std::cout << "can you guess the word? " << newWord << std::endl;
        std::string guessedWord;
        std::cin >> guessedWord;
        if (guessedWord == "quit")
        {
            break;
        }
        if (guessedWord == arr[randIndex])
        {
            std::cout << "number of tries = " << count << std::endl;
            count = 1;
            randIndex = (rand() % (16)); //reset to new word
        }
        else
        {
            ++count;
        }    
    }
    return 0;    
}