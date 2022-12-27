#include <iostream>

using namespace std;
// 4.1
// int sum(const int num1, const int num2)
// {
//     return (num1 + num2);
// }

// double sum(const double num1, const double num2)
// {
//     return (num1 + num2);
// }

// double sum(const int num1, const double num2)
// {
//     return (num1 + num2);
// }

template <typename T, typename U>
T sum(const T num1, const U num2)
{
    return (num1 + num2);
}

// 4.3, 4.4
int sumMultiple(const int num1, const int num2, const int num3 = 0, const int num4 = 0)
{
    return (num1 + num2 + num3 + num4);
}

// 4.5
int sumInfinate(const int inputNums[], const int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += inputNums[i];
    }
    return sum;
}

// 4.6
int recursiveSum(const int inputNums[], const int size)
{
    if (size == 0)
    {
        return 0;
    }
    return inputNums[0] + recursiveSum((inputNums + 1), (size - 1));
}

int sumInfinate1(int inputNums[], int size)
{
    int sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += inputNums[i];
    }
    return sum;
}

int recursiveSum1(int inputNums[], int size)
{
    if (size == 1)
    {
        return inputNums[0];
    }
    return recursiveSum1(inputNums, size - 1) + inputNums[size - 1];
}

int main()
{
    // // 4.1
    // cout << sum(3, 5) << endl;
    // cout << sum(3.4, 7.0) << endl;
    // cout << sum(4, 3.7) << endl;
    // cout << sum(3.5, 8) << endl;

    // // 4.3, 4.4
    // cout << sumMultiple(2, 3, 4) << endl;

    // 4.5
    int inputNums[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    int size = sizeof(inputNums) / sizeof(inputNums[0]);

    cout << sumInfinate(inputNums, size) << endl;
    cout << "new func" << endl;
    cout << sumInfinate1(inputNums, size) << endl;

    // 4.6
    cout << recursiveSum(inputNums, size) << endl;
    cout << recursiveSum1(inputNums, size) << endl;
}