#include <stdio.h>

int main()
{
    int d, m;
    scanf("%d%d", &m, &d);
    if (m == 2 && d == 18)
    {
        printf("Special");
    }
    else if (m < 2 || (m == 2 && d < 17))
    {
        printf("Before");
    }
    else
    {
        printf("After");
    }
}