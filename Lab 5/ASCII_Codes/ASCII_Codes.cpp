/*--------------------------------------------------------------------------------------------------
FILENAME:           template.cpp
DESCRIPTION:        Template for building stand-alone programs
COMPILER:           MinGW C++ compiler
NOTES:              Details on what this program does

MODIFICATION HISTORY:
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-10-22      0.1 - Created files, copied headers
Michael Ring        2020-10-22      0.2 - Created for loop and output logic
--------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const string PROGRAMMER_NAME = "Michael Ring";

/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        Say what this function does
RETURNS:            0
NOTES:              Optional notes on this function
--------------------------------------------------------------------------------------------------*/

int main()
{
    char letter;
    setw(16);
    for (letter = 1; letter <= 126; letter++)
    {
        cout << letter;
    }
    
    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl;
    cout << endl;

    system("pause");

    return 0;
}