#include <iostream>

using namespace std;

int main()
{
    const char *message = "Hello, world!";
    cout << message << endl;

    int numberOfIterations;
    cin >> numberOfIterations;

    for (int i = 0; i < numberOfIterations; i++)
    {
        cout << i << " ";
        cout << message << endl;
    }

    int count = numberOfIterations;
    for (; count-- > 0;)
    {
        cout << message << endl;
    }

    cout << "\n while loop: \n";

    int i = numberOfIterations;
    while (i > 0)
    {
        cout << message << endl;
        i--;
    }

    cout << "\n do while loop: \n";

    i = numberOfIterations;
    do
    {
        cout << message << endl;
        i--;
    } while (i > 0);
}