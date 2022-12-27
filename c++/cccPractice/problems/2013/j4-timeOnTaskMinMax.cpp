#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    int time, numChores, shortestChore, chorePos, tempChore;
    int timeSpent = 0, choresCompleted = 0;
    scanf("%d%d", &time, &numChores);
    vector<int> choreList;
    choreList.reserve(numChores);

    for (int i = 0; i < numChores; i++)
    {
        scanf("%d", &tempChore);
        choreList.push_back(tempChore);
    }

    do
    {
        shortestChore = *min_element(choreList.begin(), choreList.end());
        timeSpent += shortestChore;

        if (timeSpent > time)
        {
            break;
        }

        chorePos = find(choreList.begin(), choreList.end(), shortestChore) - choreList.begin();
        choreList.erase(choreList.begin() + chorePos);

        choresCompleted += 1;

    } while (timeSpent <= time);

    printf("%d", choresCompleted);
}