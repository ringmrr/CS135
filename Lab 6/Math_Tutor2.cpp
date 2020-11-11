/*--------------------------------------------------------------------------------------------------
FILENAME:           Math_Tutor2.cpp
DESCRIPTION:        Subproject of Lab 6
COMPILER:           MinGW C++ compiler
NOTES:             

MODIFICATION HISTORY:
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-10-27      1.5 - Copied from Math_Tutor.cpp
Michael Ring        2020-10-27      2.0 - Replaced 'prints calculation with result'
                                          with 'prints result', to match the output document
Michael Ring        2020-10-28      2.1 - Changed cin.ignore() to cin >> answer, with new variable
Michael Ring        2020-10-28      2.2 - if/else statement to check if answer is correct
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
    // Variable declarations
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

    // Calculates the result, stores it as variable
    result = x + y;

    // Print calculation without result
    cout << setw(5) << right << x << endl;
    cout << "+" << setw(4) << right << y << endl;
    cout << "-----" << endl << endl;

    // Pause for user input
    cout << "Enter your answer here: ";
    cin >> answer;
    cin.clear();
    cin.ignore(100, '\n');
    cout << endl;

    // Checks if user input is correct
    if (answer == result)
        cout << "Congratulations!" << endl;
    else
        cout << "Sorry! That is incorrect." << endl;
    
    // Prints result
    cout << "The answer is " << result << endl << endl;

    // Goodbye!
    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl;
    system("pause");
    return 0;
}