#include <iostream>
using namespace std;

void ascii()
{
    cout << "Please enter 5 characters: ";
    char c1, c2, c3, c4, c5;
    cin >> c1 >> c2 >> c3 >> c4 >> c5;
    cout << "The ASCII codes for the characters are: " << int(c1) << " " << int(c2) << " " << int(c3) << " " << int(c4) << " " << int(c5) << endl;
}

int main()
{
    ascii();
    return 0;
}