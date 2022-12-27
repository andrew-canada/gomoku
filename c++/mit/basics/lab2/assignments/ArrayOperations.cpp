#include <iostream>

using namespace std;

// const int length;
// const int width;

void printArray(const int inputArr[], const int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << inputArr[i];
        if (i < (size - 1))
        {
            cout << ", ";
        }
    }
    cout << '\n';
}

void reverseArray(int inputArr[], const int size)
{
    int tempSwapVar;
    int endVal;
    for (int i = 0; i < (size / 2); i++)
    {
        endVal = inputArr[size - i - 1];
        tempSwapVar = inputArr[i];
        inputArr[i] = endVal;
        inputArr[size - i - 1] = tempSwapVar;
    }
}

// 6.3
// void transpose(int input[][length], int output[][width])
// {
//     for (int x = 0; x < length; x++)
//     {
//         for (int y = 0; y < width; y++)
//         {
//             output[x][y] = input[y][x];
//         }
//     }
// }

void pointerOffsetReverseArray(int inputArr[], const int size)
{
    int tempSwapVar;
    int endVal;
    for (int i = 0; i < (size / 2); i++)
    {
        endVal = *(inputArr + size - i - 1);
        tempSwapVar = *(inputArr + i);
        *(inputArr + i) = endVal;
        *(inputArr + size - i - 1) = tempSwapVar;
    }
}

void printArray1(int inArr[], int size);
void reverseArray1(int inArr[], int size);

int main()
{
    int arr1[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 13};
    int arr2[] = {13, 12, 11, 10, 9, 8, 7, 6, 5, 4, 3, 2, 1};

    int size = sizeof(arr1) / sizeof(arr1[0]);
    printArray(arr1, size);
    cout << "2nd version" << endl;
    printArray1(arr1, size);

    reverseArray(arr1, size);
    printArray(arr1, size);
    cout << "2nd version" << endl;
    reverseArray1(arr1, size);
    printArray1(arr1, size);

    pointerOffsetReverseArray(arr1, size);
    printArray(arr1, size);

    // cin >> length;
    // cin >> width;
}

void printArray1(int inArr[], int size)
{
    for (int i = 0; i < size; i++)
    {
        cout << inArr[i];
        if (i < size - 1)
        {
            cout << ", ";
        }
    }
    cout << endl;
}

void reverseArray1(int inArr[], int size)
{
    int tempVar = 0;
    for (int i = 0; i < size / 2; i++)
    {
        tempVar = inArr[i];
        inArr[i] = inArr[size - i - 1];
        inArr[size - i - 1] = tempVar;
    }
}