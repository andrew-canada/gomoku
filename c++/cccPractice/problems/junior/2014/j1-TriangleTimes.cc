#include <iostream>
using namespace std;

int main()
{
    int angle1 = 0, angle2 = 0, angle3 = 0;
    cin >> angle1 >> angle2 >> angle3;
    if (angle1 == 60 && angle2 == 60 && angle3 == 60)
    {
        cout << "Equilateral";
    }
    else if (angle1 != angle2 && angle1 != angle3 && angle2 != angle3 && angle1 + angle2 + angle3 == 180)
    {
        cout << "Scalene";
    }
    else if (angle1 + angle2 + angle3 == 180)
    {
        cout << "Isosceles";
    }
    else
    {
        cout << "Error";
    }
}