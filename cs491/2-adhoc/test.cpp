// C++ program to demonstrate syntax of switch
#include <iostream>
using namespace std;

// Driver Code
int main()
{
    char x = 'A';
    switch (x)
    {
    case 'A':
        cout << "Choice is A";

    case 'B':
        cout << "Choice is B";

    case 'C':
        cout << "Choice is C";

    default:
        cout << "Choice other than A, B and C";
    }
    return 0;
}

// Code submitted by Susobhan AKhuli
