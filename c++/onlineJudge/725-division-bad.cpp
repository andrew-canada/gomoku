#include <stdio.h>

int main()
{
    int n1, n2, f, dgs, tmp;
    bool isp = false;

    while (scanf("%d", &f) != 0)
    {
        for (int n2 = 1234; n2 <= 98765 / f; n2++)
        {
            n1 = n2 * f;
            dgs = n2 < 10000;

            tmp = n1;
            while (tmp)
            {
                dgs |= (1 << tmp % 10);
                tmp /= 10;
            }

            tmp = n2;
            while (tmp)
            {
                dgs |= (1 << tmp % 10);
                tmp /= 10;
            }

            if (dgs == (1 << 10) - 1)
            {
                isp = true;
                printf("%d / %d = %d\n", n1, n2, f);
            }
        }
        if (!isp)
            printf("There are no solutions for %d.\n", f);
        isp = false;
    }
}