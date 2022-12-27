#include <iostream>

using namespace std;

int main()
{
    int numberOfTerms, inputNumber;
    cin >> numberOfTerms;

    cin >> inputNumber;
    double total = inputNumber;
    int min = inputNumber;
    int max = inputNumber;

    for (int i = 1; i < numberOfTerms; i++)
    {
        cin >> inputNumber;
        total += inputNumber;
        if (min > inputNumber)
        {
            min = inputNumber;
        }
        if (max < inputNumber)
        {
            max = inputNumber;
        }
    }

    cout << "average: " << (total / numberOfTerms) << endl;
    cout << "min: " << min << endl;
    cout << "max: " << max << endl;
    cout << "range: " << (max - min) << endl;
}