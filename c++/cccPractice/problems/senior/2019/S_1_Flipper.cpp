#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

char flip[1000005];
int h, v;

int main()
{
    scanf("%s", flip);
    string s(flip);
    for(char c : s)
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
        printf("4 3\n2 1");
    }
    else if (h % 2 == 1)
    {
        printf("3 4\n1 2");
    }
    else if (v % 2 == 1)
    {
        printf("2 1\n4 3");
    }
    else
    {
        printf("1 2\n3 4");
    }
}