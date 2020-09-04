/*--------------------------------------------------------------------------------------------------
FILENAME:           hello2.cpp
DESCRIPTION:        Ask the user some questions, repeat their input, then do a math problem.
COMPILER:           MinGW C++ compiler
NOTES:              Learning variable declaration, cin/cout objects, and testing math bugs.

MODIFICATION HISTORY:   
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-08-23      0.1 - Created files, copied headers
Michael Ring        2020-08-27      1.0 - Wrote source code from hello2.gif
Michael Ring        2020-08-27      1.1 - Added comments
Michael Ring        2020-08-27      1.2 - Added if-else fix for zero input. It only works once.
Michael Ring        2020-08-31      1.3 - Tried while loop instead of if-else. It only catches -1.
Michael Ring        2020-09-02      1.4 - Deleted entire math section. Noted last name input bug.
Michael Ring        2020-09-02      1.5 - Stopped requesting user input for math variables.  
Michael Ring        2020-09-03      1.6 - Re-added if-else to catch 0 divisor
Michael Ring        2020-09-03      1.7 - Answered lab questions/final check before compile+zip.
--------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const string PROGRAMMER_NAME = "Michael Ring";

/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        Greeting, questions/input, 
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
    
    cout << "What is your first name?   ";
    // Asks user to input name
    getline(cin,firstName);
    // Stores it as variable firstName.
    cout << "Hello, " << firstName << "!" << endl << endl;
    // Greets the user by name by using the variable


    //  EYE COLOR

    cout << "What color are your eyes, " << firstName << "?   ";
    // Asks the user by name to input eye color
    getline(cin,eyeColor);
    // Stores it as variable eyeColor
    cout << "Your eyes are " << eyeColor << "." << endl << endl;
    // Repeats the eye color to the user


    //  MATH

    cout << "Let's do some division.   x / y  =  z" << endl << endl;
    // Shows user what the variables mean and what we'll do with them

    // Assign values to variables
    // x = 5;
    // y = 0;   Program crashes after inputting eyeColor.
    // y = -2;  Program interprets -2 as 4294967294 (integer underflow)
    // y = 2;   Program returns 2. Decimal gets truncated due to data type.
    x = 6;      // Using an even dividend to prevent data type calculation errors
    y = 2;      // Using a positive divisor that results in a whole number quotient

    // Check for zero division to prevent crashing
    if (y == 0) {cout << "Cannot divide by zero. Please try again." << endl;}
    else 
    {
        z = x / y;
        // Run calculation
        cout << "x / y = " << x << " / " << y << " = " << z << endl << endl;
        // Share results
    }

    //  THE END
    
    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl;
    cout << endl;

    system("pause");

    return 0;
}
    // LAB QUESTIONS
    //
    // 1) What happens if you "comment it out"?
    //     
    //      The program no longer crashes, 
    //      but it no longer runs or prints 
    //      any calculation, either.
    //
    // 2) What happens if you change the value of y? Try y-values of 2 and -2.
    //      
    //      y = 0;   Program crashes after inputting eyeColor.
    //      y = -2;  Program interprets -2 as 4294967294 (integer underflow)
    //      y = 2;   Program returns 2. Decimal gets truncated due to data type.  
    //
    // 3) Other solutions? Can you add some code to make the program "bullet-proof"?
    //      
    //      Due to the data type, there isn't a way to prevent inaccurate results 
    //      (from negatives/decimals), but adding an if-else statement 
    //      prevents the divide by zero crash.