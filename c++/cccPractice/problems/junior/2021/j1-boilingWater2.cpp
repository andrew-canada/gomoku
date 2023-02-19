#include <stdio.h>

int main()
{
    int p, b;
    scanf("%d", &b);
    p = 5 * b - 400;
    printf("%d\n", p);
    if (p > 100)
    {
        printf("%d", -1);
    }
    else if (p == 100)
    {
        printf("%d", 0);
    }
    else
    {
        printf("%d", 1);
    }
}