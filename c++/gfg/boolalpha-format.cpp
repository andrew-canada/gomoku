#include <bits/stdc++.h>

using namespace std;

int main()
{
    bool a = true, b = false;
    int x = 26, y = 20;
    cout << boolalpha << a << ' ' << b << '\n';
    cout << noboolalpha << a << ' ' << b << '\n';
    printf("%o %o\n", x, y);
    printf("%x %x\n", x, y);
    cout << showbase << oct << x << ' ' << y << '\n';
    cout << hex << x << ' ' << y << '\n';
    cout << noshowbase << oct << x << ' ' << y << '\n';
    cout << uppercase << hex << x << ' ' << y << '\n';
    cout << nouppercase << x << ' ' << y << '\n';
    cout << dec << x << ' ' << y << '\n';
    cout << setw(5) << setfill('*') << x << ' ' << y << '\n';
    cout << setw(5) << left << x << '\n';
    cout << setw(5) << right << x << '\n';
    return 0;
}