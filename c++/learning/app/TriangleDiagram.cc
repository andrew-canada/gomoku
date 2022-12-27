#include <iostream>
#include <iomanip>
using namespace std;

void drawTriangle()
{
    int width;
    char symbol;
    cout << "Enter a width: ";
    cin >> width;
    cout << "Enter a symbol: ";
    cin >> symbol;

    for (int i = 1; i <= width; i++)
    {
        for (int j = 1; j <= i; j++)
        {
            cout << setw(3) << symbol;
        }
        cout << endl;
    }
}

int main()
{
    drawTriangle();
    return 0;
}
