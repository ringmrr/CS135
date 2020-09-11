/*--------------------------------------------------------------------------------------------------
FILENAME:           Chars1.cpp
DESCRIPTION:        Subproject of Lab 2
COMPILER:           MinGW C++ compiler
NOTES:              Demonstrate how char and string data types work

MODIFICATION HISTORY:
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-09-10      0.1 - Created files, copied headers
Michael Ring        2020-09-10      0.2 - Copied Programs 2-12, 2-13, 2-14, and 2-15 from textbook.
--------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const string PROGRAMMER_NAME = "Michael Ring";

/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        Assigning and printing characters
RETURNS:            0
NOTES:              
--------------------------------------------------------------------------------------------------*/

int main()
{
    char letter;

    // Program 2-12
    letter = 'A';
    cout << letter << endl;
    letter = 'B';
    cout << letter << endl;

    // Program 2-13
    letter = 65;
    cout << letter << endl;
    letter = 66;
    cout << letter << endl;

    // Program 2-14
    letter = 'A';
    cout << letter << '\n';
    letter = 'B';
    cout << letter << '\n';    
    
    // Program 2-15
    string movieTitle;
    
    movieTitle = "Movie";
    cout << "My favorite movie is " << movieTitle << endl;
    
    
    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl;
    cout << endl;

    system("pause");

    return 0;
}