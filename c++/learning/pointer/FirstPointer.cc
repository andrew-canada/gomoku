#include <iostream>
using namespace std;

void testValue(int n)
{
    int number = 0;
    number = n;
    cout << "number = " << number << endl;
}
void test(const char *pointer)
{
    cout << "The value of the pointer is: " << *pointer << endl;
    cout << "hello" << endl;
}
void printValueFromPointer(void *pointer, char type)
{
    switch (type)
    {
    case 'i':
        cout << *((int *)pointer) << endl;
        break;
    case 'c':
        cout << *((char *)pointer) << endl;
        break;
    case 'f':
        cout << *((float *)pointer) << endl;
        break;
    case 'd':
        cout << *((double *)pointer) << endl;
        break;
    default:
        cout << "Invalid type" << endl;
        break;
    }
}
void learnPointer()
{
    int n = 5;
    int *p = &n;
    cout << "n = " << n << endl;
    cout << "address of n = " << &n << endl;
    cout << "p = " << p << endl;
    cout << "value in address p = " << *p << endl;
    cout << "value in address n = " << *(&n) << endl;
    char letter = 'a';
    printValueFromPointer(&letter, 'c');
    test(&letter);
    test(&letter);
    testValue(n);
}
int main()
{
    learnPointer();

    int a = 0;
    cout << a << endl;
    int *p;
    p = &a;
    *p = 5;
    cout << a << endl;

    int array[5] = {1, 2, 3, 4, 5};
    p = array;
    //array = p;
    return 0;
}