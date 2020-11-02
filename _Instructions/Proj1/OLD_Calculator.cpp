/* -----------------------------------------------------------------------------
FILENAME:          Calculator.cpp
DESCRIPTION:       Calculator suitable for a 7th grade student
COMPILER:          MinGW  C++ compiler
NOTES:             Expanding Lab 4 into Project 1

MODIFICATION HISTORY:
Author             Date               Version
---------------    ----------         --------------
Michael Ring       2020-02-19         1.0  Copied Lab 4
Michael Ring       2020-03-04         1.1  Added function prototypes, renamed others
Michael Ring       2020-03-04         1.2  Cleaned up for readability
Michael Ring       2020-03-04         1.3  Created -, *, and / functions
Michael Ring       2020-03-05	        1.4  Created Powers & Roots menu functions
Michael Ring       2020-03-11         1.5  Created 'xinput' function from 'xyinput'
Michael Ring       2020-03-11         1.5  Added welcome message
Michael Ring       2020-03-11         1.6  Beginning to add int / float selections
Michael Ring       2020-03-12	        1.7  Created 'prMain' function for modularity / organization
Michael Ring       2020-03-12         1.8  Deleted 'xinput' function
Michael Ring       2020-03-12         1.9  Created square, cube, any power, sqrt, cbrt, and any root functions
 ----------------------------------------------------------------------------- */

// REQUIRED PREPROCESSOR DIRECTIVES
#include <iostream>		 
#include <iomanip>		
#include <string>		
#include <cmath>       

// USE STANDARD NAMESPACE
using namespace std;

// FUNCTION PROTOTYPES
char mainMenu();
char prMenu();

void add();
void subtract();
void multiply();
void divide();

void prSquare();
void prCube();
void prPower();

void prSqrt();
void prCbrt();
void prRoot();

// VARIABLE DEFINITIONS
float x, y, result;		// Used in calculations
bool integer = true;      // Used for int/float selection
bool goodbye = false;		// Used to indicate whether user has requested to quit

// GLOBAL CONSTANTS
const string PROGRAMMER_NAME = "Michael Ring";	

// MAIN
// MENU
// FUNCTIONS

/* -----------------------------------------------------------------------------
FUNCTION:          main()
DESCRIPTION:       Calls other functions, quits program when requested
RETURNS:           0
NOTES:             
------------------------------------------------------------------------------- */
int main()
{
	system("cls");	// Clears the screen if user enters from cmd
	char mainChoice; // Defines 'choice' as a character variable in this scope
	
	cout << "------------------------------------------------" << endl;
	cout << "                      HELLO                     " << endl;
	cout << "   USE THIS PROGRAM TO PRACTICE MATH SKILLS!    " << endl;
	cout << "        USE KEYBOARD TO MAKE SELECTIONS         " << endl;
	cout << "------------------------------------------------" << endl;
	cout << endl;
	system("pause");
	
	// CONSTANTLY TESTS VARIABLE mainChoice FOR MENU SELECTIONS, REDIRECTS ACCORDINGLY
	while(!goodbye)				// While loop closes when q is entered
	{
		mainChoice = mainMenu();	// Calls function menuChoice for menu, dialogue, and input
	
		switch (mainChoice)		// Creates switch that tests variable 'choice'
		{
			case 'a': 			// If choice == a,
				add();		// call the addition function.
				break;		// Stop executing statements
				
			case 'b':			// If choice == b,
				subtract(); 	// call the subtraction function.
				break; 		// Stop executing statements
				
			case 'c':			// If choice == c,
				multiply();		//call the multiplication function.
				break;		// Stop executing statements
				
			case 'd':			// If choice == d,
				divide();		// call the division function.
				break;		// Stop executing statements
					
			case 'e':			// If choice == e,
				prMenu();  	// call the P/R menu function.
				break;		// Stop executing statements
				
			case 'q':			// If choice == q,
				goodbye = true;	// close while loop
				break;		// Stop executing statements
		}	
	}	
	// EXIT + TIMESTAMP
	cout << "Goodbye! :)" << endl << endl;					
			
	cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";	
	cout << __DATE__ << "  " __TIME__ << endl;				
	cout << endl;
				
	system("pause");										// Stop window from closing
	return 0;												// Returns 0 to int main()
}

