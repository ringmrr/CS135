/*--------------------------------------------------------------------------------------------------
FILENAME:           hello.cpp
DESCRIPTION:        First program for CS135
COMPILER:           MinGW C++ compiler
NOTES:              Written in Visual Studio Code

MODIFICATION HISTORY:
Author              Date           Version
---------------     ----------     ---------------
Michael Ring        2020-08-26     0.1 - Copied example code from page 12. Program instantly closes.
Michael Ring        2020-08-26     0.2 - Added system pause. Program now stays open.
Michael Ring        2020-08-26     0.3 - Added file/function headers, as well as name/timestamp.
Michael Ring        2020-08-26     1.0 - Included <iomanip> and <string>
--------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <string>

using namespace std;

const string PROGRAMMER_NAME = "Michael Ring";

/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        Says hello, then pauses.
RETURNS:            0
NOTES:              Simple as that.
--------------------------------------------------------------------------------------------------*/
int main()
{
    cout << "Hello, world!\n" << endl;
    
    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl;
    cout << endl;

    system("pause");
    return 0;
}