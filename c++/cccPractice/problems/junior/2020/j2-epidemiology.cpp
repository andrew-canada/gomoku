#include <stdio.h>

int main()
{
    int limit, d0, nI;
    scanf("%d%d%d", &limit, &d0, &nI);
    int days = 0;
    int newCount = d0;
    do
    {
        days += 1;
        newCount = nI * newCount;
        d0 += newCount;
    } while (d0 <= limit);
    printf("%d", days);
}