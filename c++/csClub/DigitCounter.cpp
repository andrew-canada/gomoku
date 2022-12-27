#include <iostream>
using namespace std;

int main()
{
    int number = 0;
    int digitCounter = 0;
    cout << "enter a number: ";
    cin >> number;
    number = abs(number);
    if (number == 0)
    {
        digitCounter = 1;
    }
    else
    {
        while (number >= 1)
        {
            digitCounter++;
            number /= 10;
        }
    }
    cout << "number of digits: " << digitCounter << endl;
}