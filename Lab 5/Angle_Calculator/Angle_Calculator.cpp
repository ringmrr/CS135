/*--------------------------------------------------------------------------------------------------
FILENAME:           Angle_Calculator.cpp
DESCRIPTION:        Subproject of Lab 5
COMPILER:           MinGW C++ compiler
NOTES:

MODIFICATION HISTORY:
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-10-21      1.0 - Copied base from Celsius_to_Fahrenheit.cpp
Michael Ring        2020-10-21      1.1 - Modified to suit d/r selection
Michael Ring        2020-10-21      1.2 - Added global constants
Michael Ring        2020-10-21      1.3 - Replaced conversion logic and output
Michael Ring        2020-10-21      1.4 - Using setprecision and fixed manipulators
Michael Ring        2020-10-21      1.5 - Added trig functions
--------------------------------------------------------------------------------------------------*/

//PREPROCESSOR DIRECTIVES
#include <iostream>
#include <iomanip>
#include <string>
#include <cmath>

// NAMESPACE
using namespace std;

// GLOBAL CONSTANTS
const float PI = 3.14159;
const float RAD_PER_DEG = PI/180;
const float DEG_PER_RAD = 180/PI;
const string PROGRAMMER_NAME = "Michael Ring";

/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        
RETURNS:            0
NOTES:              
--------------------------------------------------------------------------------------------------*/
int main()
{
    bool goodbye = false;
    char scale;
    float deg;
    float rad;


    while (!goodbye)
    {
        cout << endl << "Degrees or radians [d/r]:   ";
        cin >> scale;
        scale = tolower(scale);
        cin.sync();

        switch (scale)
        {
            case 'd':
                cout << endl << "Enter an angle in degrees:   ";
                cin >> deg;
                cout << endl;
                if (cin.good())
                {   // Calculates and prints result
                    rad = deg * RAD_PER_DEG;
                    cout << "   " << deg << "\370  =  ";
                    cout << setprecision(4) << fixed << rad << " radians." << endl << endl;
                }
                else
                {   // Validates angle input
                    cout << "ERROR: Input numbers only." << endl;
                    cout << "Please rerun the program." << endl << endl;            
                }

                goodbye = true;
                break;
            case 'r':
                cout << endl << "Enter an angle in degrees:   ";
                cin >> rad;
                cout << endl;
                if (cin.good())
                {   // Calculates and prints result
                    deg = rad * DEG_PER_RAD;
                    cout << "   " << deg << "\370  =  ";
                    cout << setprecision(4) << fixed << rad << " radians" << endl << endl;
                }
                else
                {   // Validates angle input
                    cout << "ERROR: Input numbers only." << endl;
                    cout << "Please rerun the program." << endl << endl;            
                }
                goodbye = true;
                break;
            default:    
                // Validates d/r choice
                cout << "You did not enter a valid option. Please try again.";
                break;
        }
    }
    
    cout << "Sine:      " << setprecision(4) << fixed << sin(rad) << endl;
    cout << "Cosine:    " << setprecision(4) << fixed << cos(rad) << endl;
    cout << "Tangent:   " << setprecision(4) << fixed << tan(rad) << endl;
    cout << endl;

    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl;

    system ("pause");
    return 0;
}