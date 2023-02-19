#include <stdio.h>

int main()
{
    int d1, d2, d3, d4;
    scanf("%d%d%d%d", &d1, &d2, &d3, &d4);

    if ((d1 > 7))
    {
        if ((d2 == d3))
        {
            if (d4 > 7)
            {
                puts("ignore");
                return 0;
            }
        }
    }
    puts("answer");
}