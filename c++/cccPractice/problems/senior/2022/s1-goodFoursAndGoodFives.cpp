#include <stdio.h>

int n;
int c;

int main()
{
    scanf("%d", &n);
    while (n >= 0)
    {
        if (n % 4 == 0)
        {
            c++;
        }
        n -= 5;
    }
    printf("%d", c);
}