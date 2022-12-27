#include <iostream>
#include <algorithm>

using namespace std;

void printArray(const int inputArr[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << inputArr[i] << " ";
    }
    cout << endl;
}

int main()
{
    int testArr[] = {0, 5, 2, 3, 4, 1};
    printArray(testArr, sizeof(testArr) / sizeof(testArr[0]));
    sort(testArr, testArr + sizeof(testArr) / sizeof(testArr[0]));
    printArray(testArr, sizeof(testArr) / sizeof(testArr[0]));
    reverse(testArr, testArr + sizeof(testArr) / sizeof(testArr[0]));
    printArray(testArr, sizeof(testArr) / sizeof(testArr[0]));
    rotate(testArr, testArr + 3, testArr + sizeof(testArr) / sizeof(testArr[0]));
    printArray(testArr, sizeof(testArr) / sizeof(testArr[0]));
}