/*--------------------------------------------------------------------------------------------------
FILENAME:           Math_Tutor3.cpp
DESCRIPTION:        Subproject of Lab 6
COMPILER:           MinGW C++ compiler
NOTES:             

MODIFICATION HISTORY:
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-10-28      2.2 - Copied from Math_Tutor2.cpp
Michael Ring        2020-10-28      3.0 - Moved contents of main to void add() temporarily
Michael Ring        2020-10-28      3.1 - Created while loop and case in main() for function calls
Michael Ring        2020-10-28      3.2 - Added prototypes for new functions
Michael Ring        2020-10-29      3.3 - Separated into more functions for modularity
                                            > menu(), getAnswer(), checkAnswer(), rng(), add()
Michael Ring        2020-10-29      3.4 - Added more documentation
Michael Ring        2020-10-29      3.5 - Copied add() to subtract(), multiply(), and divide()
Michael Ring        2020-10-29      3.6 - Modified divide() to work appropriately
--------------------------------------------------------------------------------------------------*/

// PREPROCESSOR DIRECTIVES
#include <iostream>
#include <iomanip>
#include <string>
#include <cstdlib>
#include <ctime>

// NAMESPACE
using namespace std;

// FUNCTION PROTOTYPES
int menu();

void getAnswer(int &answer);
void checkAnswer(int &result, int &answer);

void rng(int &x, int &y);

void add();
void subtract();
void multiply();
void divide();

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
    bool goodbye = false;
    while (!goodbye)
    {
        int choice = menu();
        switch (choice)
        {
            case 1:
                add();
                break;
            case 2:
                subtract();
                break;
            case 3:
                multiply();
                break;
            case 4:
                divide();
                break;
            case 5:
                goodbye = true;
        }
    }

    // Goodbye!
    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl;
    system("pause");
    return 0;
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           menu()
DESCRIPTION:        Displays menu and receives user selection
RETURNS:            choice
NOTES:
--------------------------------------------------------------------------------------------------*/
int menu()
{
    cout << "        Math Tutor Menu"         << endl;
    cout << "-------------------------------" << endl;
    cout << "1. Addition problem"             << endl;
    cout << "2. Subtraction problem"          << endl;
    cout << "3. Multiplication problem"       << endl;
    cout << "4. Division problem"              << endl;
    cout << "5. Quit this program"            << endl;
    cout << "-------------------------------" << endl;
    cout << "Enter your choice (1-5): ";

    int choice;
    bool valid = false;
    while (!valid)
    {
        cin >> choice;
        cin.clear();
        cin.ignore(100, '\n');

        if (cin.good())
            if (choice <= 5 && choice >= 0)
                valid = true;
        else
            cout << "ERROR: Invalid input. Please try again.";
    }
    cout << endl;
    return choice;
}   

/*--------------------------------------------------------------------------------------------------
FUNCTION:           getAnswer()
DESCRIPTION:        Gets answer for math question
RETURNS:            N/A
NOTES:
--------------------------------------------------------------------------------------------------*/
void getAnswer(int &answer)
{
    // Pause for user input
    cout << " ";
    cin >> answer;
    cin.clear();
    cin.ignore(100, '\n');
    cout << endl;
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           checkAnswer()
DESCRIPTION:        Checks answer against result and prints appropriate message
RETURNS:            N/A
NOTES:
--------------------------------------------------------------------------------------------------*/
void checkAnswer(int &result, int &answer)
{
    // checkAnswers if user input is correct
    if (answer == result)
        cout << "Congratulations! That's right." << endl << endl;
    else
        cout << "Sorry! The correct answer is " << result << "." << endl << endl;
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           rng()
DESCRIPTION:        Seeds RNG from system time, and continues randomizing x and y until valid
RETURNS:            N/A
NOTES:
--------------------------------------------------------------------------------------------------*/
void rng(int &x, int &y)
{
    // Gets the system time to seed RNG
    unsigned seed = time(0);    
    srand(seed);  

    // Loop stays open until x and y are in the proper range
    // x range: 100-999     y range: 10-x
    bool valid = false;
    while (!valid)
    {
        // Assigns random values to x and y
        x = rand();             
        y = rand();             

        // checkAnswers that x is a 3 digit number, and that y is a 2 or 3 digit number less than x.
        if (x >= 100 && x <= 999 && y >= 10 && y < x)
            valid = true;
    }
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           add()
DESCRIPTION:        Prints addition problem and gets answer from user
RETURNS:            N/A
NOTES:
--------------------------------------------------------------------------------------------------*/
void add() 
{
    // Variable declarations
    int x, y, result, answer;

    // Generates numbers to be added
    rng(x, y);

    // Calculates the result, stores it as variable
    result = x + y;

    // Print calculation without result
    cout << setw(5) << right << x << endl;
    cout << "+" << setw(4) << right << y << endl;
    cout << "-----" << endl;

    // Pause for user input
    getAnswer(answer);

    // Checks if answer was correct and prints message/result
    checkAnswer(result, answer);
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           subtract()
DESCRIPTION:        Prints subtraction problem and gets answer from user
RETURNS:            N/A
NOTES:
--------------------------------------------------------------------------------------------------*/
void subtract() 
{
    // Variable declarations
    int x, y, result, answer;

    // Generates numbers to be added
    rng(x, y);

    // Calculates the result, stores it as variable
    result = x - y;

    // Print calculation without result
    cout << setw(5) << right << x << endl;
    cout << "-" << setw(4) << right << y << endl;
    cout << "-----" << endl;

    // Pause for user input
    getAnswer(answer);

    // Checks if answer was correct and prints message/result
    checkAnswer(result, answer);
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           multiply()
DESCRIPTION:        Prints multiplication problem and gets answer from user
RETURNS:            N/A
NOTES:
--------------------------------------------------------------------------------------------------*/
void multiply() 
{
    // Variable declarations
    int x, y, result, answer;

    // Generates numbers to be added
    rng(x, y);

    // Calculates the result, stores it as variable
    result = x * y;

    // Print calculation without result
    cout << setw(5) << right << x << endl;
    cout << "*" << setw(4) << right << y << endl;
    cout << "-----" << endl;

    // Pause for user input
    getAnswer(answer);

    // Checks if answer was correct and prints message/result
    checkAnswer(result, answer);
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           division()
DESCRIPTION:        Prints division problem and gets answer from user
RETURNS:            N/A
NOTES:              Modified output format, and added extra steps to eliminate remainder
--------------------------------------------------------------------------------------------------*/
void divide() 
{
    // Variable declarations
    int x, y, z, result, answer;

    // Generates numbers to be added
    rng(x, y);

    // Does multiplication to eliminate remainder
    z = x * y;

    // Renames y for readability
    result = y; 

    // Print calculation without result
    cout << "  " << z << " / " << x << " = ";

    // Pause for user input
    getAnswer(answer);

    // Checks if answer was correct and prints message/result
    checkAnswer(result, answer);
}