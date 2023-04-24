#include <stdio.h>

#define LSOne(n) (n & (-n))

int main()
{
    int n = 4;
    for (int i = 0; i < (1 << n); i++)
    {
        int pos = i;
        while (pos)
        {
            int ls = LSOne(pos);
            printf("%d ", __builtin_ctz(ls) + 1);
            pos -= ls;
        }
        printf("\n");
    }
}