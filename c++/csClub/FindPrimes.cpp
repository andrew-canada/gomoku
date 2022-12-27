#include <iostream>
using namespace std;

int main()
{
    int inputNum = 0;
    cin >> inputNum;

    for (int i = 1; i <= inputNum; i++)
    {
        if (i == 1)
        {
            cout << i << " is not prime" << endl;
        }
        else if (i == 2)
        {
            cout << i << " is prime" << endl;
        }
        else
        {
            for (int j = 2; j < i; j++)
            {
                if (i % j == 0)
                {
                    cout << i << " is not prime" << endl;
                    break;
                }
                if (j == i - 1)
                {
                    cout << i << " is prime" << endl;
                }
            }
        }
    }
}
