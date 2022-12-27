#include <iostream>
using namespace std;

int main()
{
    int sz = 100000000;
    int *arr = new int[sz];
    for (int i = 0; i < sz; i++)
    {
        arr[i] = i + 1;
    }
    int *newArr = new int[sz + 1];
    for (int i = 0; i < sz; i++)
    {
        newArr[i] = arr[i];
    }
    delete[] arr;
    arr = newArr;
    arr[sz++] = 11;
    cout << arr << endl;

    int size = 10;
    int *betterArray = new int[size];
    for (int i = 0; i < size; i++)
    {
        betterArray[i] = i + 1;
    }
    int *newArray = new int[size * 2];
    for (int i = 0; i < size; i++)
    {
        newArray[i] = betterArray[i];
    }
    delete[] betterArray;
    betterArray = newArray;
    for (int i = 10; i < size * 2; i++)
    {
        betterArray[i] = i + 1;
    }
    cout << "a";
}