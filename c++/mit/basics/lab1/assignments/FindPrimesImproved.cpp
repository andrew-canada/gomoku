#include <iostream>

using namespace std;

int main()
{
    int inputNum;
    bool isPrime = true;
    cin >> inputNum;

    for (int i = 2; inputNum > 0; i++)
    {
        isPrime = true;
        for (int j = 2; j <= i - 1; j++)
        {
            if (i % j == 0)
            {
                isPrime = false;
                break;
            }
        }
        if (isPrime == true)
        {
            cout << i << '\n';
            --inputNum;
        }
    }
}