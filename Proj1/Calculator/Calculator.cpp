/*--------------------------------------------------------------------------------------------------
FILENAME:           Calculator.cpp
DESCRIPTION:        Suitable for a seventh grade student.
COMPILER:           MinGW C++ compiler
NOTES:              Details on what this program does

MODIFICATION HISTORY:
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-09-23      1.0 - Copied functions from Lab 4.
                                            >> SOURCE CODE COPIED FROM:
                                                > Add_2_Numbers.gif on Canvas
                                                > Get_mainChoice_v(1-6).gifs on Canvas
                                                > Program 6-17 from Textbook pg. 342
Michael Ring        2020-09-23      1.1 - Added function prototypes for -, *, /, powers, and roots.
Michael Ring        2020-09-23      1.2 - Renamed functions and modified them for the operation.
Michael Ring        2020-09-24      1.3 - Created prMenu to navigate to power/root functions. 
Michael Ring        2020-09-24      1.4 - Added new switch to main function to check prMenu input.
Michael Ring        2020-10-05      1.5 - Moved prMenu switch to new function prMain().
Michael Ring        2020-10-05      1.6 - Tested various methods to quit from prMain, unsuccessful.
                                            > Moving goodbye to global variable, allowing prMain()
                                              to set it to 'true' as well
                                            > Changed prMain to a bool function so it can return
                                              a value, allowing main to check that value in a 
                                              separate if statement to assign true to goodbye
Michael Ring        2020-10-07      1.7 - Added prSquare(), prCube(), and prPower().
Michael Ring        2020-10-07      1.8 - Found better way to call & return prMain (for quit & menu)  
                                            > Problem is I can only get quit OR menu working,
                                              not both at the same time. 
                                            > Commenting out the if statement in main case e
                                              gets main menu to work, but quit from pr breaks
Michael Ring        2020-10-07      2.0 - Added remaining pr functions and call them in the switch
Michael Ring        2020-10-07      2.1 - Testing methods to allow int/floating point selection
                                            > It currently asks user to select, and validates input,
                                              but the data type does not actually change.
Michael Ring        2020-10-10      2.2 - Created dataSelect() with loop to determine i/f selection
Michael Ring        2020-10-10      2.3 - Fixed menu/quit from prMenu
Michael Ring        2020-10-10      2.4 - Added cin.sync() to bulletproof i/f selection
                                            > Solution found in the forum post cited below:
                                            > http://www.cplusplus.com/forum/beginner/50795/
Michael Ring        2020-10-15      2.5 - Calling cin as while condition for input validation
                                            > Got the idea from this stackoverflow thread:
                                            > https://stackoverflow.com/questions/19483126/
Michael Ring        2020-10-15      2.6 - Ditched the previous two solutions in favor of 
                                          cin.clear(), cin.ignore(), and cin.good().
Michael Ring        2020-10-15      2.7 - Dialed in input validation for input functions
Michael Ring        2020.10-15      2.8 - Added additional cin.ignore()'s to prevent multi-input
                                            > e.g. inputting "a i 5 3 a" from main menu
                                            > inputting "x y" in same line is still acceptable 
--------------------------------------------------------------------------------------------------*/

// Required preprocessor directives
#include <iostream>    
#include <iomanip>
#include <string>
#include <cmath>

// Namespace
using namespace std;

// Function prototypes
bool prMain();

char mainMenu();
char prMenu();

void getX();
void getXandY();      
bool dataSelect();

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
====================================================================================================
            DRIVER FUNCTIONS
====================================================================================================
--------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        Driver function
RETURNS:            0
NOTES:              
--------------------------------------------------------------------------------------------------*/

