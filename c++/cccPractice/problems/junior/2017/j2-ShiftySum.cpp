#include <iostream>
#include <math.h>
using namespace std;

int recursiveShift(int number, int numberOfShifts)
{
    if (numberOfShifts == 0)
    {
        return number;
    }
    return number * pow(10, numberOfShifts) + recursiveShift(number, numberOfShifts - 1);
}

int main()
{
    int number = 0, numberOfShifts = 0;
    cin >> number;
    cin >> numberOfShifts;
    cout << recursiveShift(number, numberOfShifts);
}