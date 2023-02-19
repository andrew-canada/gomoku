#include <stdio.h>

int main()
{
    int numVotes;
    int aCount = 0, bCount = 0;
    scanf("%d", &numVotes);
    char votes[15];

    scanf("%14s", &votes);

    for (int i = 0; i < numVotes; i++)
    {
        if (votes[i] == 'A')
        {
            aCount++;
        }
        else
        {
            bCount++;
        }
    }

    if (aCount == bCount)
    {
        puts("Tie");
    }
    else if (aCount > bCount)
    {
        puts("A");
    }
    else
    {
        puts("B");
    }
}