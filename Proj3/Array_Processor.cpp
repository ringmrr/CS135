
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
--------------------------------------------------------------------------------------------------*/

#include <iostream>
#include <iomanip>
#include <string>
#include <fstream>

using namespace std;

string fileSelect();
void intoArray(ifstream& infile);
void sortData();
void displayData();
void histogram();
void save();

const string PROGRAMMER_NAME = "Michael Ring";

/*--------------------------------------------------------------------------------------------------
FUNCTION:           main()
DESCRIPTION:        Say what this function does
RETURNS:            0
NOTES:              Optional notes on this function
--------------------------------------------------------------------------------------------------*/
int main()
{
    // Attempts to open selected file
    string fileName = fileSelect();
    ifstream infile;
    infile.open(fileName);

    // Allows program to continue if file opens successfully
    if (infile)
    {
        intoArray(infile);
        sortData();
        displayData();
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

string fileSelect()
{
    string fileName;

    // Gets user selection
    cout << "Input file: ";
    getline (cin, fileName);
    return fileName;
}

void intoArray(ifstream& infile)
{
    int count, value;

    // Determine array size
    for (count = 0; infile >> value; count++) {}

    // Initialize array with a count that matches items in selected file
    int data[count];

    // Loads values into data[] until none are left
    while (infile >> data[count]) {}
}

void sortData()
{

}

void displayData()
{
    int min, max, mode, total;
    float avg, med, dev;
}

void histogram()
{

}

void save()
{

}