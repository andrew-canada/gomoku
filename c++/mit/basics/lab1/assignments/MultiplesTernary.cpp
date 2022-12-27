#include <iostream>

using namespace std;

int main()
{
    int inputNum = 0;
    do
    {
        cin >> inputNum;
        cout << ((inputNum >= 0 && inputNum % 5 == 0) ? (inputNum / 5) : -1) << '\n';
    } while (true);
}