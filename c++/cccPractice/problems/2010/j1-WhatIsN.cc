#include <iostream>
using namespace std;

int main()
{
    int input, counter = 0;
    int rh = 0, lh = 0;
    cin >> input;

    if (input > 5)
    {
        rh = 5;
        lh = input - 5;
    }
    else
    {
        rh = input;
    }
    while (rh >= lh)
    {
        rh--;
        lh++;
        counter++;
    }
    cout << counter;
}