/* -----------------------------------------------------------------------------
FUNCTION:          mainMenu()
DESCRIPTION:       Requests, identifies, and stores user input
RETURNS:           mainChoice
NOTES:             
------------------------------------------------------------------------------- */
char mainMenu()
{
	char mainChoice;			
	
	// PRINTS MAIN MENU
	cout << endl;						
	cout << "-------------------------------------------------" << endl;
	cout << "                    MAIN MENU                    " << endl;
	cout << "-------------------------------------------------" << endl;
	cout << endl << endl;						
	cout << "a) Addition                                 (X+Y)" << endl;
	cout << "b) Subtraction                              (X-Y)" << endl;
	cout << "c) Multiplication                           (X*Y)" << endl;
	cout << "d) Division                                 (X/Y)" << endl;
	cout << "e) Powers & Roots                           (X^Y)" << endl << endl;
	cout << "q) Quit" << endl << endl;
	cout << endl << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "           Enter your choice: [a-e, q]           " << endl;
	cout << "-------------------------------------------------" << endl << endl;
	
	// GETS CHOICE, CONVERTS TO LOWERCASE
	cin >> mainChoice;
	cout << endl;
	mainChoice = tolower(mainChoice);
			
	// INPUT VALIDATION		
	if (mainChoice >= 'a' && mainChoice <= 'e')	
		cout << "You entered: '" << mainChoice << "', that is correct input." << endl << endl;
	else if (mainChoice == 'q')						
		cout << "You entered: '" << mainChoice << "', that is correct input." << endl << endl;
	else
	{
		cout << "You did not enter a valid option." << endl;	
		cout << "Please rerun the program." << endl;			
	}
	
	return mainChoice;												
}

// 
//
//

/* -----------------------------------------------------------------------------
FUNCTION:          prMain()
DESCRIPTION:       Equivalent to main() but handles prMenu
RETURNS:           void
NOTES:             
------------------------------------------------------------------------------- */
void prMain()
{	
	char prChoice = prMenu();
	
	// FUNCTION REDIRECTION	


// WARNING -----------
// I seem to have broken this last minute before submitting. The switch doesn't actually	
	switch (prChoice)		// Tests variable 'choice' and redirects to matching function
	{
		case 'a': 		// If prChoice == a,
		prSquare();		// call the square function.
		break;		// Stop executing statements
		
		case 'b':		// If prChoice == b,
		prCube();		// call the cube function.
		break;		// Stop executing statements
				
		case 'c':		// If prChoice == c,
		prPower();		// call the any power function.
		break;		// Stop executing statements
				
		case 'd':		// If prChoice == d,
		prSqrt();		// call the square root function.
		break;		// Stop executing statements
				
		case 'e':		// If prChoice == e,
		prCbrt();		// call the cube root function.
		break;		// Stop executing statements
			
		case 'f':		// If prChoice == f,
		prRoot();		// call the any root function.
		break;		// Stop executing statements
			
		case 'm':		// If prChoice == m,
		mainMenu();		// call the main menu function.
		break;		// Stop executing statements	
				
		case 'q':		//If prChoice == q,
		goodbye = true;	//closes while loop
		break;		//Stop executing statements				
	}	
}

/* -----------------------------------------------------------------------------
FUNCTION:          prMenu()
DESCRIPTION:       Prints Powers & Roots submenu
RETURNS:           void
NOTES:            
------------------------------------------------------------------------------- */
char prMenu()
{
	char prChoice;
	
	// PRINTS POWERS & ROOTS MENU
	cout << endl << endl;						
	cout << "-------------------------------------------------" << endl;
	cout << "               POWERS & ROOTS MENU               " << endl;
	cout << "-------------------------------------------------" << endl;
	cout << endl << endl;						
	cout << "a) Square a number         (X^2)" << endl;
	cout << "b) Cube a number           (X^3)" << endl;
	cout << "c) Raise to any power      (X^Y)" << endl;
	cout << "d) Square root a number    (X^1/2)" << endl;
	cout << "e) Cube root a number      (X^1/3)" << endl;
	cout << "f) Take any root           (X^1/Y)" << endl << endl;
	cout << "m) Return to Main Menu" << endl << endl;
	cout << "q) Quit" << endl << endl;
	cout << endl << endl;
	cout << "-------------------------------------------------" << endl;
	cout << "         Enter your choice: [a-f, m, q]          " << endl;
	cout << "-------------------------------------------------" << endl << endl;
	
	// GETS CHOICE
	cin >> prChoice;
	cout << endl;
	
	// GETS CHOICE, CONVERTS TO LOWERCASE
	cin >> prChoice;
	cout << endl;
	prChoice = tolower(prChoice);
	
	// INPUT VALIDATION		
	if (prChoice >= 'a' && prChoice <= 'f')	
		cout << "You entered: '" << prChoice << "', that is correct input." << endl << endl;
	else if (prChoice == 'm')						
		cout << "You entered: '" << prChoice << "', that is correct input." << endl << endl;
	else if (prChoice == 'q')						
		cout << "You entered: '" << prChoice << "', that is correct input." << endl << endl;
	else
	{
		cout << "You did not enter a valid option." << endl;	
		cout << "Please rerun the program." << endl;			
	}
	
	return (prChoice);
}	

/* -----------------------------------------------------------------------------
FUNCTION:          xyInput()
DESCRIPTION:       Requests and stores input for math operations
RETURNS:           void
NOTES:             
------------------------------------------------------------------------------- */
void xyInput()
{		
	// GETS INPUT
	cout << "Select values for x and y: ";
	cin >> x;						
	cin >> y;
}

// BASIC
// CALCULATIONS
// +  -  *  /

