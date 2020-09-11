/*--------------------------------------------------------------------------------------------------
FILENAME:           Space.cpp
DESCRIPTION:        Subproject of Lab 2
COMPILER:           MinGW C++ compiler
NOTES:              

MODIFICATION HISTORY:
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-09-10      0.1 - Created files, copied headers
Michael Ring        2020-09-10      0.2 - Copied Program 2-16 from textbook
--------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const string PROGRAMMER_NAME = "Michael Ring";

/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        
RETURNS:            0
NOTES:              
--------------------------------------------------------------------------------------------------*/

int main()
{
    float distance;
    double mass;

    distance= 1.495979E11;
    mass = 1.989E30;
    cout << "The Sun is " <<distance<< " meters away.\n";
    cout << "The Sun\'s mass is " <<mass<<" kilograms.\n";
    
    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl;
    cout << endl;

    system("pause");

    return 0;
}