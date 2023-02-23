#include <iostream>
#include <string>

using namespace std;

int main()
{
    string str = "abcde";
    string reverse;
    for (int i = str.size() - 1; i >= 0; i--)
    {
        reverse += str[i];
    }
    cout << str << endl;
    cout << reverse << endl;
}