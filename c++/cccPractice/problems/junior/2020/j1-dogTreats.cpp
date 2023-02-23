#include <stdio.h>

int main()
{
    int s, m, l;
    scanf("%d%d%d", &s, &m, &l);
    if (s + 2 * m + 3 * l >= 10)
    {
        printf("happy");
    }
    else
    {
        printf("sad");
    }
    return 0;
}