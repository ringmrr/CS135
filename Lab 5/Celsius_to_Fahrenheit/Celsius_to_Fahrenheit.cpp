/*--------------------------------------------------------------------------------------------------
FILENAME:           Celsius_to_Fahrenheit.cpp
DESCRIPTION:        Subproject of Lab 5
COMPILER:           MinGW C++ compiler
NOTES:

MODIFICATION HISTORY:
Author              Date           Version
---------------     ----------     ---------------
Michael Ring        2020-10-14     0.1 - 
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
        cout << "Fahrenheit or Celsius [F/C]: ";
        cin >> scale;
        scale = tolower(scale);
        cin.sync();

        switch (scale)
        {
            case 'f':
                cout << "Enter the temperature in Fahrenheit: ";
                cin >> fahrenheit;
                cin.clear();
                goodbye = true;
                break;
            case 'c':
                cout << "Enter the temperature in Celsius: ";
                cin >> celsius;
                cin.clear();
                fahrenheit = (9/5) * celsius + 32;
                cout << celsius << " C is:   " << fahrenheit << " F." << endl;
                goodbye = true;
                break;
            default:
                cout << "You did not enter a valid option. Please try again." << endl;
                break;
        }
    }
    
    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl;
    cout << endl;

    system ("pause");
    return 0;
}