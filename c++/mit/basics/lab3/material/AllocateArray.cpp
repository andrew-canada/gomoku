#include <iostream>

using namespace std;

int main()
{
    int arrSize = 0;
    cout << "enter array size: ";
    cin >> arrSize;

    int *dynamicArray = new int[arrSize];
    for (int i = 0; i < arrSize; i++)
    {
        cin >> dynamicArray[i];
    }

    for (int i = 0; i < arrSize; i++)
    {
        cout << dynamicArray[i] << '\n';
    }

    delete[] dynamicArray;
}