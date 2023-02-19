#include <stdio.h>

int numPeople;
int person;
int numRemovalSets[] = {1, 1, 1, 1, 1, 1, 1};

int main()
{
    scanf("%d", &numPeople);

    for (int i = 1; i < numPeople; i++)
    {
        scanf("%d", &person);
        numRemovalSets[person] = numRemovalSets[person] * (numRemovalSets[i] + 1);
    }

    printf("%d", numRemovalSets[numPeople]);
}