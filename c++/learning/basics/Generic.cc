#include <iostream>
using namespace std;

template <typename T>

T add(T a, T b)
{
    return a + b;
}
int sum(int num1, int num2)
{
    return num1 + num2;
}
float sum(float num1, float num2)
{
    return num1 + num2;
}

int main()
{
    cout << sum(2, 2) << endl;
    cout << sum((float)2.1, (float)2.3) << endl;
    cout << add(2.1, 2.3) << endl;
    cout << add(22, 2) << endl;
    return 0;
}