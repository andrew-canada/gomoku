#include <iostream>
#include <iomanip>
using namespace std;

void symbolDraw()
{
    int height;
    int width;
    char symbol;
    cout << "Enter a height: ";
    cin >> height;
    cout << "Enter a width: ";
    cin >> width;
    cout << "Enter a symbol: ";
    cin >> symbol;

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            cout << setw(3) << symbol;
        }
        cout << endl;
    }
}

int main()
{
    symbolDraw();
    return 0;
}
