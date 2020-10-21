/*--------------------------------------------------------------------------------------------------
FILENAME:           Celsius_to_Fahrenheit.cpp
DESCRIPTION:        Subproject of Lab 5
COMPILER:           MinGW C++ compiler
NOTES:

MODIFICATION HISTORY:
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-10-14      0.1 - Copied template, added preprocessor directives + namespace
Michael Ring        2020-10-19      0.2 - Defined variables (goodbye, scale, fahrenheit, celsius)
Michael Ring        2020-10-19      0.3 - Created loop, added logic for C-to-F selection   
Michael Ring        2020-10-19      0.4 - Added logic for conversion
Michael Ring        2020-10-19      0.5 - Added cin.sync to F/C input so entering a string doesn't 
                                          throw an error for every character
Michael Ring        2020-10-21      1.0 - Added input validation for temperature
Michael Ring        2020-10-21      1.1 - Added degree symbol, fixed line spacing
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
    bool goodbye = false;

    char scale;
    float fahrenheit;
    float celsius;


    while (!goodbye)
    {
        cout << endl << "Fahrenheit or Celsius [F/C]:   ";
        cin >> scale;
        scale = tolower(scale);
        cin.sync();

        switch (scale)
        {
            case 'f':
                cout << endl << "Enter the temperature in Fahrenheit:   ";
                cin >> fahrenheit;
                cout << endl;
                if (cin.good())
                {   // Calculates and prints result
                    celsius = ((fahrenheit - 32) * 5) / 9;
                    cout << fahrenheit << " F" << "\370" << "is:   ";
                    cout << celsius << " C" << "\370" << "." << endl << endl;
                }
                else
                {   // Validates temperature input
                    cout << "ERROR: Input numbers only." << endl;
                    cout << "Please rerun the program." << endl << endl;            
                }
                goodbye = true;
                break;
            case 'c':
                cout << endl << "Enter the temperature in Celsius: ";
                cin >> celsius;
                cout << endl;
                if (cin.good())
                {   // Calculates and prints result
                    fahrenheit = ((celsius * 9) / 5) + 32;
                    cout << celsius << " C" << "\370" << "is:   ";
                    cout << fahrenheit << " F" << "\370" << "." << endl << endl;
                }
                else
                {   // Validates temperature input
                    cout << "ERROR: Input numbers only." << endl;
                    cout << "Please rerun the program." << endl << endl;            
                }
                goodbye = true;
                break;
            default:    
                // Validates C/F choice
                cout << "You did not enter a valid option. Please try again.";
                break;
        }
    }
    
    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl;

    system ("pause");
    return 0;
}