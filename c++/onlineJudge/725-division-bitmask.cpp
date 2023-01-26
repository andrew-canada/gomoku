#include <stdio.h>

int main()
{
    int f;
    bool first = true;
    while (scanf("%d", &f), f)
    {
        if (!first)
            printf("\n");
        first = false;

        bool nosolution = true;
        for (int n2 = 1234; n2 <= 98765 / f; n2++)
        {
            int n1 = n2 * f;
            int dgs = n2 < 10000;

            int tmp = n1;
            while (tmp)
            {
                dgs |= (1 << (tmp % 10));
                tmp /= 10;
            }

            tmp = n2;
            while (tmp)
            {
                dgs |= (1 << (tmp % 10));
                tmp /= 10;
            }

            if (dgs == (1 << 10) - 1)
            {
                nosolution = false;
                printf("%05d / %05d = %d\n", n1, n2, f);
            }
        }
        if (nosolution)
            printf("There are no solutions for %d.\n", f);
    }
}