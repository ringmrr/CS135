/*--------------------------------------------------------------------------------------------------
FILENAME:           hello2.cpp
DESCRIPTION:        Ask the user some questions, repeat their input, then do a math problem.
COMPILER:           MinGW C++ compiler
NOTES:              Learning variable declaration, cin/cout objects, and testing math bugs.

MODIFICATION HISTORY:
Author              Date           Version
---------------     ----------     ---------------
Michael Ring        2020-07-23     0.1 - Created files, copied headers
Michael Ring        2020-07-23     1.0 - Wrote source code from hello2.gif
Michael Ring        2020-07-23     1.1 - Added comments
Michael Ring        2020-07-23     
--------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const string PROGRAMMER_NAME = "Michael Ring";

/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        Say what this function does
RETURNS:            0
NOTES:              Optional notes on this function
--------------------------------------------------------------------------------------------------*/

int main()
{
    string firstName;           // Declaring variables
    string eyeColor;            // strings will be input by user
    unsigned int x;             // integers will be input by me for testing
    unsigned int y;
    unsigned int z;

    cout << "Hello, world!" << endl << endl << endl;               
    // Print welcome message

    cout << "What is your name?   ";
    // Asks user to input name
    cin >> firstName;
    // Stores it as a variable
    cout << "Hello, " << firstName << endl << endl;
    // Greets the user by name by using the variable

    cout << "What color are your eyes, " << firstName << "?   ";
    // Asks user to input eye color
    cin >> eyeColor;
    // Stores it as variable eyeColor
    cout << "Your eyes are " << eyeColor << endl << endl;

    x = 5;
    y = 0;
    z = x / y;

    cout << "x / y = " << x << " / " << y << " = " << z << endl << endl;
    
    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl;
    cout << endl;

    system("pause");

    return 0;
}