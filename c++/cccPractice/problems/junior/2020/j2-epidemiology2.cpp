#include <stdio.h>

int ni, day, ipp;
int t, d = -1;

int main()
{
    scanf("%d%d%d", &ni, &day, &ipp);
    if (ipp != 1)
    {
        while (t <= ni)
        {
            t += day;
            d++;
            day *= ipp;
        }
    }
    else
    {
        printf("%d", ni / day);
        return 0;
    }

    printf("%d", d);
}