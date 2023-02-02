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

        int set;
        for (set = 0; set < (1 << bars); set++)
        {
            int sum = 0;
            for (int bar = 0; bar < bars; bar++)
            {
                if (set & (1 << bar))
                {
                    sum += lengths[bar];
                }
            }
            if (sum == l)
            {
                break;
            }
        }
        printf(set < (1 << bars) ? "YES\n" : "NO\n");
    }
}