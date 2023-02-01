#include <stdio.h>

int cases;
int l, bars;
int lengths[21];

int main()
{
    scanf("%d", &cases);
    for (int i = 0; i < cases; i++)
    {
        scanf("%d%d", &l, &bars);
        for (int j = 0; j < bars; j++)
        {
            scanf("%d", &lengths[j]);
        }
    }
}