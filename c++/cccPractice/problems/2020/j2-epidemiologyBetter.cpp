#include <stdio.h>
#include <math.h>

int main()
{
    int limit, d0, nI;
    scanf("%d%d%d", &limit, &d0, &nI);
    int days = 0;
    int newCount = d0;

    if (nI != 1)
    {
        while (newCount <= limit)
        {
            days++;
            newCount += d0 * pow(nI, days);
        }
    }
    else
    {
        days = limit / d0;
    }
    printf("%d", days);
}