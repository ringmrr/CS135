/*--------------------------------------------------------------------------------------------------
FILENAME:           Strings1.cpp
DESCRIPTION:        Subproject of Lab 2
COMPILER:           MinGW C++ compiler
NOTES:              Demonstrate usage of cin versus getline() for input

MODIFICATION HISTORY:
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-09-10      0.1 - Created files, copied headers
Michael Ring        2020-09-10      0.2 - Copied source code from Math1.gif, compiled, and ran
Michael Ring        2020-09-10      0.3 - Uncommented cin statements on lines 36 and 41.
                                                > 'name " you live in " state' no longer prints.
Michael Ring        2020-09-10      1.0 - Added notes to function main()
--------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const string PROGRAMMER_NAME = "Michael Ring";

/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        Testing differences between cin and getline
RETURNS:            0
NOTES:              'getline()' takes an entire line of input from the user to put into a string,
                    whereas 'cin' stops after it sees a space. If a user inputs multiple words
                    with a cin statement, the subsequent words will automatically be input for
                    following cin statements. 
--------------------------------------------------------------------------------------------------*/

int main()
{
    string name;
    string state;

    cout << endl << "What is your full name? ";
    cin >> name;    
    getline(cin, name);
    cout << endl << endl;

    cout << endl << "What state do you live in? ";
    cin >> state;    
    getline(cin, state);
    cout << endl << endl;

    cout << name << " you live in " << state << endl;
    cout << endl << endl;

    cout << "The 5th character you typed is: " << state[4] << endl;
    cout << endl << endl;

    cout << "Goodbye." << endl;
    cout << endl << endl;

    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl;
    cout << endl;

    system("pause");

    return 0;
}