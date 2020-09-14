/*--------------------------------------------------------------------------------------------------
FILENAME:           Get_Choice_v1.cpp
DESCRIPTION:        Subproject of Lab 3
COMPILER:           MinGW C++ compiler
NOTES:              Menu program

MODIFICATION HISTORY:
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-09-11      0.1 - Created files, copied headers
Michael Ring        2020-09-11      1.0 - Copied source code from Get_Choice_v1.gif and compiled
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

    if (choice == 'a' || choice == 'A')
        cout << "You entered an 'a', that is correct input." << endl;
    if (choice == 'b' || choice == 'B')
        cout << "You entered a 'b', that is correct input." << endl;
    if (choice == 'c' || choice == 'C')
        cout << "You entered a 'c', that is correct input." << endl;
    cout << endl << endl;

    
    //  GOODBYE

    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl;
    cout << endl;

    system("pause");

    return 0;
}