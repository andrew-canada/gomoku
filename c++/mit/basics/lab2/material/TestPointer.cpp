#include <iostream>

using namespace std;

void squareByPtr(int *numPtr)
{
    *numPtr = *numPtr * *numPtr;
}

// int *myFunc()
// {
//     int phantom = 4;
//     return &phantom; // can't return, phantom doesn't exist outside of function
// }

void setString(char **strPtr)
{
    int x;
    cin >> x;
    if (x < 0)
        *strPtr = "Negative!";
    else
        *strPtr = "Nonnegative!";
}

int main()
{

    char *str;
    setString(&str);
    cout << str; // String has been set by setString
    return 0;

    // char *courseName2 = "6.096 ";
    // cout << courseName2 << endl;
    // cout << *courseName2 << endl;
    int x;
    int *numPtr = &x;
    *numPtr = 1;
    cout << numPtr << endl;
    cout << *numPtr << endl;
    numPtr++;
    *numPtr = 9;
    cout << *numPtr << endl;
    cout << *(--numPtr) << endl;
    int bb = 5;
    int &num = bb;
    cout << &num << endl;
    cout << num << endl;

    // long arr[] = {6, 0, 9, 7};
    // long *ptr = arr; // first element (arr[0]), 6
    // cout << *ptr << endl;
    // ptr++; // second element (arr[1]), 0
    // cout << *ptr << endl;
    // long *ptr2 = arr + 3;
    // cout << *ptr2 << endl;
    // cout << ptr2 << endl;
    // cout << ptr << endl;
    // cout << (ptr2 - ptr) << endl; // subtracts memory addresses to find number of elements in between ptr2 and ptr

    // int w = 6;
    // int y = 5;
    // // x is a reference type, same address as y
    // // int &x = &y; // error: &x is already reference, just write y, not &y
    // int &x = y; // Makes x a reference to, or alias of, y
    // cout << &x << endl;
    // cout << y << endl;
    // cout << &y << endl;
    // cout << x << endl;
    // // &x = w; // can't change referenced location, always reference y

    // // nullPointer is an int pointer, address is 0
    // int *nullPointer = 0; // null beause memory address 0 doesn't exist
    // // nullPointer = 5;      // error: cannot assign to null pointer
    // cout << nullPointer << endl;

    // cout << myFunc() << endl;

    // int a = 5;
    // squareByPtr(&a);
    // cout << a;
}