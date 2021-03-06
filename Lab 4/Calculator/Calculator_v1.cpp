/*--------------------------------------------------------------------------------------------------
FILENAME:           Calculator_v1.cpp
DESCRIPTION:        Beginning version of Project 1 (Calculator)
COMPILER:           MinGW C++ compiler
NOTES:              

MODIFICATION HISTORY:
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-09-14      0.1 - Created files, copied headers
                                            >> Source code copied from:
                                                > Add_2_Numbers.gif on Canvas
                                                > Get_Choice_v(1-6).gifs on Canvas
Michael Ring        2020-09-14      0.2 - Created functions from old programs
Michael Ring        2020-09-14      0.3 - Added function prototypes and successfully compiled
Michael Ring        2020-09-16      0.4 - Added 'q' selection to GetChoice()
                                            > q is now recognized as correct input, but like
                                            > b and c, it does nothing but print a message.
Michael Ring        2020-09-16      1.0 - Added q to menu message, added more comments
--------------------------------------------------------------------------------------------------*/

// Required preprocessor directives
#include <iostream>    
#include <iomanip>
#include <string>

// Namespace
using namespace std;

// Function prototypes
char GetChoice();       
void Add2Numbers();

// Declared global constants
const string PROGRAMMER_NAME = "Michael Ring";

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

    while(true)                     // Open while loop to keep the program running
    {
        choice = GetChoice();       // Calls function GetChoice to get user's selection
        switch (choice)
        {
            case 'a':
                Add2Numbers();      // If choice == a, call Add2Numbers function
                break;
            case 'q':
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
FUNCTION:           Add2Numbers()
DESCRIPTION:        Addition function
RETURNS:            N/A
NOTES:              Inputting characters for x and/or y results in an infinite scroll
--------------------------------------------------------------------------------------------------*/
void Add2Numbers()
{
    double x, y, sum;

    cout << "This program will add x and y... " << endl;
    cout << endl << endl;
    cout << "Please input x and y: ";
    cin >> x;       // <!> BUG <!>
    cin >> y;       // Inputting characters rather than numbers results in an infinite scroll    

    sum = x + y;

    cout << endl << endl;

    cout << "   x + y = " << x << " + " << y
         << " = " << sum << endl;

    cout << endl << endl;
}