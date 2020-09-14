/*--------------------------------------------------------------------------------------------------
FILENAME:           Add_2_Numbers.cpp
DESCRIPTION:        Subproject of Lab 3a
COMPILER:           MinGW C++ compiler
NOTES:              Create a prototype calculator for Project 1

MODIFICATION HISTORY:
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-09-11      0.1 - Created files, copied headers
Michael Ring        2020-09-11      1.0 - Copied source code from Add_2_Numbers.gif and compiled
Michael Ring        2020-09-11      1.1 - Tested and commented
--------------------------------------------------------------------------------------------------*/

#include <iostream>

using namespace std;

const string PROGRAMMER_NAME = "Michael Ring";

/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        Take 2 numbers and add them
RETURNS:            0
NOTES:              
--------------------------------------------------------------------------------------------------*/

int main()
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

    cout << "Goodbye..." << endl;
    cout << endl << endl;

    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl;
    cout << endl;

    system("pause");

    return 0;
}