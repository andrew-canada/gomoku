#include <iostream>

using namespace std;

int main()
{
    int N = 4;
    double acc = 0;
    for (int i = 1; i <= N; ++i)
    {
        double term = (1.0 / i);
        acc += term * term;
        for (int j = 1; j < i; ++j)
        {
            acc *= -1;
        }
    }
    cout << acc << "\n";
}