#include <stdio.h>

int hours, minutes, time;
int main()
{
    scanf("%d:%d", &hours, &minutes);
    time = 60 * hours + minutes;

    for (int i = 0; i < 240; time++)
    {
        if (time >= 420 && time < 600)
        {
            i += 1;
        }
        else if (time >= 900 && time < 1140)
        {
            i += 1;
        }
        else
        {
            i += 2;
        }
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