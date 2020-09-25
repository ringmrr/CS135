/*--------------------------------------------------------------------------------------------------
FILENAME:           Calculator.cpp
DESCRIPTION:        Suitable for a seventh grade student.
COMPILER:           MinGW C++ compiler
NOTES:              Details on what this program does

MODIFICATION HISTORY:
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-09-23      1.0 - Copied functions from Lab 4.
                                            >> Source code copied from:
                                                > Add_2_Numbers.gif on Canvas
                                                > Get_mainChoice_v(1-6).gifs on Canvas
                                                > Program 6-17 from Textbook pg. 342
Michael Ring        2020-09-23      1.1 - Added function prototypes for -, *, /, powers, and roots.
Michael Ring        2020-09-23      1.2 - Renamed functions and modified them for the operation.
Michael Ring        2020-09-24      1.3 - Created prMenu to navigate to power/root functions. 
Michael Ring        2020-09-24      1.4 - Added new switch to main function to check prMenu input.
                                            > Commented out, since there's no functions to go to yet
--------------------------------------------------------------------------------------------------*/

// Required preprocessor directives
#include <iostream>    
#include <iomanip>
#include <string>

// Namespace
using namespace std;

// Function prototypes
char mainMenu();
char prMenu();
void getXandY();      

void add();
void subtract();
void multiply();
void divide();

void prSquare();
void prCube();
void prPower();

void prSqrt();
void prCbrt();
void prRoot();

// Global constants
const string PROGRAMMER_NAME = "Michael Ring";

// Global variables
double x, y, result;


/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        Driver function
RETURNS:            0
NOTES:              
--------------------------------------------------------------------------------------------------*/

int main()
{
    system("cls");                  // Clears the screen (nothing to clear unless opened from cmd)

    char mainChoice;                    // Declares variable for menu selections
    char prChoice;

    bool goodbye = false;           // Flag allows loop to be closed when switched to true
    while(!goodbye)                 // Open while loop to allow multiple uses without restarting
    {
        mainChoice = mainMenu();       // Calls function mainMenu to get user's selection
        switch (mainChoice)
        {
            case 'a':
                add();      // If mainChoice == a, call add function
                break;
            case 'b':
                subtract();
                break;
            case 'c':
                multiply();
                break;
            case 'd':
                divide();
                break;
            case 'e':
                prMenu();
                break;
            case 'q':
                goodbye = true;
                break;
        }
 /*     switch (prChoice)
        {
            case 'a':
                prSqrt();
                break;
            case 'b':
                prCbrt();
                break;
            case 'c':
                pr
        }*/
    }                              

    //  GOODBYE

    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl;
    cout << endl;

    system("pause");

    return 0;
}


/*--------------------------------------------------------------------------------------------------
FUNCTION:           mainMenu()
DESCRIPTION:        Main Menu and selection logic
RETURNS:            mainChoice
NOTES:              
--------------------------------------------------------------------------------------------------*/
char mainMenu()
{
    char mainChoice;


    //  MAIN MENU

    cout << "-----------------------------------------------" << endl;
    cout << "                   MAIN MENU                   " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << endl;
    cout << "a.   Addition                    (X+Y)" << endl;
    cout << "b.   Subtraction                 (X-Y)" << endl;
    cout << "c.   Multiplication              (X*Y)" << endl;
    cout << "d.   Division                    (X/Y)" << endl;
    cout << "e.   Powers & Roots" << endl;
    cout << "q.   Quit" << endl;
    cout << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "          Enter your Choice [a-e, q]:          " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << endl;
    cin >> mainChoice;
    cout << endl;

    
    //  INPUT DECISION LOGIC

    mainChoice = tolower(mainChoice);       // Converts uppercase char input to corresponding lowercase char

    if (mainChoice >= 'a' && mainChoice <= 'e')
        cout << "You entered: '" << mainChoice << "', that is correct input." << endl;
    else if (mainChoice == 'q')
        cout << "You entered: '" << mainChoice << "'. Goodbye!" << endl << endl;
    else
    {
        cout << "You did not enter a valid option." << endl;
        cout << "Please try again." << endl;
    }
    cout << endl << endl;

    return mainChoice;
}


