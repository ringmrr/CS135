/*--------------------------------------------------------------------------------------------------
FILENAME:           Math_Testor.cpp
DESCRIPTION:        Subproject of Lab 6
COMPILER:           MinGW C++ compiler
NOTES:             

MODIFICATION HISTORY:
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-10-28      1.0 - Copied from Math_Tutor3.cpp
Michael Ring        2020-10-28      1.1 - Adjusted menus to match output examples
Michael Ring        2020-11-02      1.2 - Fixed case and input validation to accept characters
Michael Ring        2020-11-02      1.3 - Separated difficulty into its own function
Michael Ring        2020-11-09      1.4 - Fixed RNG to have proper min/max range from difficulty
Michael Ring        2020-11-09      1.5 - Corrected math problem alignment
Michael Ring        2020-11-11      1.6 - Added input validation for difficulty
Michael Ring        2020-11-12      1.7 - Added problem # counter (using a for loop)
Michael Ring        2020-11-12      1.8 - Changed fill-in-the-blank to multiple choice
Michael Ring        2020-11-12      1.9 - Randomize incorrect answers
Michael Ring        2020-11-12      2.0 - Allow for 3 attempts per question
--------------------------------------------------------------------------------------------------*/

// PREPROCESSOR DIRECTIVES
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>
#include <cmath>
#include <fstream>

// NAMESPACE
using namespace std;

// FUNCTION PROTOTYPES
string user();
int difficulty();

char menu();

void rng(int level, int &x, int &y);
void answer(int result);

void add(int level);
void subtract(int level);
void multiply(int level);
void divide(int level);

// NAMED CONSTANTS
const string PROGRAMMER_NAME = "Michael Ring";

