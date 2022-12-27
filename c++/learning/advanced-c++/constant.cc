#include <iostream>
using namespace std;

/*
    Why use const
        1. Guards against inadvertent write to the variable
        2. Self documenting 
        3. Enables compiler to do more optimization, making code tighter. Compiler will replace variable with its value 
        4. const means the variable can be put in ROM - Read Only Memory
*/

int main()
{
    //if const on left of *, data is const
    //if const on right of *, pointer is const

    int i = 6;
    const int *p1 = &i; // data is const, pointer is not
    //*p1 = 7;            //not allowed
    cout << "*p1 is the same as before. the value in pointer is " << *p1 << endl;
    p1++;
    cout << "*p1 is increased by1. the pointer is pointing the next address. the value in pointer is " << *p1 << endl;

    int *const p2 = &i; // pointer is constant, data is not
    //p2++;               //not allowed
    cout << "value inside pointer before change is " << *p2 << endl;
    *p2 = 2;
    cout << "value inside pointer after change is " << *p2 << endl;

    const int *const p3 = &i; // pointer is constant, data is constant
    //p3++;                     //not allowed
    //*p3 = 2; //not allowed
    cout << "value inside pointer is " << *p3 << endl;

    int const *p4 = &i; // data is constant, pointer is not
    const int *p5 = &i; // same as above but better (easier to read)
    cout << "pointer value before change is " << p4 << endl;
    p4++;
    //*p4 = 2; //not allowed
    cout << "pointer value after change is " << p4 << endl;

    //casting can turn an variable into a const
    //casting can cast away a constant into a modifiable variable
    //avoid casting constants
    const int j = 5;
    cout << "j = " << j << endl;
    const_cast<int &>(j) = 6; //casts away a constant and changes its value
    cout << "j = " << j << endl;
    //j = 8; //not allowed because j is const. j is only modifiable in line of casting
    int a = 5;
    cout << "a = " << a << endl;
    //static_cast<const int &>(a) = 5; //not allowed because a is const in this line
    static_cast<const int &>(a);
    cout << "a = " << a << endl;
    a = 6; //allowed because a is not const. a is only const in line of casting
    cout << "a = " << a << endl;
}