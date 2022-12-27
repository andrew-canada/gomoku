#include <iostream>
#include <array>
using namespace std;

int main()
{
    bool testTrue = true;
    bool testFalse = false;
    bool testImplicitTrue = 3 < 5;
    cout << testTrue << endl;
    cout << testFalse << endl;
    cout << testImplicitTrue << endl;

    // int array1[3] * 3; can't copy values
    int array2[3] = {1, 2, 3};
    cout << sizeof(array2) << endl;
    cout << sizeof(array2) / sizeof(array2[0]) << endl;
}