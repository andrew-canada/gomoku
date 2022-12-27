#include <stdio.h>

int main()
{
    int numMinutes, numTimes;
    int time[4] = {1, 2, 0, 0};

    scanf("%d", &numMinutes);

    numTimes = numMinutes / 720 * 31;

    for (int i = 0; i < numMinutes % 720; i++)
    {
        time[3] += 1;
        if (time[3] == 10)
        {
            time[3] = 0;
            time[2] += 1;
            if (time[2] == 6)
            {
                time[2] = 0;
                time[1] += 1;
                if (time[1] == 10)
                {
                    time[1] = 0;
                    time[0] = 1;
                }
                else if (time[1] == 3 && time[0] == 1)
                {
                    time[1] = 1;
                    time[0] = 0;
                }
            }
        }

        if (time[0] == 0)
        {
            if (time[3] - time[2] == time[2] - time[1])
            {
                numTimes += 1;
            }
        }
        else
        {
            if (time[3] - time[2] == time[2] - time[1] && time[2] - time[1] == time[1] - time[0])
            {
                numTimes += 1;
            }
        }
    }

    printf("%d", numTimes);
}