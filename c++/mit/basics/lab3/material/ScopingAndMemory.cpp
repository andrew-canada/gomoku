#include <iostream>

using namespace std;

int main()
{
    int *p;
    if (true)
    {
        int x = 5;
        p = &x;
    }
    // dangling pointer
    cout << *p << endl; // *p = 5 because p memory address hasn't been reused yet
}