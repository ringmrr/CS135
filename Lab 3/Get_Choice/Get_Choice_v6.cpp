/*--------------------------------------------------------------------------------------------------
FILENAME:           Get_Choice_v6.cpp
DESCRIPTION:        Subproject of Lab 3
COMPILER:           MinGW C++ compiler
NOTES:              Menu program

MODIFICATION HISTORY:
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-09-11      0.1 - Created files, copied headers
Michael Ring        2020-09-11      1.0 - Copied source code from Get_Choice_v1.gif and compiled
Michael Ring        2020-09-14      2.0 - Modify if statements to be if-else statements
                                                > Program now catches invalid input.
Michael Ring        2020-09-14      3.0 - Replaced if-else statement with a switch statement
                                                > Program no longer catches invalid input,
                                                  nor does it accept uppercase input.
Michael Ring        2020-09-14      4.0 - Handle upper and lowercase input, add default case
                                                > Program accepts all cases, catches invalid input.
Michael Ring        2020-09-14      5.0 - Simplified the switch to have only one output line
                                                > Program is functionally the same, but neater
Michael Ring        2020-09-14      6.0 - Switch back to an "if" to simplify further, add 'tolower'
                                                > Program is functionally the same, but neater
--------------------------------------------------------------------------------------------------*/

#include <iostream>

using namespace std;

const string PROGRAMMER_NAME = "Michael Ring";

/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        Reads letters chosen from menu
RETURNS:            0
NOTES:         
--------------------------------------------------------------------------------------------------*/

int main()
{
    char choice;

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

    
    //  GOODBYE

    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl;
    cout << endl;

    system("pause");

    return 0;
}