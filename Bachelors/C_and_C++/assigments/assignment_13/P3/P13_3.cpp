/*
  CH-230-A
  a13_p3.cpp
  Harishi Velavan
  hvelavan@jacobs-university.de
*/

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main()
{
    int n;
    cout << "Enter the number of files to be concatenated: ";
    cin >> n;

    string *filenames = new string[n];

    // Read file names from the user
    for (int i = 0; i < n; ++i)
    {
        cout << "Enter file name " << i + 1 << ": " << endl;
        cin >> filenames[i];
    }

    // Open the output file
    ofstream outFile("concatn.txt", ios::binary);

    // Check if the output file is open
    if (!outFile.is_open())
    {
        cerr << "Error opening output file." << endl;
        delete[] filenames;
        return 1;
    }

    // Concatenate the content of input files into the output file
    for (int i = 0; i < n; ++i)
    {
        ifstream inFile(filenames[i], ios::binary);

        // Check if the input file is open
        if (!inFile.is_open())
        {
            cerr << "Error opening input file: " << filenames[i] << endl;
            outFile.close();
            delete[] filenames;
            return 1;
        }

        // Copy the content of the input file to the output file
        outFile << inFile.rdbuf();

        // Add a newline character to separate the content of different files
        outFile << '\n';

        // Close the input file
        inFile.close();
    }

    // Close the output file
    outFile.close();

    // Open the output file for reading
    ifstream resultFile("concatn.txt", ios::binary);

    // Check if the result file is open
    if (!resultFile.is_open())
    {
        cerr << "Error opening result file for reading." << endl;
        delete[] filenames;
        return 1;
    }

    // Print the contents of the output file
    cout << "Printing the contents of the output file:" << endl;
    string line;
    while (getline(resultFile, line))
    {
        cout << line << endl;
    }

    resultFile.close();

    cout << "Concatenation completed." << endl;

    
    delete[] filenames;

    return 0;
}
