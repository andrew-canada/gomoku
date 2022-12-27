#include <iostream>

using namespace std;

int main()
{
    int numberOfTerms, inputNumber;
    double mean = 0;
    int min = INT_MAX, max = 0, range = 0;
    cin >> numberOfTerms;

    int *statistics = new int[numberOfTerms];

    for (int i = 0; i < numberOfTerms; i++)
    {
        cin >> inputNumber;
        statistics[i] = inputNumber;
    }

    for (int i = 0; i < numberOfTerms; i++)
    {
        mean += statistics[i];
        if (min > statistics[i])
        {
            min = statistics[i];
        }
        if (max < statistics[i])
        {
            max = statistics[i];
        }
    }
    mean /= numberOfTerms;
    range = max - min;

    cout << "mean: " << mean << endl;
    cout << "min: " << min << endl;
    cout << "max: " << max << endl;
    cout << "range: " << range << endl;
}