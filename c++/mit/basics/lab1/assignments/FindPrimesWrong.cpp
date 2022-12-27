#include <iostream>

using namespace std;

int main()
{
    int inputNum;
    int primeCounter = 0;
    bool isPrime = true;
    cin >> inputNum;

    for (int i = 1; i != 0; i++)
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
            primeCounter++;
            if (primeCounter == inputNum)
            {
                break;
            }
        }
    }
}