/*--------------------------------------------------------------------------------------------------
FUNCTION:           prMenu()
DESCRIPTION:        Powers & Roots Menu and selection logic
RETURNS:            prChoice
NOTES:              
--------------------------------------------------------------------------------------------------*/
char prMenu()
{
    char prChoice;

    //  MAIN MENU

    cout << endl << endl;   
    cout << "-----------------------------------------------" << endl;
    cout << "               POWERS & ROOTS MENU             " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << endl;
    cout << "a.   Square a number             (X^2)" << endl;
    cout << "b.   Cube a number               (X^3)" << endl;
    cout << "c.   Raise to any power          (X^Y)" << endl;
    cout << "d.   Square root a number        (X^1/2)" << endl;
    cout << "e.   Cube root a number          (X^1/3)" << endl;
    cout << "f.   Take any root               (X^1/Y)" << endl;
    cout << "m.   Return to Main Menu" << endl;
    cout << "q.   Quit" << endl;
    cout << endl;
    cout << "-----------------------------------------------" << endl;
    cout << "        Enter your Choice [a-f, m, q]:         " << endl;
    cout << "-----------------------------------------------" << endl;
    cout << endl;
    cin >> prChoice;
    cout << endl;

    
    //  INPUT DECISION LOGIC

    prChoice = tolower(prChoice);   

    if (prChoice >= 'a' && prChoice <= 'f')
        cout << "You entered: '" << prChoice << "', that is correct input." << endl << endl;
    else if (prChoice == 'm')
        mainMenu();
    else if (prChoice == 'q')
        cout << "You entered: '" << prChoice << "'. Goodbye!" << endl << endl;
    else
    {
        cout << "You did not enter a valid option." << endl;
        cout << "Please try again." << endl;
    }
    cout << endl << endl;

    return prChoice;
}


/*--------------------------------------------------------------------------------------------------
FUNCTION:           getXandY()
DESCRIPTION:        Gets user input for math functions
RETURNS:            N/A
NOTES:              Inputting characters for x and/or y results in an infinite scroll
--------------------------------------------------------------------------------------------------*/
void getXandY()
{
    cout << "Please input x and y: ";
    cin >> x;       // <!> BUG <!>
    cin >> y;       // Inputting characters rather than numbers results in an infinite scroll
}


/*--------------------------------------------------------------------------------------------------
FUNCTION:           add()
DESCRIPTION:        Addition function
RETURNS:            N/A
NOTES:              
--------------------------------------------------------------------------------------------------*/
void add()
{
    cout << "This function will add x and y... " << endl;
    cout << endl;

    getXandY();
    result = x + y;

    cout << endl;
    cout << "   x + y = " << x << " + " << y << " = " << result << endl;

    cout << endl << endl;
    system("pause");
    cout << endl;
}


/*--------------------------------------------------------------------------------------------------
FUNCTION:           subtract()
DESCRIPTION:        Subtraction function
RETURNS:            N/A
NOTES:              
--------------------------------------------------------------------------------------------------*/
void subtract()
{
    cout << "This function will subtract x from y... " << endl;
    cout << endl;

    getXandY();
    result = x - y;

    cout << endl;
    cout << "   x - y = " << x << " - " << y << " = " << result << endl;

    cout << endl << endl;
    system("pause");
    cout << endl;
}


/*--------------------------------------------------------------------------------------------------
FUNCTION:           multiply()
DESCRIPTION:        Multiplication function
RETURNS:            N/A
NOTES:              
--------------------------------------------------------------------------------------------------*/
void multiply()
{
    cout << "This function will multiply x and y... " << endl;
    cout << endl;

    getXandY();
    result = x * y;

    cout << endl;
    cout << "   x * y = " << x << " * " << y << " = " << result << endl;

    cout << endl << endl;
    system("pause");
    cout << endl;
}


/*--------------------------------------------------------------------------------------------------
FUNCTION:           divide()
DESCRIPTION:        Division function
RETURNS:            N/A
NOTES:              
--------------------------------------------------------------------------------------------------*/
void divide()
{
    cout << "This function will divide x by y... " << endl;
    cout << endl;

    getXandY();
    result = x / y;

    cout << endl;
    cout << "   x / y = " << x << " / " << y << " = " << result << endl;

    cout << endl << endl;
    system("pause");
    cout << endl;
}