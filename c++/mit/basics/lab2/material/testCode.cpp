// testCode.cpp - implementation
#include "testCode.h"
#include <iostream>
// defines rand(), srand(), RAND_MAX
#include <cstdlib>
// C time functions -defines time(
#include <ctime>

using namespace std;

string foo()
{
    return "hello";
}

void printNumber(int num)
{
    cout << "number is " << num << endl;
}

void aFunction(int arr[][4])
{
    cout << arr << endl;

    // cout << "size" << sizeof(arr) << endl;
    cout << "xx " << **arr << endl;
    cout << "xx " << &arr << endl;
    cout << "xx " << *(&arr) << endl;
    cout << "size" << sizeof(*arr) << endl;
    cout << "size" << sizeof(&arr) << endl;
    cout << "size" << sizeof(*(&arr)) << endl;

    for (int i = 0; i < 3; i++)
    {
        for (int j = 0; j < 4; j++)
        {
            cout << arr[i][j] << '\n';
        }
    }
}

void printNTimes(char const *msg, int n = 1)
{
    for (int i = 0; i < n; ++i)
    {
        cout << msg;
    }
}

int main()
{
    // time(0) returns current time as a number
    srand(time(0)); // Set the seed;
    int randNum = rand();
    std::cout << "A random number: " << randNum << endl;

    printNTimes("hello");

    int arr1[3][4] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12};

    aFunction(arr1);

    cout << square(5) << '\n';

    cout << foo() << '\n';

    printNumber(3);

    return 0;
}