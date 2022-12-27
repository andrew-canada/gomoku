#include <iostream>

using namespace std;

int main()
{
    // outputs 0 to 9
    // output first, then add
    for (int i = 0; i < 10;)
    {
        cout << i++ << "\n";
    }
    // outputs 1 to 10
    // add first, then output
    for (int i = 0; i < 10;)
    {
        cout << ++i << "\n";
    }
}