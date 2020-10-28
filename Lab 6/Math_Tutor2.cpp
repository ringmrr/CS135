/*--------------------------------------------------------------------------------------------------
FILENAME:           Math_Tutor2.cpp
DESCRIPTION:        Subproject of Lab 6
COMPILER:           MinGW C++ compiler
NOTES:             

MODIFICATION HISTORY:
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-10-26      1.0 - Copied from Math_Tutor.cpp
--------------------------------------------------------------------------------------------------*/

// PREPROCESSOR DIRECTIVES
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>

// NAMESPACE
using namespace std;

// NAMED CONSTANTS
const string PROGRAMMER_NAME = "Michael Ring";

/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        Say what this function does
RETURNS:            0
NOTES:              Optional notes on this function
--------------------------------------------------------------------------------------------------*/
int main()
{
    int x, y, result, answer;

    // Gets the system time to seed RNG
    unsigned seed = time(0);    
    srand(seed);               

    // Loop stays open until x and y are in the proper range
    bool valid = false;
    while (!valid)
    {
        // Assigns random values to x and y
        x = rand();             
        y = rand();             

        // Checks that x is a 3 digit number, and that y is a 2 or 3 digit number less than x.
        if (x >= 100 && x <= 999 && y >= 10 && y < x)
            valid = true;
    }

    result = x + y;

    // Print calculation without result
    cout << setw(5) << right << x << endl;
    cout << "+" << setw(4) << right << y << endl;
    cout << "-----" << endl << endl;

    // Pause for user input
    cout << "Enter your answer here: " << endl;
    cin >> answer;
    cin.clear();

    // Print calculation with result
    cout << setw(5) << right << x << endl;
    cout << "+" << setw(4) << right << y << endl;
    cout << "-----" << endl;
    cout << setw(5) << right << result << endl << endl;

    // Goodbye!
    cout << "Programmed by: " << PROGRAMMER_NAME << " -- " << __DATE__ << " " __TIME__ << endl;
    system("pause");
    return 0;
}