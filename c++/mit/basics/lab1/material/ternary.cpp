#include <iostream>

using namespace std;

int main()
{
    int a = 3, b = 4;

    // equivalent to if(a > b) ... else ...
    (a > b) ? cout << "a is bigger" << endl : cout << "b is bigger" << endl;
}