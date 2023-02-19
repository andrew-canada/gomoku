#include <stdio.h>

int main()
{
    int xVal, yVal;
    scanf("%d%d", &xVal, &yVal);

    if (xVal > 0)
    {
        if (yVal > 0)
        {
            puts("1");
        }
        else
        {
            puts("4");
        }
    }
    else
    {
        if (yVal > 0)
        {
            puts("2");
        }
        else
        {
            puts("3");
        }
    }
}