/* -----------------------------------------------------------------------------
FUNCTION:          add()
DESCRIPTION:       Adds two numbers
RETURNS:           void
NOTES:            
------------------------------------------------------------------------------- */
void add()
{
	xyInput();				// Requests user input
	result = x + y;			// Performs calculation
	cout << endl;			// Prints result 
	cout << "	x + y = " << x << " + " << y << " = " << result;
	cout << endl << endl;
	system("pause");
}

/* -----------------------------------------------------------------------------
FUNCTION:          subtract()
DESCRIPTION:       Subtracts two numbers
RETURNS:           void
NOTES:             
------------------------------------------------------------------------------- */
void subtract()
{
	xyInput();			// Requests user input
	result = x - y;		// Performs calculation
	cout << endl;		// Prints result
	cout << "	x - y = " << x << " - " << y << " = " << result;
	cout << endl << endl;
	system("pause");
}

/* -----------------------------------------------------------------------------
FUNCTION:          multiply()
DESCRIPTION:       Multiplies two numbers
RETURNS:           void
NOTES:             
------------------------------------------------------------------------------- */
void multiply()
{
	xyInput();				// Requests user input
	result = x * y;			// Performs calculation
	cout << endl;		// Prints result
	cout << "	x * y = " << x << " * " << y << " = " << result;
	cout << endl << endl;
	system("pause");
}

/* -----------------------------------------------------------------------------
FUNCTION:          divide()
DESCRIPTION:       Divides the first number by the second
RETURNS:           void
NOTES:             
------------------------------------------------------------------------------- */
void divide()
{
	xyInput();						// Requests user input
	
	// IF-ELSE FOR INPUT VERIFICATION
	if (y != 0)					// Catches 'divide by zero' error
	{
		result = x / y;				// Performs calculation
		cout << endl << endl;			// Prints result
		cout << "	x / y = " << x << " / " << y << " = " << result << endl;	
		cout << endl;
		system("pause");
	}
	
	else 
		cout << endl << "Cannot divide by zero. Please try again." << endl;
		cout << endl;
		system("pause");
}		
	
// POWERS
// AND
// ROOTS
	
/* -----------------------------------------------------------------------------
FUNCTION:          prSquare()
DESCRIPTION:       
RETURNS:           void
NOTES:             
------------------------------------------------------------------------------- */
void prSquare()
{
	// GETS INPUT
	cout << "Select a value for x: ";
	cin >> x;	
	
	result = pow (x, 2);		// Performs calculation
	cout << endl << endl;		// Prints result 
	cout << "	x ^ 2 = " << x << " ^2 " << " = " << result << endl;
	cout << endl;
	system("pause");	
}

/* -----------------------------------------------------------------------------
FUNCTION:          prCube()
DESCRIPTION:       
RETURNS:           void
NOTES:             
------------------------------------------------------------------------------- */
void prCube()
{
	// GETS INPUT
	cout << "Select a value for x: ";
	cin >> x;	
	
	result = pow (x, 3);		// Performs calculation
	cout << endl << endl;		// Prints result 
	cout << "	x^3 = " << x << " ^3 " << " = " << result << endl;
}


/* -----------------------------------------------------------------------------
FUNCTION:          prPower()
DESCRIPTION:       
RETURNS:           void
NOTES:             
------------------------------------------------------------------------------- */
void prPower()
{
	xyInput();				// Requests user input
	result = pow (x, y);		// Performs calculation
	cout << endl << endl;		// Prints result 
	cout << "	x^3 = " << x << " ^3 " << " = " << result << endl;
}

/* -----------------------------------------------------------------------------
FUNCTION:          prSqrt()
DESCRIPTION:       
RETURNS:           void
NOTES:             
------------------------------------------------------------------------------- */
void prSqrt()
{
	// GETS INPUT
	cout << "Select a value for x: ";
	cin >> x;	
	
	result = sqrt (x);		// Performs calculation
	cout << endl << endl;		// Prints result 
	cout << "	x ^ 1/2 = " << x << " ^1/2 " << " = " << result << endl;
}

/* -----------------------------------------------------------------------------
FUNCTION:          prCbrt()
DESCRIPTION:       
RETURNS:           void
NOTES:             
------------------------------------------------------------------------------- */
void prCbrt()
{
	// GETS INPUT
	cout << "Select a value for x: ";
	cin >> x;	
	
	result = pow (x, 1.0/3);	// Performs calculation
	cout << endl << endl;		// Prints result 
	cout << "	x ^ 1/2 = " << x << " ^1/2 " << " = " << result << endl;
}

/* -----------------------------------------------------------------------------
FUNCTION:          prRoot()
DESCRIPTION:       
RETURNS:           void
NOTES:             
------------------------------------------------------------------------------- */
void prRoot()
{	
	xyInput();				// Requests user input
	result = pow (x, 1.0/y);	// Performs calculation
	cout << endl << endl;		// Prints result 
	cout << "	x^3 = " << x << " ^3 " << " = " << result << endl;
}