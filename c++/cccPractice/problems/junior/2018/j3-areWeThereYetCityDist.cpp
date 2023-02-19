#include <stdio.h>

int main()
{
    int distances[4];
    int cities[5];
    int totalDist;

    scanf("%d%d%d%d", &distances[0], &distances[1], &distances[2], &distances[3]);

    for (int i = 0; i < 5; i++)
    {
        cities[i] = cities[i - 1] + distances[i - 1];
    }

    for (int i = 0; i < 5; ++i)
    {
        for (int j = 0; j < 5; ++j)
        {
            totalDist = cities[i] - cities[j];
            if (totalDist < 0)
                totalDist *= -1;
            printf("%d ", totalDist);
        }
        puts("\n");
    }
}