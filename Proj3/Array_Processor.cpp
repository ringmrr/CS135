
/*--------------------------------------------------------------------------------------------------
FILENAME:           Array_Processor.cpp
DESCRIPTION:        Project 3
COMPILER:           MinGW C++ compiler
NOTES:              

MODIFICATION HISTORY:
Author              Date            Version
---------------     ----------      ---------------
Michael Ring        2020-11-18      0.1 - Prepped folders/files
Michael Ring        2020-11-23      0.2 - Prepped modular functions
Michael Ring        2020-11-30      0.3 - Added file opening and success check
Michael Ring        2020-12-01      0.4 - Created simple fileSelect() function
Michael Ring        2020-12-01      0.5 - Added loops to intoArray()
Michael Ring        2020-12-02      0.6 - Simplified intoArray(), and now returns count
Michael Ring        2020-12-02      0.7 - Moved variable declarations to main to be more 'global'
Michael Ring        2020-12-03      0.8 - Added bubble sort for array in function sortData()
Michael Ring        2020-12-03      0.9 - Added function prototypes for sum(), avg(), etc.
Michael Ring        2020-12-03      1.0 - displayData() successfully prints points, min, and max
Michael Ring        2020-12-03      1.1 - 
--------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

// Namespace
using namespace std;

// Function prototypes
string fileSelect();
int intoArray(ifstream& infile, int data[]);

void sortData(int data[], int count);
void swap(int &a, int &b);

void displayData(int data[], int count);
int sum(int data[], int count);
float avg();
float dev();
float med();
int mode();

void histogram();

void save();

// Global constants
const int ARRAY_SIZE = 1000;
const string PROGRAMMER_NAME = "Michael Ring";

/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        Say what this function does
RETURNS:            0
NOTES:              Optional notes on this function
--------------------------------------------------------------------------------------------------*/
int main()
{
    // Variable Declarations
    int data[ARRAY_SIZE];
    int count;

    // Attempts to open selected file
    string fileName = fileSelect();
    ifstream infile;
    infile.open(fileName);

    // Allows program to continue if file opens successfully
    if (infile)
    {
        count = intoArray(infile, data);
        sortData(data, count);
        displayData(data, count);
        histogram();
        save(); 
    }

    // Throws error if file cannot open successfully
    else
    cout << "Could not open file. Please re-run the program." << endl;

    // Goodbye!
    cout << endl;
    cout << "Programmed by: " << PROGRAMMER_NAME << " -- ";
    cout << __DATE__ << " " __TIME__ << endl;
    system("pause");
    return 0;
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           fileSelect()
DESCRIPTION:        Prompts user to input file, then returns selection as string
RETURNS:            sting fileName
NOTES:              
--------------------------------------------------------------------------------------------------*/
string fileSelect()
{
    string fileName;

    // Gets user selection
    cout << "Input file: ";
    getline (cin, fileName);
    return fileName;
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           intoArray()
DESCRIPTION:        Loads values from selected file into array data[]
RETURNS:            0
NOTES:              
--------------------------------------------------------------------------------------------------*/
int intoArray(ifstream& infile, int data[])
{
    // Counts total amount of values in file for later calculations
    int count = 0;

    // Loads values into data[] until none are left
    while (count < ARRAY_SIZE && infile >> data[count]) 
    {
        count++;
    }

    // Returns count for
    return count;
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           sortData()
DESCRIPTION:        Bubble sort
RETURNS:            0
NOTES:              SOLUTION TAKEN FROM: Figure 8-7 (p.478) from Starting out with C++
--------------------------------------------------------------------------------------------------*/
void sortData(int data[], int count)
{
    int position;

    for (int remaining = count - 1; remaining > 0; remaining--)
    {
        for (position = 0; position < remaining; position++)
        {
            if (data[position] > data[position + 1])
            {
                swap(data[position], data[position + 1]);
            }
        }
    }
}

void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           displayData()
DESCRIPTION:       
RETURNS:            0
NOTES:              
--------------------------------------------------------------------------------------------------*/
void displayData(int data[], int count)
{
    //int sum = sum();
    //float avg = avg();
    //float dev = dev();
    //float med = med();
    //int mode = mode();

    cout << endl;
    cout << "No. points: " << count << endl;
    cout << "The Min is: " << data[0] << endl;
    cout << "The Max is: " << data[count - 1] << endl;
    cout << "Sum  Total: " << sum(data, count) << endl;
    cout << "The Avg is: " << endl;
    cout << "Std Dev is: " << endl;
    cout << "Median  is: " << endl;
    cout << "Modes  are: " << endl;

    for (int position = 0; position < count; position++)
        cout << data[position] << endl;
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           sum()
DESCRIPTION:       
RETURNS:            0
NOTES:              
--------------------------------------------------------------------------------------------------*/
int sum(int data[], int count)
{
    int total;

    for (total = 0; remaining > 0; remaining--)
        total =+ data[count - 1];

    return total;
}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           avg()
DESCRIPTION:       
RETURNS:            0
NOTES:              
--------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------
FUNCTION:           dev()
DESCRIPTION:       
RETURNS:            0
NOTES:              
--------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------
FUNCTION:           med()
DESCRIPTION:       
RETURNS:            0
NOTES:              
--------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------
FUNCTION:           mode()
DESCRIPTION:       
RETURNS:            0
NOTES:              
--------------------------------------------------------------------------------------------------*/

/*--------------------------------------------------------------------------------------------------
FUNCTION:           histogram()
DESCRIPTION:        
RETURNS:            0
NOTES:              
--------------------------------------------------------------------------------------------------*/
void histogram()
{

}

/*--------------------------------------------------------------------------------------------------
FUNCTION:           save()
DESCRIPTION:        
RETURNS:            0
NOTES:              
--------------------------------------------------------------------------------------------------*/
void save()
{

}