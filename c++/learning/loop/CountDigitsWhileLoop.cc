#include <iostream>
using namespace std;

void countDigits()
{
    int digits = 0;
    int number;
    cout << "Please enter a number: ";
    cin >> number;
    if (number == 0)
    {
        cout << "Invalid input";
    }
    else
    {
        while (abs(number) >= 1)
        {
            number /= 10;
            digits++;
        }
        cout << digits << " digit(s)";
    }
}

int main()
{
    countDigits();
    return 0;
}