#include <stdio.h>

int main()
{
    int hours, minutes;
    int timeSpent = 0;
    scanf("%d:%d", &hours, &minutes);
    int time = 60 * hours + minutes;

    // after 5 and before 10 : will be affected
    if (time > 300 && time < 600)
    {
        if (time < 420)
        {
            timeSpent = 420 - time;
            timeSpent += (120 - timeSpent) * 2;
            if (timeSpent > 200)
            {
                timeSpent -= (time + timeSpent - 600) / 2;
            }
            time += timeSpent;
        }
        else
        {
            timeSpent = (600 - time);
            timeSpent += 120 - (600 - time) / 2;
            time += timeSpent;
        }
    }
    // after 13:00 and before 19:00 : will be affected
    else if (time > 780 && time < 1140)
    {
        if (time < 900)
        {
            timeSpent = 900 - time;
            timeSpent += (120 - timeSpent) * 2;
            time += timeSpent;
        }
        else
        {
            timeSpent = (1140 - time);
            timeSpent += 120 - (1140 - time) / 2;
            time += timeSpent;
        }
    }
    // won't be affected
    else
    {
        time += 120;
    }

    hours = time / 60;
    minutes = time % 60;
    if (hours > 23)
    {
        hours = hours - 24;
    }

    if (hours < 10)
    {
        fputs("0", stdout);
    }
    printf("%d:", hours);
    if (minutes < 10)
    {
        fputs("0", stdout);
    }
    printf("%d", minutes);
}