#include <stdio.h>
#include <cstring>

int nums[12];

int main()
{
    int setsize;
    bool first = true;
    while (scanf("%d", &setsize), setsize)
    {
        if (!first)
        {
            printf("\n");
        }
        first = false;
        for (int i = 0; i < setsize; i++)
        {
            scanf("%d", &nums[i]);
        }
        for (int a = 0; a < setsize - 5; a++)
        {
            for (int b = a + 1; b < setsize - 4; b++)
            {
                for (int c = b + 1; c < setsize - 3; c++)
                {
                    for (int d = c + 1; d < setsize - 2; d++)
                    {
                        for (int e = d + 1; e < setsize - 1; e++)
                        {
                            for (int f = e + 1; f < setsize; f++)
                            {
                                printf("%d %d %d %d %d %d\n", nums[a], nums[b], nums[c], nums[d], nums[e], nums[f]);
                            }
                        }
                    }
                }
            }
        }
        memset(nums, 0, 12);
    }
}