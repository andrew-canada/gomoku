#include <stdio.h>

int p;
int a, b;

int main()
{
    for (int i = 3; i >= 1; i--)
    {
        scanf("%d", &p);
        a += p * i;
    }
    for (int i = 3; i >= 1; i--)
    {
        scanf("%d", &p);
        b += p * i;
    }

    if (a > b)
    {
        printf("A");
    }
    else if (b > a)
    {
        printf("B");
    }
    else
    {
        printf("T");
    }
}