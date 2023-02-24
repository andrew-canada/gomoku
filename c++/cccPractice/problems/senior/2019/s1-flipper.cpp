#include <stdio.h>
#include <string>

char line[1000001];
int h, v;

int main()
{
    scanf("%s", &line);
    std::string s(line);
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
    if (h % 2 == 0 && v % 2 == 0)
    {
        printf("1 2\n3 4");
    }
    else if (h % 2 == 0)
    {
        printf("2 1\n4 3");
    }
    else if (v % 2 == 0)
    {
        printf("3 4\n1 2");
    }
    else
    {
        printf("4 3\n2 1");
    }
}