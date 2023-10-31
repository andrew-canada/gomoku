#include <stdio.h>

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
}