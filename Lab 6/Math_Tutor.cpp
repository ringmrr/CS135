/*--------------------------------------------------------------------------------------------------
FILENAME:           Math_Tutor.cpp
DESCRIPTION:        Subproject of Lab 6
COMPILER:           MinGW C++ compiler
NOTES:             

MODIFICATION HISTORY:
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-10-26      0.1 - Declared variables and formatted output
Michael Ring        2020-10-26      0.2 - Assign rand() to x and y
                                            > Assigns same values each time the program is run.
Michael Ring        2020-10-27      0.3 - Added if statement to set constraints for x and y
Michael Ring        2020-10-27      0.4 - Added srand and way to generate seed
                                            > Solution found in Starting out with C++ p.129
Michael Ring        2020-10-27      1.0 - Pauses and prints result
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
    int x, y, result;

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
    cout << "Press Enter to see the answer . . ." << endl;
    cin.ignore();

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