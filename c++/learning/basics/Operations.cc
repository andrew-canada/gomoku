#include <iostream>
using namespace std;

void ops()
{
    cout << 5 + 2 << endl;
    cout << 5 - 2 << endl;
    cout << 5 / 2 << endl;
    cout << (float)5 / 2 << endl;
    cout << 5.0 / 2 << endl;
    cout << 5 % 2 << endl;
    int counter = 7;
    cout << counter++ << endl;
    cout << counter << endl;
    cout << ++counter << endl;
    int counter2 = 7;
    cout << --counter2 << endl;
    cout << counter2-- << endl;
    cout << counter2 << endl;
    int i = 5, j = 6;
    cout << (j > i) << endl;
    cout << ((j > i) ? "True" : "False") << endl;
    cout << (i == 5 && j == 5) << endl;
    cout << (i == 5 || j == 5) << endl;
    cout << !(i == 5 || j == 5) << endl;
    cout << (i == 5 && j == 5 + 1) << endl;
    cout << (i += 2) << endl;
    int temp;
    temp = i;
    i = j;
    j = temp;
    cout << "i=" << i << ", " << "j=" << j;
}

int main()
{
    ops();
    return 0;
}