/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        Driver function
RETURNS:            0
NOTES:              Function redirection and quitting
--------------------------------------------------------------------------------------------------*/
int main()
{
    // Gets the system time and seeds RNG
    time_t start = time(0);
    srand(start);  

    // Asks user for their name, puts it into a string variable
    string name = user();

    // Difficulty selection
    int level = difficulty();

    // Header
    cout << "Student name: " << name << endl;
    cout << "Program start: " << ctime(&start);
    cout << "Random seed: " << start << endl << endl; 

    // Opens file
    ofstream outputFile;    
    outputFile.open(name);

    // Introduction
    cout << "          ARITHMETIC PRACTICE PROGRAM"                     << endl << endl;
    cout << "Welcome to the Math Skills Practice Program."              << endl << endl;
    cout << "This program allows you to practice your math skills."     << endl << endl;
    cout << "Choose what you want to practice in the menu shown below." << endl << endl << endl;

    // Counts number of problems
    int problem;

    // Function selection
    bool goodbye = false;
    for (problem = 1; !goodbye; problem++)
    {
        char choice = menu();
        switch (choice)
        {
            case 'a':
                cout << "Problem no. " << problem << ": " << ctime(&start) << endl;
                add(level);
                break;
            case 'b':
                cout << "Problem no. " << problem << ": " << ctime(&start) << endl;
                subtract(level);
                break;
            case 'c':
                cout << "Problem no. " << problem << ": " << ctime(&start) << endl;
                multiply(level);
                break;
            case 'd':
                cout << "Problem no. " << problem << ": " << ctime(&start) << endl;
                divide(level);
                break;
            case 'q':
                goodbye = true;
        }
    }

    // Goodbye!
    outputFile.close();
    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl;
    system("pause");
    return 0;
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           user()
DESCRIPTION:        
RETURNS:            name
NOTES:
--------------------------------------------------------------------------------------------------*/
string user()
{
    string name;
    cout << "What is your first and last name?  ";
    getline(cin, name);
    cout << endl;
    return name;
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           difficulty()
DESCRIPTION:        Difficulty menu & selection
RETURNS:            level
NOTES:
--------------------------------------------------------------------------------------------------*/
int difficulty()
{
    cout << "Please select difficulty level:" << endl;
    cout << "1. 1 digit" << endl;
    cout << "2. 2 digits" << endl;
    cout << "3. 3 digits" << endl;
    cout << "4. 4 digits" << endl;
    cout << "5. 5 digits" << endl;

    int level;                      // Holds difficulty selection
    bool valid = false;             // Keeps loop open until selection is valid
    while (!valid)
    {
        cout << "Please enter 1-5 only: ";
        cin >> level;
        cin.clear();
        cin.ignore(100, '\n');
        if (level > 0 && level < 6)
            valid = true;   
    }

    cout << "Difficulty #: " << level << endl << endl;
    return level;
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           menu()
DESCRIPTION:        Displays menu and receives user selection
RETURNS:            choice
NOTES:
--------------------------------------------------------------------------------------------------*/
char menu()
{
    // Menu display
    cout << "---------------------------------------------------------" << endl;
    cout << "              ARITHMETIC PRACTICE PROGRAM"                 << endl;
    cout << "                      MAIN MENU"                           << endl;  
    cout << "---------------------------------------------------------" << endl;
    cout << "              a. Addition" << endl;
    cout << "              b. Subtraction" << endl;
    cout << "              c. Multiplication" << endl;
    cout << "              d. Division" << endl;
    cout << "              q. Quit the program" << endl;
    cout << "---------------------------------------------------------" << endl;
    cout << "          Enter your choice [ a b c d q ]: ";
    
    // Input and validation
    char choice;
    bool valid = false;
    while (!valid)
    {
        cin >> choice;
        cin.clear();
        cin.ignore(100, '\n');

        if (cin.good())
            if (choice >= 'a' && choice <= 'q')
                valid = true;
        else
            cout << "ERROR: Invalid input. Please try again.";
    }
    cout << "---------------------------------------------------------" << endl;

    cout << endl;
    return choice;
}   

/*--------------------------------------------------------------------------------------------------
FUNCTION:           rng()
DESCRIPTION:        Seeds RNG from system time, and continues randomizing x and y until valid
RETURNS:            N/A
NOTES:
--------------------------------------------------------------------------------------------------*/
void rng(int level, int &x, int &y)
{
    int min = pow(10, level - 1);
    int max = pow(10, level);

    x = (rand() % (max - min + 1)) + min;
    y = (rand() % (max - min + 1)) + min;
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           answer()
DESCRIPTION:        Gets answer for math question
RETURNS:            N/A
NOTES:
--------------------------------------------------------------------------------------------------*/
void answer(int result)
{
    // Sets up variables for choice output
    int a, b, c, d;

    // Selects the correct answer and adjusts the incorrect choices
    int randomize = (rand() % (101 - 97 + 1)) + 97;
    char correct = randomize;
    switch (correct)
    {
        case 'a':
            a = result;
            b = result + ((rand() % (25)) + 1);
            c = result - ((rand() % (25)) + 1);
            d = result + ((rand() % (25)) + 1);
            break;
        case 'b':
            a = result + ((rand() % (25)) + 1);
            b = result;
            c = result - ((rand() % (25)) + 1);
            d = result + ((rand() % (25)) + 1);
            break;
        case 'c':
            a = result + ((rand() % (25)) + 1);
            b = result - ((rand() % (25)) + 1);
            c = result;
            d = result + ((rand() % (25)) + 1);
            break;
        case 'd':
            a = result + ((rand() % (25)) + 1);
            b = result - ((rand() % (25)) + 1);
            c = result + ((rand() % (25)) + 1);
            d = result;
            break;
        case 'e':
            a = result + ((rand() % (25)) + 1);
            b = result - ((rand() % (25)) + 1);
            c = result + ((rand() % (25)) + 1);
            d = result - ((rand() % (25)) + 1);
            break;
    }

    // Prints choices
    cout << "(a)  " << a << endl;
    cout << "(b)  " << b << endl;
    cout << "(c)  " << c << endl;
    cout << "(d)  " << d << endl;
    cout << "(e)   NONE OF THE ABOVE" << endl;

    // Tests user choice with 3 chances
    char choice;
    int chances;
    for (chances = 3; chances != 0; chances--)
    {
        cout << endl << "Choice: ";
        cin >> choice;
        if (choice == correct)
        {
            cout << "Congratulations!" << endl;
            cout << "  " << result << " is the correct answer." << endl;
            chances = 1;
        }
        else
        {
            if (chances != 1)
                cout << "Sorry, try again..." << endl;
        }
    }

}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           add()
DESCRIPTION:        Prints addition problem and gets answer from user
RETURNS:            N/A
NOTES:
--------------------------------------------------------------------------------------------------*/
void add(int level) 
{
    // Variable declarations
    int x, y, result;

    // Generates numbers to be added
    rng(level, x, y);

    // Calculates the result, stores it as variable
    result = x + y;

    // Print calculation without result
    cout << "   " << setw(7) << right << x << endl;
    cout << "   " << "+" << setw(6) << right << y << endl;
    cout << "   " << setw(7) << right << "-----" << endl;

    // Give multiple choice and take selection
    answer(result);
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           subtract()
DESCRIPTION:        Prints subtraction problem and gets answer from user
RETURNS:            N/A
NOTES:
--------------------------------------------------------------------------------------------------*/
void subtract(int level) 
{
    // Variable declarations
    int x, y, result;

    // Generates numbers to be added
    rng(level, x, y);

    // Calculates the result, stores it as variable
    result = x - y;

    // Print calculation without result
    cout << "   " << setw(7) << right << x << endl;
    cout << "   " << "-" << setw(6) << right << y << endl;
    cout << "   " << setw(6) << right << "-----" << endl;

    // Give multiple choice and take selection
    answer(result);
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           multiply()
DESCRIPTION:        Prints multiplication problem and gets answer from user
RETURNS:            N/A
NOTES:
--------------------------------------------------------------------------------------------------*/
void multiply(int level) 
{
    // Variable declarations
    int x, y, result;

    // Generates numbers to be added
    rng(level, x, y);

    // Calculates the result, stores it as variable
    result = x * y;

    // Print calculation without result
    cout << "   " << setw(7) << right << x << endl;
    cout << "   " << "*" << setw(6) << right << y << endl;
    cout << "   " << setw(6) << right << "-----" << endl;

    // Give multiple choice and take selection
    answer(result);
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           division()
DESCRIPTION:        Prints division problem and gets answer from user
RETURNS:            N/A
NOTES:              Modified output format, and added extra steps to eliminate remainder
--------------------------------------------------------------------------------------------------*/
void divide(int level) 
{
    // Variable declarations
    int x, y, z, result;

    // Generates numbers to be added
    rng(level, x, y);

    // Does multiplication to eliminate remainder
    z = x * y;

    // Renames y for readability
    result = y; 

    // Print calculation without result
    cout << "  " << z << " / " << x << " = ";

    // Give multiple choice and take selection
    answer(result);
}