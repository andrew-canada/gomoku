#include <stdio.h>
#include <set>

char status;
int num, numMsg;
int currentTime;
int recieveTimes[101];
int numMessages[101];
int waitTimes[101];
std::set<int> friends;

int main()
{
    scanf("%d", &numMsg);
    for (int i = 0; i < numMsg; i++)
    {
        scanf(" %c %d", &status, &num);
        if (status == 'R')
        {
            friends.insert(num);
            recieveTimes[num] = currentTime;
            numMessages[num] += 1;
        }
        else if (status == 'S')
        {
            waitTimes[num] += currentTime - recieveTimes[num];
            numMessages[num] += 1;
        }
        else
        {
            currentTime += num - 2;
        }
        currentTime += 1;
    }

    for (int f : friends)
    {
        if (numMessages[f] % 2 == 1)
        {
            printf("%d %d\n", f, -1);
        }
        else
        {
            printf("%d %d\n", f, waitTimes[f]);
        }
    }
}