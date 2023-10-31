#include <stdio.h>
#include <cstring>
#include <string>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int h, v;
char flips[1000005];

int main()
{
    scanf("%s", &flips);
    std::string s(flips);
    for (char c : s)
    {
        if (c == 'H')
        {
            h++;
        }
        else
        {
            v++;
        }
    }
    if (h % 2 == 1 && v % 2 == 1)
    {
        puts("4 3\n2 1");
    }
    else if (h % 2 == 1)
    {
        puts("3 4\n1 2");
    }
    else if (v % 2 == 1)
    {
        puts("2 1\n4 3");
    }
    else
    {
        puts("1 2\n3 4");
    }
}