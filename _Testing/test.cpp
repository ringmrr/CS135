// Required preprocessor directives
#include <iostream>    
#include <iomanip>
#include <cstdlib>
#include <string>

// Namespace
using namespace std;

int main()
{
    int x;

    x = -3 + 4 % 6 / 5;

    cout << "x = " << x << endl;

    system("pause");
    return 0;
}