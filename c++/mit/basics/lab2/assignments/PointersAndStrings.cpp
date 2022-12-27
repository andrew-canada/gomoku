#include <iostream>

using namespace std;

int length(const char *inputString)
{
    int size = 0;
    for (int i = 0; i >= 0; i++)
    {
        if (*(inputString + i) != '\0')
        {
            size += 1;
        }
        else
        {
            break;
        }
    }
    return size;
}

int lengthBetter(const char *inputString)
{
    int size = 0;
    while (*(inputString + size) != '\0')
    {
        size += 1;
    }
    return size;
}

void swapIntReference(int &int1, int &int2)
{
    int temp = int1;
    int1 = int2;
    int2 = temp;
}

void swapIntPointerValue(int *int1, int *int2)
{
    int temp = *int1;
    *int1 = *int2;
    *int2 = temp;
}

void swapIntPointerAddress(int **int1, int **int2)
{
    int *temp = *int1;
    *int1 = *int2;
    *int2 = temp;
}

int length1(char *inputString)
{
    for (int i = 0;; i++)
    {
        if (inputString[i] == '\0')
        {
            return i;
        }
    }
}

void swapIntReference1(int &int1, int &int2)
{
    int temp = int1;
    int1 = int2;
    int2 = temp;
}

void swapIntPointerValue1(int *int1, int *int2)
{
    int temp = *int1;
    *int1 = *int2;
    *int2 = temp;
}

void swapIntPointerAddress1(int **int1, int **int2)
{
    int *temp = *int1;
    *int1 = *int2;
    *int2 = temp;
}

int main()
{
    char *inputString = " he llo123*& ";
    cout << length(inputString) << endl;
    cout << lengthBetter(inputString) << endl;
    cout << "new function" << endl;
    cout << length1(inputString) << endl;

    int int1 = 1;
    int int2 = 2;
    swapIntReference(int1, int2);
    cout << "int1: " << int1 << endl;
    cout << "int2: " << int2 << endl;
    cout << "new function" << endl;
    swapIntReference1(int1, int2);
    cout << "int1: " << int1 << endl;
    cout << "int2: " << int2 << endl;

    swapIntPointerValue(&int1, &int2);
    cout << "int1: " << int1 << endl;
    cout << "int2: " << int2 << endl;
    cout << "new function" << endl;
    swapIntPointerValue1(&int1, &int2);
    cout << "int1: " << int1 << endl;
    cout << "int2: " << int2 << endl;

    int *x = &int1;
    int *y = &int2;

    swapIntPointerAddress(&x, &y);
    cout << "int1: " << *x << endl;
    cout << "int2: " << *y << endl;
    cout << "new function" << endl;
    swapIntPointerAddress1(&x, &y);
    cout << "int1: " << *x << endl;
    cout << "int2: " << *y << endl;

    // 7.5
    char *oddOrEven = "Never odd or even";

    // 1
    char *nthCharPtr = (&oddOrEven[5]);
    cout << oddOrEven[5] << endl;
    cout << *nthCharPtr << endl;

    // 2 & 3
    nthCharPtr = (oddOrEven + 3);
    cout << *nthCharPtr << endl;

    // 4 & 5 & 6
    char **pointerPtr = &nthCharPtr;
    cout << pointerPtr << endl;
    cout << **pointerPtr << endl;

    // 7
    nthCharPtr += 1;
    cout << *nthCharPtr << endl;

    // 8
    cout << nthCharPtr - oddOrEven << endl;
}