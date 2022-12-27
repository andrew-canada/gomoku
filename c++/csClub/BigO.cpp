#include <iostream>
using namespace std;

int main()
{
    int a = INT_MAX;
    int b = INT_MAX;
    int total = 0;
    double result = double(INT_MAX) * INT_MAX;
    cout << result << endl;

    cout << a * b << endl;

    for (int i = 0; i < a; i++)
    {
        total += b;
    }
    cout << total << endl;
}