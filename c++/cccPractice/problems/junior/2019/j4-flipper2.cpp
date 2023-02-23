#include <stdio.h>
#include <string>

bool h, v;
char in[1000001];

int main()
{
    scanf("%s", &in);
    std::string s(in);
    for (char c : s)
    {
        c == 'H' ? h = !h : v = !v;
    }

    if (h)
    {
        if (v)
        {
            printf("4 3\n2 1");
        }
        else
        {
            printf("3 4\n1 2");
        }
    }
    else if (v)
    {
        printf("2 1\n4 3");
    }
    else
    {
        printf("1 2\n3 4");
    }
}