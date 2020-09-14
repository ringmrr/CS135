/*--------------------------------------------------------------------------------------------------
FILENAME:           Calculator_v1.cpp
DESCRIPTION:        Beginning version of Project 1 (Calculator)
COMPILER:           MinGW C++ compiler
NOTES:              

MODIFICATION HISTORY:
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-09-14      0.1 - Created files, copied headers
Michael Ring        2020-09-14      0.2 - Created functions from old programs, added prototypes
--------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

char GetChoice();
char choice;

const string PROGRAMMER_NAME = "Michael Ring";

/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        Driver function
RETURNS:            0
NOTES:              
--------------------------------------------------------------------------------------------------*/

int main()
{
    while(true)                     // Open while loop to keep the program running
    {
        choice = GetChoice();
        switch (choice)
        {
            case 'a':               // Goes to Add2Numbers()
                cout << "Add code to me please";
            case 'q':               // Goes to quit. You need some "exit" strategy here.
                cout << "Add code to me please";
        }
    }                               // Close while loop

    //  GOODBYE

    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl;
    cout << endl;

    system("pause");

    return 0;
}

char GetChoice()
{
    system("cls");


    //  MAIN MENU

    cout << endl << endl;   
    cout << "               Main Menu" << endl << endl;
    cout << endl << endl;
    cout << "   a   You are choosing letter a" << endl << endl;
    cout << "   b   You are choosing letter b" << endl << endl;
    cout << "   c   You are choosing letter c" << endl << endl;
    cout << endl << endl;
    cout << "Choose from the items above: ";
    cin >> choice;
    cout << endl << endl;

    
    //  INPUT DECISION LOGIC

    choice = tolower(choice);       // Converts uppercase char input to corresponding lowercase char

    if (choice >= 'a' && choice <= 'c')
        cout << "You entered: '" << choice << "', that is correct input." << endl;
    else
    {
        cout << "You did not enter 'a', 'b', or 'c'." << endl;
        cout << "Please rerun the program." << endl;
    }
    
    cout << endl << endl;
}

void Add2Numbers()
{
//  int x, y, sum;      
//  Despite not being assigned a value, the program automatically gives
//  x a value of -2, and y a random +/- value in the billions.
//  It also truncates any decimals entered by the user.
//  Negatives are okay.

    double x, y, sum;
//  Despite not being assigned a value, the program automatically gives
//  x a value of 1.79272e-307, and y a value of 8.00859e-307.
//  It can handle floating-point numbers, so decimals are acceptable.
//  Negatives are okay.

    cout << "The value of x is: " << x << endl;
    cout << "The value of y is: " << y << endl;
    cout << endl;

    cout << "This program will add x and y... " << endl;
    cout << endl << endl;
    cout << "Please input x and y: ";
    cin >> x;
    cin >> y;

    sum = x + y;

    cout << endl << endl;

    cout << "   x + y = " << x << " + " << y
         << " = " << sum << endl;

    cout << endl << endl;
}