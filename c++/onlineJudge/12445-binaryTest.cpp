#include <stdio.h>

int set[3]{1, 2, 3};

int main()
{
    for (int i = 0; i < (1 << 3); i++)
    {
        int sum = 0;
        for (int j = 0; j < 3; j++)
        {
            printf("i:%d j:%d 1<<j:%d set[j]:%d ", i, j, 1 << j, set[j]);
            if (i & (1 << j))
            {
                printf("in");
                sum += set[j];
            }
            printf("\n");
        }
        printf("%d\n", sum);
        if (sum == 6)
        {
            printf("found");
            break;
        }
    }
}