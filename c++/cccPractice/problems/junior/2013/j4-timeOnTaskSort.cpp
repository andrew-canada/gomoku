#include <stdio.h>
#include <algorithm>

using namespace std;

int main()
{
    int time, numChores;
    int timeSpent = 0, choresCompleted = 0;
    scanf("%d%d", &time, &numChores);

    int *choreList = new int[numChores];

    for (int i = 0; i < numChores; i++)
    {
        scanf("%d", &choreList[i]);
    }

    sort(choreList, choreList + numChores);

    for (; timeSpent < time; choresCompleted++)
    {
        if (timeSpent + choreList[choresCompleted] <= time)
        {
            timeSpent += choreList[choresCompleted];
        }
        else
        {
            break;
        }
    }

    printf("%d", choresCompleted);
}