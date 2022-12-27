#include <iostream>
#include <sstream>
using namespace std;

int main()
{

    int number;
    char var1, var2;
    int value;
    cin >> number;
    switch (number)
    {
    case 1:
        cin >> var1 >> value;
        cout << number << " " << var1 << " " << value << endl;
        break;
    }
    return 0;
}