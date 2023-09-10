#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int n;
int ways;

int main()
{
    scanf("%d", &n);
    while (n >= 0)
    {
        if (n % 4 == 0)
        {
            ways++;
        }
        n -= 5;
    }
    printf("%d", ways);
    REP(i, 0, 2)
    {
        puts("hello");
    }
}