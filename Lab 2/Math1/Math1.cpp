/*--------------------------------------------------------------------------------------------------
FILENAME:           Math1.cpp
DESCRIPTION:        Subproject of Lab 2 & Project 1
COMPILER:           MinGW C++ compiler
NOTES:              

MODIFICATION HISTORY:
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-09-07      0.1 - Created files, copied headers
Michael Ring        2020-09-07      0.2 - Copied source code, tried to compile
Michael Ring        2020-09-10      1.0 - Uncommented #include <cmath> and compiled successfully
Michael Ring        2020-09-10      1.1 - 
--------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

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
    int x;
    unsigned int y;

    double PI = 3.14159265;
    double angle;
    double sinOfTheAngle;

    x = -17;
    y = -5;

    cout << endl << endl;
    cout << "The value in x is: " << x << endl
         << "The value in y is: " << y << endl;
    cout << endl << endl;

    x = -17;
    y = abs(-5.0);      

//  The unsigned data type causes -5 to underflow to +4294967291 ((2^32)-5).
//  The absolute value remains 4294967291, because it wrapped around to a positive value.

//  Commenting out the other cout statements causes only
//  first example's results to be printed to the console


//  cout << "The value in x is: " << x << endl
//       << "The value in y is: " << y << endl;
//  cout << endl << endl;

//  cout << "PI = " << PI << endl;
    angle = PI / 4;     // 45 degree angle
//  cout << "angle = PI/4 = " << angle << " = 45 deg. ";
//  cout << endl << endl;

    sinOfTheAngle = sin(angle);

//  cout << "sin of angle = " << sinOfTheAngle << endl;
//  cout << "sin of angle = " << setprecision(20) << sinOfTheAngle;
//  cout << endl << endl;
//  cout << " sqrt(2)/2 = " << sqrt(2)/2 << endl << endl;

//  cout << "The sin value is: " <<< setprecision(20) << setw(50)
//       << setfill ('x') << sinOfTheAngle << endl;
//  cout << "The sin value is: " << setprecision(20) << setw(50)
//       << left << setfill('$') << sinOfTheAngle << endl;
//  cout << endl << endl;

//  cout << "Goodbye..." << endl;
//  cout << endl << endl;

    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl;
    cout << endl;

    system("pause");

    return 0;
}