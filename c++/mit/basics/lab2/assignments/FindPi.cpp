#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cmath>

using namespace std;

int main()
{
    double x, y;
    int inCircleCount = 0;
    int distFromCenter = 0;
    double pi = 0;
    int numberOfThrows;
    cin >> numberOfThrows;

    for (int i = 0; i < numberOfThrows; i++)
    {
        x = rand() / (double)RAND_MAX;
        y = rand() / (double)RAND_MAX;
        if (sqrt(pow(x, 2) + pow(y, 2)) <= 1)
        {
            inCircleCount += 1;
        }
    }
    pi = 4.0 * inCircleCount / numberOfThrows;
    cout << "Pi is " << pi << endl;

    return 0;
}