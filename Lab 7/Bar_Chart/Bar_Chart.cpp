/*--------------------------------------------------------------------------------------------------
FILENAME:           Bar_Chart.cpp
DESCRIPTION:        Lab 7
COMPILER:           MinGW C++ compiler
NOTES:              Prep for Proj 3

MODIFICATION HISTORY:
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-11-18      0.1 - Created files, copied input file (people.txt).
Michael Ring        2020-11-18      0.2 - Created title header and * to 1000 people key
Michael Ring        2020-11-18      0.3 - Prepped for file input
Michael Ring        2020-11-18      0.4 - Created for loop
Michael Ring        2020-11-18      0.5 - Set up EditPlus to workaround NPP file open failures
Michael Ring        2020-11-18      1.0 - Successfully tested program.
--------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

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
    int year;
    int pop;
    int stars;

    ifstream infile;
    infile.open("People.txt");

    cout << "PRAIRIEVILLE POPULATION GROWTH" << endl;
    cout << "(each * represents 1,000 people)" << endl;

    for (year = 1900; infile >> pop; year += 20)
    {
        stars = pop / 1000;
        cout << year << " ";

        while (stars != 0)
            {
                cout << "*";
                stars --;
            }

        cout << endl;
    }

    infile.close();

    cout << endl;
    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl;
    system("pause");

    return 0;
}