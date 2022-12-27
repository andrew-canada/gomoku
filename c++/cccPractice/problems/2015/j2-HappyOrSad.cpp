#include <iostream>
#include <string>
using namespace std;

int main()
{
    int happyCount = 0, sadCount = 0;
    string input;
    getline(cin, input);
    for (int i = 0; i < input.length(); i++)
    {
        if (input[i] == ':' && i <= input.length() - 3)
        {
            if (input[i + 1] == '-')
            {
                if (input[i + 2] == ')')
                {
                    happyCount += 1;
                }
                else if (input[i + 2] == '(')
                {
                    sadCount += 1;
                }
            }
        }
    }
    if (happyCount == 0 && sadCount == 0)
    {
        cout << "none";
    }
    else if (happyCount == sadCount)
    {
        cout << "unsure";
    }
    else if (happyCount > sadCount)
    {
        cout << "happy";
    }
    else
    {
        cout << "sad";
    }
}