#include <stdio.h>

// #define LOCAL
const int INF = 1e9;

int numPeople, budget, hotels, choices;
int cpp;
int maxRooms = 0;
int tmc;
int minCost = INF;

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    while (scanf("%d %d %d %d", &numPeople, &budget, &hotels, &choices) != EOF)
    {
        while (hotels > 0)
        {
            hotels--;
            scanf("%d", &cpp);
            for (int j = 0; j < choices; j++)
            {
                scanf("%d ", &maxRooms);
                if (maxRooms >= numPeople)
                {
                    tmc = numPeople * cpp;
                    if (tmc < minCost)
                        minCost = tmc;
                }
            }
        }
        if (minCost <= budget)
            printf("%d\n", minCost);
        else
            printf("stay home\n");

        minCost = INF;
    }
    return 0;
}