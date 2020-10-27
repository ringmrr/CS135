/*--------------------------------------------------------------------------------------------------
FILENAME:           Math_Tutor.cpp
DESCRIPTION:        Subproject of Lab 6
COMPILER:           MinGW C++ compiler
NOTES:             

MODIFICATION HISTORY:
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-10-26      0.1 - Copied from template
Michael Ring        2020-10-26      0.2 - Set up while loop in main to call new menu() function
Michael Ring        2020-10-26      0.3 - Created menu output and int input/return
Michael Ring        2020-10-26      0.4 - Added function prototypes and respective cases
Michael Ring        2020-10-26      0.5 - 
--------------------------------------------------------------------------------------------------*/

// PREPROCESSOR DIRECTIVES
#include <iostream>
#include <iomanip>
#include <string>

// NAMESPACE
using namespace std;

// FUNCTION PROTOTYPES
int menu();

void add();
void subtract();
void multiply();
void divide();

// NAMED CONSTANTS
const string PROGRAMMER_NAME = "Michael Ring";

/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        Say what this function does
RETURNS:            0
NOTES:              Optional notes on this function
--------------------------------------------------------------------------------------------------*/

int main()
{
    bool goodbye = false;
    while(!goodbye)
    {
        int choice = menu();
        cout << "chose " << choice << endl;
        switch (choice)
        {
            case 1:
                add();
                break;
            case 2:
                subtract();
                break;
            case 3:
                multiply();
                break;
            case 4:
                divide();
                break;
            case 5:
                goodbye = true;
                break; // unnecessary
        }
    }

    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl;
    cout << endl;

    system("pause");
    return 0;
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           menu()
DESCRIPTION:        
RETURNS:            choice
NOTES:              No comments necessary -- pretty self explanatory
--------------------------------------------------------------------------------------------------*/
int menu()
{
    cout << "        Math Tutor Menu"         << endl;
    cout << "-------------------------------" << endl;
    cout << "1. Addition problem"             << endl;
    cout << "2. Subtraction problem"          << endl;
    cout << "3. Multiplication problem"       << endl;
    cout << "4. Diision problem"              << endl;
    cout << "5. Quit this program"            << endl;
    cout << "-------------------------------" << endl;
    cout << "Enter your choice (1-5): ";

    int choice;

    bool valid = false;
    while (!valid)
    {
        cin >> choice;
        cin.clear();
        if (cin.good())
        {
            if (choice <= 5 && choice >= 0)
                return choice;            
        }
        else
            cout << "ERROR: Invalid input. Please try again.";
    }
    cin >> choice;
    return choice;
}   

/*--------------------------------------------------------------------------------------------------
FUNCTION:           add()
DESCRIPTION:        
RETURNS:            void
NOTES:
--------------------------------------------------------------------------------------------------*/
void add()
{
    //P129 (159)
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           subtract()
DESCRIPTION:        
RETURNS:            void
NOTES:
--------------------------------------------------------------------------------------------------*/
void subtract()
{

}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           multiply()
DESCRIPTION:        
RETURNS:            void
NOTES:
--------------------------------------------------------------------------------------------------*/
void multiply()
{

}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           divide()
DESCRIPTION:        
RETURNS:            void
NOTES:
--------------------------------------------------------------------------------------------------*/
void divide()
{

}