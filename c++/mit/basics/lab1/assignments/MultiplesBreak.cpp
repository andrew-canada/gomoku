#include <iostream>

using namespace std;

int main()
{
    int inputNum = 0;
    do
    {
        cin >> inputNum;

        if (inputNum == -1)
        {
            break;
        }
        if (inputNum % 5 != 0 || inputNum < 0)
        {
            continue;
        }
        else
        {
            cout << (inputNum / 5) << '\n';
        }
    } while (true);
    cout << "Goodbye!";
    return 0;
}
