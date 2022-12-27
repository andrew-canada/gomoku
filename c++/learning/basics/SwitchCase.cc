#include <iostream>
using namespace std;

int main()
{
    int i;
    do
    {
        cin >> i;
        switch (i)
        {
        case 1:
            cout << "one" << endl;
            break;
        default:
            cout << "default" << endl;
            break;
        }
    } while (i == 1);
}