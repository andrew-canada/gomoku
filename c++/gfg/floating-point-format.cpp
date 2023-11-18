#include <bits/stdc++.h>

using namespace std;

int main()
{
    double a = 1.2345;
    double b = 12345.6;
    double c = 1234567;
    double d = -123;
    cout << a << " " << b << " " << c << "\n";
    cout << setprecision(4) << a << " " << b << " " << c << "\n";
    cout << showpoint << a << "\n";
    cout << setprecision(6) << a << "\n";
    cout << showpos << a << "\n";
    cout << showpos << d << "\n";
    cout << noshowpos << uppercase << c << "\n";
}