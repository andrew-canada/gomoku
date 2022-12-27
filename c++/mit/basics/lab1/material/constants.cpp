#include <iostream >

using namespace std;

//#define doesn't use memory
// use #define for global scope
#define PI 3.14159
#define NEWLINE '\n'

int main()
{
    // use const... for local scope
    const double r = 5.0;

    // is an lvalue expression because can be assigned with some value
    double circle;

    circle = 2 * PI * r;       // circle = 2 * 3.14159 * r;
    cout << circle << NEWLINE; // cout << circle << ’\n ’;

    return 0;
}