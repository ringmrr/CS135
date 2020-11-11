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
Michael Ring        2020-11-09      1.5 - 
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
void name();
int difficulty();
char menu();

void getAnswer(int &answer);
void checkAnswer(int &result, int &answer);

void rng(int level, int &x, int &y);

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
    void name();

    // Difficulty selection
    int level = difficulty();

    // Header
    cout << "Student name: " << name << endl;
    cout << "Program start: " << ctime(&start);
    cout << "Random seed: " << start << endl << endl; 

    // Opens file
    outfile.open(name);

    // Introduction
    cout << "          ARITHMETIC PRACTICE PROGRAM"                     << endl << endl;
    cout << "Welcome to the Math Skills Practice Program."              << endl << endl;
    cout << "This program allows you to practice your math skills."     << endl << endl;
    cout << "Choose what you want to practice in the menu shown below." << endl << endl << endl;

    bool goodbye = false;
    while (!goodbye)
    {
        char choice = menu();
        switch (choice)
        {
            case 'a':
                add(level);
                break;
            case 'b':
                subtract(level);
                break;
            case 'c':
                multiply(level);
                break;
            case 'd':
                divide(level);
                break;
            case 'q':
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
FUNCTION:           name()
DESCRIPTION:        
RETURNS:            N/A
NOTES:
--------------------------------------------------------------------------------------------------*/
void name()
{
    string name;
    cout << "What is your first and last name?  ";
    getline(cin, name);
    cout << endl;
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           difficulty()
DESCRIPTION:        
RETURNS:            level
NOTES:
--------------------------------------------------------------------------------------------------*/
int difficulty()
{
    // Difficulty menu & selection
    int level;
    cout << "Please select difficulty level:" << endl;
    cout << "1. 1 digit" << endl;
    cout << "2. 2 digits" << endl;
    cout << "3. 3 digits" << endl;
    cout << "4. 4 digits" << endl;
    cout << "5. 5 digits" << endl;
    cout << "Please enter 1-5 only: ";
    cin >> level;
    cout << endl;
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
    cout << endl;
    cout << "---------------------------------------------------------" << endl;

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
    cout << endl;
    return choice;
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
    int x, y, result, answer;

    // Generates numbers to be added
    rng(level, x, y);

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
void subtract(int level) 
{
    // Variable declarations
    int x, y, result, answer;

    // Generates numbers to be added
    rng(level, x, y);

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
void multiply(int level) 
{
    // Variable declarations
    int x, y, result, answer;

    // Generates numbers to be added
    rng(level, x, y);

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
void divide(int level) 
{
    // Variable declarations
    int x, y, z, result, answer;

    // Generates numbers to be added
    rng(level, x, y);

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
void rng(int level, int &x, int &y)
{
    int min = pow(10, level - 1);
    int max = pow(10, level);

    x = (rand() % (max - min + 1)) + min;
    y = (rand() % (max - min + 1)) + min;
}