#include <iostream>

using namespace std;

// without enum - no input restriction
const int A = 0, B = 1, C = 2, D = 3;
void printClass(const int code)
{
    const char *classes[] = {"english", "french", "math", "geography"};
    cout << classes[code] << endl;
}

// with enum - can only pass one of the options; first item defaults to 0, others default to previous + 1
// enum can be used for any arguments, variables, return types, etc.
enum code
{
    W,
    X,
    Y,
    Z
};
void enumPrintClass(const code inputCode)
{
    const char *classes[] = {"english", "french", "math", "geography"};
    cout << classes[inputCode] << endl;
}

int main()
{
    printClass(A);
    enumPrintClass(Y);
    // can't call because 100 isnt W, X, Y, or Z
    // enumPrintClass(100);
}