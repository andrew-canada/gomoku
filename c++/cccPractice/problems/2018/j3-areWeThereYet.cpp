#include <stdio.h>

using namespace std;

int main()
{
    int d[4];
    scanf("%d%d%d%d", &d[0], &d[1], &d[2], &d[3]);
    for (int i = 0; i < 5; i++)
    {
        int acc1 = 0, acc2 = 0;
        for (int x = 0; x < i; x++)
        {
            acc2 += d[x];
        }
        for (int j = 0; j < 5; j++)
        {
            if (i == j)
            {
                printf("%d ", 0);
            }
            if (i < j)
            {
                acc1 += d[j - 1];
                printf("%d ", acc1);
            }
            if (i > j)
            {
                printf("%d ", acc2);
                acc2 -= d[j];
            }
        }
        printf("\n");
    }
}