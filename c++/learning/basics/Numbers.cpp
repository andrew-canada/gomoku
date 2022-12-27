#include <iostream>
using namespace std;

int main()
{
    // first bit in a signed number stores if positive (0) or negative (1)
    int signedInt1 = 1111111111;
    cout << "signed: " << signedInt1 << endl;

    // overflows because too many digits, but unsigned won't
    int signedInt2 = 4111111111;
    cout << "signed: " << signedInt2 << endl;

    // unsigned number can store twice as many values as signed numbers because always positive
    unsigned int unsignedInt = 1111111111;
    cout << "unsigned: " << 4111111111 << endl;

    float number1 = (float)7 / 3;
    cout << "float: " << number1 << endl;
    // double is short for "double precision float"
    double number2 = (double)7 / 3;
    cout << "double: " << number2 << endl;
    // use apostrophe to increase readability. "chunking separators".
    float number3 = 3'222'222'222'222'222'222;
    cout << number3 << endl;

    // sizeof() returns memory size
    cout << "size of int: " << sizeof(int) << endl;
    int int1 = 66;
    cout << sizeof(int1) << endl;
    cout << "max size of int: " << INT_MAX << endl;
    cout << "max size of unsigned int: " << UINT_MAX << endl;

    // fixed width
    cout << "size of 8-bit int: " << sizeof(int8_t) << endl;
    cout << "size of 64-bit int: " << sizeof(int64_t) << endl;
}