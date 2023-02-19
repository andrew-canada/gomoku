#include <iostream>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);

    string text, string;
    cin >> text >> string;

    for (int i = 0; i < string.length(); i++)
    {
        if (text.find(string) != string::npos)
        {
            cout << "yes";
            return 0;
        }
        string = string.substr(1, string.length() - 1) + string[0];
    }

    cout << "no";
}
