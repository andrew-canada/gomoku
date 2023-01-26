#include <stdio.h>

int main()
{
    int n;
    int a, b, c;
    bool notSolved = true;

    scanf("%d", &n);
    for (int i = 0; i < n; i++)
    {
        scanf("%d %d %d", &a, &b, &c);
        for (int x = -22; x <= 22 && notSolved; x++)
        {
            if (x * x < c)
            {
                for (int y = -100; y <= 100 && notSolved; y++)
                {
                    if (x * x + y * y < c && x != y)
                    {
                        for (int z = -100; z <= 100 && notSolved; z++)
                        {
                            if ((z != x && z != y) &&
                                (x + y + z == a) &&
                                (x * y * z == b) &&
                                (x * x + y * y + z * z == c))
                            {
                                printf("%d %d %d\n", x, y, z);
                                notSolved = false;
                            }
                        }
                    }
                }
            }
        }
        if (notSolved)
            printf("%s\n", "No solution.");
        notSolved = true;
    }
}