#include <stdio.h>
#include <algorithm>

int main()
{
    int distances[4];
    int totalDist;

    scanf("%d%d%d%d", &distances[0], &distances[1], &distances[2], &distances[3]);

    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            for (int city = std::min(i, j); city < std::max(i, j); city++)
            {
                totalDist += distances[city];
            }
            printf("%d ", totalDist);
            totalDist = 0;
        }
        puts("\n");
    }
}