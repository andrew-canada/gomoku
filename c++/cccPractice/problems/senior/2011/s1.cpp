#include <stdio.h>
#include <iostream>
#include <string>

using namespace std;

int n, t, s;
string line;

int main()
{
    scanf("%d", &n);
    getline(cin, line);
    while (n--)
    {
        getline(cin, line);
        for (char c : line)
        {
            if (c == 't' || c == 'T')
            {
                t++;
            }
            else if (c == 's' || c == 'S')
            {
                s++;
            }
        }
    }
    if (t > s)
    {
        printf("English");
    }
    else
    {
        printf("French");
    }
}