#include <stdio.h>

bool checkIsFavorite(int time);

int main()
{
    int numMinutes, numTimes;
    scanf("%d", &numMinutes);

    numTimes = numMinutes / 720 * 31;
    for (int i = 0; i < numMinutes % 720; i++)
    {
        if (checkIsFavorite(i))
        {
            numTimes += 1;
        }
    }

    printf("%d", numTimes);
}

bool checkIsFavorite(int time)
{
    int hour = time / 60;
    int minute = time % 60;
    if (hour == 0)
    {
        hour = 12;
    }

    if (hour > 9)
    {
        int diff1 = minute / 10 - minute % 10;
        int diff2 = hour - minute / 10;
        return diff1 == diff2;
    }
    int diff1 = minute / 10 - minute % 10;
    int diff2 = hour % 10 - minute / 10;
    int diff3 = hour / 10 - hour % 10;
    return diff1 == diff2 && diff2 == diff3;
}
