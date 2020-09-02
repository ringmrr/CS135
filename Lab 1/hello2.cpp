/*--------------------------------------------------------------------------------------------------
FILENAME:           hello2.cpp
DESCRIPTION:        Ask the user some questions, repeat their input, then do a math problem.
COMPILER:           MinGW C++ compiler
NOTES:              Learning variable declaration, cin/cout objects, and testing math bugs.

MODIFICATION HISTORY:
Author              Date           Version
---------------     ----------     ---------------
Michael Ring        2020-08-23     0.1 - Created files, copied headers
Michael Ring        2020-08-27     1.0 - Wrote source code from hello2.gif
Michael Ring        2020-08-27     1.1 - Added comments
Michael Ring        2020-08-27     1.2 - Fixed divide by zero bug
Michael Ring        2020-08-27     1.3 - Added if-else fix for negative input. It only works once.
Michael Ring        2020-08-31     1.4 - Changed if-else to while loop. It only catches -1.
Michael Ring        2020-09-02     1.5 - 
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
    string eyeColor;    // strings will be text responses from user
    unsigned int x;     // integers will be numbers input for math operation 
    unsigned int y;
    unsigned int z;

    //  GREETING

    cout << "Hello, world!" << endl << endl << endl;               
    // Print welcome message
    

    //  NAME
    
    cout << "What is your name?   ";
    // Asks user to input name
    cin >> firstName;
    // Stores it as variable firstName
    cout << "Hello, " << firstName << "!" << endl << endl;
    // Greets the user by name by using the variable


    //  EYE COLOR

    cout << "What color are your eyes, " << firstName << "?   ";
    // Asks the user by name to input eye color
    cin >> eyeColor;
    // Stores it as variable eyeColor
    cout << "Your eyes are " << eyeColor << "." << endl << endl;
    // Repeats the eye color to the user


    //  MATH
    
    cout << "Let's do some division.   x / y  =  z" << endl << endl;
    // Shows user what the variables mean and what we'll do with them

    x = 4294967295;             // Initializes while loop, which should stay open
    y = 2;
    while (x == 4294967295)     // in the event of int overflow (2^32 - 1)
    {
            cout << "What should x be? Choose a positive whole number.   ";
            // Asks user to input dividend, guides them to stick within unsigned int paramaters
            cin >> x;
            // Stores it as variable x 
    }

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
    //      5/2=2.5 gets truncated to 2, and 5/-2=-2.5 instead returns 4,294,967,294 (interger overflow)
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