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
--------------------------------------------------------------------------------------------------*/

// Required preprocessor directives
#include <iostream>    
#include <iomanip>
#include <string>
#include <cmath>

// Namespace
using namespace std;

// Function prototypes
char mainMenu();
bool prMain();
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

    char mainChoice;                // Declares variable for menu selections

    bool goodbye = false;           // Used to open and close while loop
    while (!goodbye)                 // Open while loop to allow multiple uses without restarting
    {
        mainChoice = mainMenu();    // Calls function mainMenu to get user's selection
        bool prQuit;

        switch (mainChoice)
        {
            case 'a':
                add();              // If mainChoice == a, call add function
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
                prQuit = prMain();
                if (prQuit == true)
                    goodbye = true;
                break;
            case 'q':
                goodbye = true;
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
    bool exit = false;
    char prChoice;

    while (!exit)                 
    {
        prChoice = prMenu();    
        switch (prChoice)
        {
            case 'a':
                prSquare();
                break;
            case 'b':
                prCube();    
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
                exit = true;
            case 'q':
                return true;
                break;
        }
    }

    return false;
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
    

    //  INPUT DECISION LOGIC

    cin >> mainChoice;
    cout << endl;
    mainChoice = tolower(mainChoice);       
    // Converts uppercase char input to corresponding lowercase char

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
    

    //  INPUT DECISION LOGIC
    cin >> prChoice;
    cout << endl;
    prChoice = tolower(prChoice);   

    if (prChoice >= 'a' && prChoice <= 'f')
        cout << "You entered: '" << prChoice << "', that is correct input." << endl << endl;
    else if (prChoice == 'm')
        cout << "You entered: '" << prChoice << "', that is correct input." << endl << endl;
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
====================================================================================================
            MATH INPUT FUNCTIONS
====================================================================================================
--------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------
FUNCTION:           getX()
DESCRIPTION:        Gets single user input for math functions
RETURNS:            N/A
NOTES:              Inputting characters for x results in an infinite scroll
--------------------------------------------------------------------------------------------------*/
void getX()
{
    char dataChoice;
    cout << "Interger or floating-point?" << endl;
    cout << "Enter your choice [i/f]: ";
    cin >> dataChoice;
    dataChoice = tolower(dataChoice);

    switch (dataChoice)
    {
        case 'i':
            cout << "You selected: INTERGER" << endl;
            x = int(x);
            result = int(result);
            break;
        case 'f':
            cout << "You selected: FLOATING-POINT" << endl;
            break;
        default:
            cout << "You did not select a valid input. Please re-run the function." << endl;
    }

    cout << "Please input x: ";
    cin >> x;       // <!> BUG <!>  Same as getXandY
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           getXandY()
DESCRIPTION:        Gets two user inputs for math functions
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
    cout << "This function will add x and y... " << endl;
    cout << endl;

    getXandY();
    result = x + y;

    cout << endl;
    cout << "   x + y = " << x << " + " << y << " = " << result << endl;

    cout << endl << endl;
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
    cout << "This function will square x... " << endl;
    cout << endl;

    getX();
    result = pow(x, 2);

    cout << endl;
    cout << "   x ^ 2 = " << x << " ^ 2 = " << result << endl;

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
    result = sqrt(x);

    cout << endl;
    cout << "   x ^ 1/2 = " << x << " ^ 1/2 = " << result << endl;

    cout << endl << endl;
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