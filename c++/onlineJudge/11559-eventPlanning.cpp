#include <stdio.h>

// #define LOCAL
const int INF = 1e9;

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    int numPeople, budget, hotels, choices;
    int costPerPerson;
    int maxRooms = 0, tempRooms;
    int minCost = INF, tempMinCost;
    bool isEntered = false;

    while (scanf("%d %d %d %d", &numPeople, &budget, &hotels, &choices) != EOF)
    {
        while (hotels > 0)
        {
            hotels--;
            scanf("%d", &costPerPerson);
            for (int j = 0; j < choices; j++)
            {
                scanf("%d ", &tempRooms);
                if (j == 0)
                {
                    maxRooms = tempRooms;
                }
                if (tempRooms > maxRooms)
                {
                    maxRooms = tempRooms;
                }
            }
            if (maxRooms >= numPeople)
            {
                tempMinCost = numPeople * costPerPerson;
                if (!isEntered)
                {
                    minCost = tempMinCost;
                }
                if (tempMinCost < minCost)
                {
                    minCost = tempMinCost;
                }
                isEntered = true;
            }
        }
        if (minCost <= budget)
        {
            printf("%d\n", minCost);
        }
        else
        {
            printf("stay home\n");
        }
        maxRooms = 0;
        minCost = INF;
        isEntered = false;
    }
    return 0;
}