int main()
{
    system("cls");                  // Clears the screen (nothing to clear unless opened from cmd)

    bool goodbye = false;           // Flag used to open and close while loop
    while (!goodbye)                // while loop allows multiple uses without restarting
    {
        char mainChoice = mainMenu();//Calls function mainMenu to get user's selection
        bool prQuit;                // Flag to allow closing of loop from powers & roots menu

        switch (mainChoice)         // Tests user selection to direct them to the right function
        {
            case 'a':
                add();              // If mainChoice == 'a', call add function
                break;
            case 'b':       
                subtract();         // etc.
                break;
            case 'c':
                multiply();
                break;
            case 'd':
                divide();
                break;
            case 'e':
                prQuit = prMain();  // Calls pr driver and checks for quit command
                if (prQuit == true)
                    goodbye = true; // Closes while loop, quitting program
                break;
            case 'q':
                goodbye = true;     // Closes while loop, quitting program
                break;
        }
    }                              

    //  GOODBYE
    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl << endl;

    system ("pause");
    return 0;
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           prMain()
DESCRIPTION:        Driver function for powers & roots, similar to main()
RETURNS:            prQuit
NOTES:              
--------------------------------------------------------------------------------------------------*/
bool prMain()
{
    bool exit = false;              // Flag used to open and close while loop
    while (!exit)                 
    {
        char prChoice = prMenu();   // Calls function prMenu to get user's selection
        switch (prChoice)           // Tests user selection to direct them to the right function
        {
            case 'a':
                prSquare();         // If prChoice == 'a', call square function
                break;
            case 'b':
                prCube();           // etc.
                break;
            case 'c':
                prPower();
                break;
            case 'd':
                prSqrt();
                break;
            case 'e':
                prCbrt();
                break;
            case 'f':
                prRoot();
                break;
            case 'm':
                exit = true;        // Closes while loop
                break;
            case 'q':
                return true;        // Closes function, quitting program
                break;
        }
    }

    return false;                   // Closes function, returning to main menu
}


/*--------------------------------------------------------------------------------------------------
====================================================================================================
            MENU FUNCTIONS
====================================================================================================
--------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------
FUNCTION:           mainMenu()
DESCRIPTION:        Main Menu and selection logic
RETURNS:            mainChoice
NOTES:              
--------------------------------------------------------------------------------------------------*/
char mainMenu()
{
    char mainChoice;

    //  MAIN MENU DISPLAY
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
    
    //  INPUT DECISION LOGIC
    cin.clear();             
    // Clears input buffer from previous math operations

    bool menuValid = false;         // Flag used to open and close while loop
    while (!menuValid)
    {
        cin >> mainChoice;           
        cout << endl;
        mainChoice = tolower(mainChoice);   
        // Converts uppercase char input to corresponding lowercase

        if (cin.good())
        // Checks whether input matches data type
        {
            if (mainChoice >= 'a' && mainChoice <= 'e')
            {
                cout << "You entered: '" << mainChoice << "', that is correct input." << endl;
                menuValid = true;
                // Closes while loop
            }
            else if (mainChoice == 'q')
            {
                cout << "You entered: '" << mainChoice << "'. Goodbye!" << endl;
                menuValid = true;
                // Closes while loop
            }
            else
            // Catches invalid character input, e.g. x or j
            {
                cout << "ERROR: You did not enter a valid option." << endl;
                cout << "Please try again: ";
                cin.clear();
                cin.ignore(100, '\n');
            }
        }
        else
        // Catches non-character input, e.g. numbers
        {
            cout << "ERROR: You did not enter a valid option." << endl << endl;
            cout << "Please try again: ";
            cin.clear();            // Fixes error scroll
            cin.ignore(100, '\n');  // Ignores next 100 characters in input buffer
        }
    }
    cin.ignore(100, '\n');
    // Clears input buffer so extra input isn't applied to following cin statements
    
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

    //  POWERS & ROOTS MENU DISPLAY
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
    

    //  INPUT DECISION LOGIC
    cin.clear();
    // Clears input buffer from previous math operations

    bool menuValid = false;         // Flag to open and close while loop
    while (!menuValid)
    {
        cin >> prChoice;
        prChoice = tolower(prChoice);   
        // Converts uppercase char input to corresponding lowercase

        if (cin.good())
        // Checks whether input matches data type
        {
            if (prChoice >= 'a' && prChoice <= 'f')
            {
                cout << "You entered: '" << prChoice << "', that is correct input." << endl;
                menuValid = true;
                // Closes while loop
            }
            else if (prChoice == 'm')
            {
                cout << "You entered: '" << prChoice << "'. Returning to main menu..." << endl;
                menuValid = true;
                // Closes while loop
            }
            else if (prChoice == 'q')
            {
                cout << "You entered: '" << prChoice << "'. Goodbye!" << endl;
                menuValid = true;
                // Closes while loop
            }
            else
            {
            cout << "ERROR: You did not enter a valid option." << endl << endl;
            cout << "Please try again." << endl;
            cin.clear();
            cin.ignore(100, '\n');
            }
        } 
        else
        {
            cout << "ERROR: You did not enter a valid option." << endl << endl;
            cout << "Please try again:";
            cin.clear();            // Fixes error scroll
            cin.ignore(100, '\n');  // Ignores next 100 characters in input buffer
        }      
    }
    cin.ignore(100, '\n');
    // Clears input buffer so extra input isn't applied to following cin statements

    cout << endl << endl;

    return prChoice;
}


/*--------------------------------------------------------------------------------------------------
====================================================================================================
            INPUT FUNCTIONS
====================================================================================================
--------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------
FUNCTION:           getX()
DESCRIPTION:        Gets single user input for math functions
RETURNS:            N/A
NOTES:              
--------------------------------------------------------------------------------------------------*/
void getX()
{
    cout << "Please input x: ";

    bool xValid = false;            // Flag to open and close while loop
    while (!xValid)
    {
        cin >> x;

        if (cin.good())
        // Checks whether input matches data type
        {
            xValid = true;          // Closes while loop
        }
        else
        {
            cout << "ERROR: Input numbers only." << endl << endl;
            cout << "Please try again: ";
            cin.clear();
            cin.ignore(100, '\n');           
        }
    }

    cin.ignore(100, '\n');
    // Clears input buffer so extra input isn't applied to following cin statements
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           getXandY()
DESCRIPTION:        Gets two user inputs for math functions
RETURNS:            N/A
NOTES:              
--------------------------------------------------------------------------------------------------*/
void getXandY()
{
    cout << "Please input x and y: ";

    bool xValid = false;            // Flag to open and close while loop
    while (!xValid)
    {
        cin >> x;

        if (cin.good())
        // Checks whether input matches data type
        {
            xValid = true;
        }
        else
        {
            cout << "ERROR: Input numbers only." << endl << endl;
            cout << "Please try again: ";
            cin.clear();            // Fixes error scroll
            cin.ignore(100, '\n');  // Ignores next 100 characters in input buffer            
        }
    }

    bool yValid = false;            // Flag to open and close while loop
    while (!yValid)
    {
        cin >> y;

        if (cin.good())
        // Checks whether input matches data type
        {
            yValid = true;          // Closes while loop
        }
        else
        {
            cout << "ERROR: Input numbers only." << endl << endl;
            cout << "Please try again: ";
            cin.clear();            // Fixes error scroll
            cin.ignore(100, '\n');  // Ignores next 100 characters in input buffer             
        }  
    }

    cin.ignore(100, '\n');
    // Clears input buffer so extra input isn't applied to following cin statements
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           dataSelect()
DESCRIPTION:        Allows user to select int or float
RETURNS:            N/A
NOTES:              
--------------------------------------------------------------------------------------------------*/
bool dataSelect()
{
    char dataChoice;
    cout << "Integer or floating-point?" << endl;

    while (1) // Loop until return value is found
    {
        cout << "Enter your choice [i/f]: ";

        cin >> dataChoice;
        dataChoice = tolower(dataChoice);
        // Converts uppercase char input to corresponding lowercase

        switch (dataChoice)
        {
            case 'i':
                cout << "You selected: INTEGER" << endl << endl;
                cin.ignore(100, '\n');
                return true;
                break;
            case 'f':
                cout << "You selected: FLOATING POINT" << endl << endl;
                cin.ignore(100, '\n');
                return false;
                break;
            default:
                cout << "ERROR: Input I or F." << endl << endl;
                cin.clear();
                cin.ignore(100, '\n');
                break;
        }
    }
}


/*--------------------------------------------------------------------------------------------------
====================================================================================================
            ARITHMETIC FUNCTIONS
====================================================================================================
--------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------
FUNCTION:           add()
DESCRIPTION:        Addition function
RETURNS:            N/A
NOTES:              
--------------------------------------------------------------------------------------------------*/
void add()
{
    cout << "This function will add x and y... " << endl << endl;

    bool convertData = dataSelect();
    getXandY();
    if (convertData == true)
        {
            x = int(x);
            y = int(y);
            result = int(result);
        }
    
    result = x + y;
    cout << endl << "   x + y = " << x << " + " << y << " = " << result << endl << endl << endl;
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           subtract()
DESCRIPTION:        Subtraction function
RETURNS:            N/A
NOTES:              
--------------------------------------------------------------------------------------------------*/
void subtract()
{
    cout << "This function will subtract y from x... " << endl << endl;

    bool convertData = dataSelect();
    getXandY();
    if (convertData == true)
        {
            x = int(x);
            y = int(y);
            result = int(result);
        }
    
    result = x - y;
    cout << endl << "   x - y = " << x << " - " << y << " = " << result << endl << endl << endl;
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           multiply()
DESCRIPTION:        Multiplication function
RETURNS:            N/A
NOTES:              
--------------------------------------------------------------------------------------------------*/
void multiply()
{
    cout << "This function will multiply x by y... " << endl << endl;

    bool convertData = dataSelect();
    getXandY();
    if (convertData == true)
        {
            x = int(x);
            y = int(y);
            result = int(result);
        }
    
    result = x * y;
    cout << endl << "   x * y = " << x << " * " << y << " = " << result << endl << endl << endl;
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           divide()
DESCRIPTION:        Division function
RETURNS:            N/A
NOTES:              
--------------------------------------------------------------------------------------------------*/
void divide()
{
    cout << "This function will add x and y... " << endl << endl;

    bool convertData = dataSelect();
    getXandY();
    if (convertData == true)
        {
            x = int(x);
            y = int(y);
            result = int(result);
        }

    if (y == 0)
        {
            cout << "ERROR: Can't divide by zero." << endl << endl;
            cout << "Please try again." << endl << endl << endl;
        }
    else 
        {
            result = x + y;
            cout << endl << "   x + y = " << x << " + " << y << " = " << result << endl << endl << endl;
        }
}


/*--------------------------------------------------------------------------------------------------
====================================================================================================
            POWER & ROOT FUNCTIONS
====================================================================================================
--------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------
FUNCTION:           prSquare()
DESCRIPTION:        Square function
RETURNS:            N/A
NOTES:              
--------------------------------------------------------------------------------------------------*/
void prSquare()
{
    cout << "This function will square x... " << endl << endl;

    getX();
    result = pow(x, 2);

    cout << endl << "   x ^ 2 = " << x << " ^ 2 = " << result << endl;

    cout << endl << endl;
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           prCube()
DESCRIPTION:        Cube function
RETURNS:            N/A
NOTES:              
--------------------------------------------------------------------------------------------------*/
void prCube()
{
    cout << "This function will cube x... " << endl;
    cout << endl;

    getX();
    result = pow(x, 3);

    cout << endl;
    cout << "   x ^ 3 = " << x << " ^ 3 = " << result << endl;

    cout << endl << endl;
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           prPower()
DESCRIPTION:        Any power function
RETURNS:            N/A
NOTES:              
--------------------------------------------------------------------------------------------------*/
void prPower()
{
    cout << "This function will raise x to the power of y... " << endl;
    cout << endl;

    getXandY();
    result = pow(x, y);

    cout << endl;
    cout << "   x ^ y = " << x << " ^ " << y << " = " << result << endl;

    cout << endl << endl;
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           prSqrt()
DESCRIPTION:        Square root function
RETURNS:            N/A
NOTES:              
--------------------------------------------------------------------------------------------------*/
void prSqrt()
{
    cout << "This function will take the square root of x... " << endl;
    cout << endl;

    getX();
    if (x <= 0)
        {
            cout << "ERROR: Can't square root negatives." << endl << endl;
            cout << "Please try again." << endl << endl << endl;
        }
    else 
        {
            result = sqrt(x);
            cout << endl << "   x ^ 1/2 = " << x << " ^ 1/2 = " << result << endl << endl << endl;
        }
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           prCbrt()
DESCRIPTION:        Cube root function
RETURNS:            N/A
NOTES:              
--------------------------------------------------------------------------------------------------*/
void prCbrt()
{
    cout << "This function will take the cube root of x... " << endl;
    cout << endl;

    getX();
    result = cbrt(x);

    cout << endl;
    cout << "   x ^ 1/3 = " << x << " ^ 1/3 = " << result << endl;

    cout << endl << endl;
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           prRoot()
DESCRIPTION:        Any root function
RETURNS:            N/A
NOTES:              
--------------------------------------------------------------------------------------------------*/
void prRoot()
{
    cout << "This function will take the y'th root of x... " << endl;
    cout << endl;

    getXandY();
    result = pow(x, 1/y);

    cout << endl;
    cout << "   x ^ 1/y = " << x << " ^ 1/" << y << " = " << result << endl;

    cout << endl << endl;
}