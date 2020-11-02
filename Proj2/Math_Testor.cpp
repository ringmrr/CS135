/*--------------------------------------------------------------------------------------------------
FILENAME:           Math_Testor.cpp
DESCRIPTION:        Subproject of Lab 6
COMPILER:           MinGW C++ compiler
NOTES:             

MODIFICATION HISTORY:
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-10-28      2.2 - Copied from Math_Tutor3.cpp

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
    cout << "          ARITHMETIC PRACTICE PROGRAM"                 << endl << endl;
    cout << "Welcome to the Math Skills Practice Program."          << endl << endl;
    cout << "This program allows you to practice your math skills." << endl << endl;
    cout << "Choose what to practice in the menu shown below."      << endl << endl << endl;

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
    cout << "-----------------------------------------------------" << endl;
    cout << "              ARITHMETIC PRACTICE PROGRAM"             << endl;
    cout << "                      MAIN MENU"                       << endl;  
    cout << "-----------------------------------------------------" << endl;
    cout << "a. Addition" << endl;
    cout << "b. Subtraction" << endl;
    cout << "c. Multiplication" << endl;
    cout << "d. Division" << endl;
    cout << "q. Quit the program" << endl;

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