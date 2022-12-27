#include <iostream>

using namespace std;

int main()
{
    // takes int and uses as a char ascii
    int i = 97;
    char ch = static_cast<char>(i);
    cout << ch << endl; // a

    char c1(49);
    cout << c1 << '\n';
}
