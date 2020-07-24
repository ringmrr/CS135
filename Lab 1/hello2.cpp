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
Michael Ring        2020-07-23     1.2 - Fixed divide by zero bug
Michael Ring        2020-07-23     1.3 - 
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
    string firstName;   // Declaring variables
    string eyeColor;    // strings will be input by user
    unsigned int x;     // integers will be input by me for testing
    unsigned int y;
    unsigned int z;

    cout << "Hello, world!" << endl << endl << endl;               
    // Print welcome message

    cout << "What is your name?   ";
    // Asks user to input name
    cin >> firstName;
    // Stores it as variable firstName
    cout << "Hello, " << firstName << "!" << endl << endl;
    // Greets the user by name by using the variable

    cout << "What color are your eyes, " << firstName << "?   ";
    // Asks the user by name to input eye color
    cin >> eyeColor;
    // Stores it as variable eyeColor
    cout << "Your eyes are " << eyeColor << "." << endl << endl;
    // Repeats the eye color to the user.

    x = 5;              // Assigning values to 
    y = -2;             // ints and dividing    
    z = x / y;          // x by y to assign z

    cout << "x / y = " << x << " / " << y << " = " << z << endl << endl;
    // Print division and result


    // LAB QUESTIONS
    //
    // 1) What happens if you "comment it out"?
    //     
    //      Commenting the math portion of the code out allows
    //      it to print the timestamp and pause as expected.
    //
    // 2) What happens if you change the value of y? Try y-values of 2 and -2.
    //      
    //      The program no longer crashes, but it can give inaccurate results.
    //      5/2=2.5 gets truncated to 2, and 5/-2=-2.5 instead returns 4294967294,
    //      because the integer variable only relates to whole numbers, and
    //      because unsigned variables do not accept negative values.
    //
    // 3) Other solutions? Can you add some code to make the program "bullet-proof"?
    //     
    //       fuck

    
    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl;
    cout << endl;

    system("pause");

    return 0;
}