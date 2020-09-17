/*--------------------------------------------------------------------------------------------------
FILENAME:           Calculator_v2.cpp
DESCRIPTION:        Beginning version of Project 1 (Calculator)
COMPILER:           MinGW C++ compiler
NOTES:              

MODIFICATION HISTORY:
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-09-14      1.0 - Copied Calculator_v1, adjusted name and file header
                                            >> Source code copied from:
                                                > Add_2_Numbers.gif on Canvas
                                                > Get_Choice_v(1-6).gifs on Canvas
                                                > Program 6-17 from Textbook pg. 342
Michael Ring        2020-09-16      1.1 - Added bool flag 'goodbye' which allows loop to be closed
                                                > case 'q' now sets 'goodbye' to true and quits
Michael Ring        2020-09-16      2.0 - Added new function getXandY for modularity
--------------------------------------------------------------------------------------------------*/

// Required preprocessor directives
#include <iostream>    
#include <iomanip>
#include <string>

// Namespace
using namespace std;

// Function prototypes
char GetChoice();
void getXandY();      
void Add2Numbers();

// Global constants
const string PROGRAMMER_NAME = "Michael Ring";

// Global variables
double x, y, sum;

/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        Driver function
RETURNS:            0
NOTES:              
--------------------------------------------------------------------------------------------------*/

int main()
{
    system("cls");                  // Clears the screen (nothing to clear unless opened from cmd)

    char choice;                    // Declares variable for menu selections

    bool goodbye = false;           // Flag allows loop to be closed when switched to true
    while(!goodbye)                 // Open while loop to allow multiple uses without restarting
    {
        choice = GetChoice();       // Calls function GetChoice to get user's selection
        switch (choice)
        {
            case 'a':
                Add2Numbers();      // If choice == a, call Add2Numbers function
                break;
            case 'q':
                goodbye = true;
                break;
        }
    }                              

    //  GOODBYE

    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl;
    cout << endl;

    system("pause");

    return 0;
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           GetChoice()
DESCRIPTION:        Main Menu and selection logic
RETURNS:            choice
NOTES:              
--------------------------------------------------------------------------------------------------*/
char GetChoice()
{
    char choice;

    //  MAIN MENU

    cout << endl << endl;   
    cout << "               Main Menu" << endl << endl;
    cout << endl << endl;
    cout << "   a   Add two numbers" << endl << endl;
    cout << "   b   You are choosing letter b" << endl << endl;
    cout << "   c   You are choosing letter c" << endl << endl;
    cout << endl << endl;
    cout << "   q   Quit" << endl << endl;
    cout << endl << endl;
    cout << "Choose from the items above: ";
    cin >> choice;
    cout << endl << endl;

    
    //  INPUT DECISION LOGIC

    choice = tolower(choice);       // Converts uppercase char input to corresponding lowercase char

    if (choice >= 'a' && choice <= 'c')
        cout << "You entered: '" << choice << "', that is correct input." << endl << endl;
    else if (choice == 'q')
        cout << "You entered: '" << choice << "'. Goodbye!" << endl << endl;
    else
    {
        cout << "You did not enter a valid option." << endl;
        cout << "Please rerun the program." << endl;
    }

    cout << endl << endl;

    return choice;
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
FUNCTION:           Add2Numbers()
DESCRIPTION:        Addition function
RETURNS:            N/A
NOTES:              
--------------------------------------------------------------------------------------------------*/
void Add2Numbers()
{
    cout << "This program will add x and y... " << endl;
    cout << endl << endl;
    getXandY();

    sum = x + y;

    cout << endl << endl;

    cout << "   x + y = " << x << " + " << y
         << " = " << sum << endl;

    cout << endl << endl;
}