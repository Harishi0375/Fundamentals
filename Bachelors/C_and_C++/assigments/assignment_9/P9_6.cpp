/*
  CH-230-A
  a9_p6.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
using namespace std;

class foverloading
{
    public:
        int myfirst(const int a[], int size)
        {
            for (int i = 0; i < size; i++)
            {
                if (a[i] > 0 && a[i] % 2 == 0)
                {
                    return a[i];
                }
            }
            return -1;       
        }

        float myfirst(const double a[], int size)
        {
            for (int i = 0; i < size; i++)
            {
                if (a[i] < 0 && a[i] == (int)a[i]) //(int)a[i] if int then no fraction
                {
                    return a[i];
                }  
            }
            return -1.1;
        }

        char myfirst(const char a[], int size)
        {
            for (int i = 0; i < size; i++)
            {
                if (a[i] != 'a' && a[i] != 'e' && a[i] != 'i' && a[i] != 'o' && a[i] != 'u' && a[i] != 'A' && a[i] != 'E' && a[i] != 'I' && a[i] != 'O' && a[i] != 'U') //taking out vowels
                {
                    return a[i];
                } 
            }
            return '0';
        }
};

int main()
{
    foverloading example;

    int intArr[] = {3, 1, 6, 4, 7, 8}; //example 1
    double doubleArr[] = {-1.5, -2.0, -3.2, 4.7}; //example 2
    char charArr[] = "ealo he"; //example 3

    std::cout << "First positive even integer: " << example.myfirst(intArr, sizeof(intArr)/sizeof(int)) << std::endl;
    std::cout << "First negative integer: " << example.myfirst(doubleArr, sizeof(doubleArr)/sizeof(double)) << std::endl;
    std::cout << "First consonant: " << example.myfirst(charArr, sizeof(charArr)/sizeof(char)) << std::endl;

    return 0;
}
