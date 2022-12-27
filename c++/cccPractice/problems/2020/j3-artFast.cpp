#include <stdio.h>
#include <algorithm>

int numPoints, tempX, tempY;
int minX = 100, minY = 100;
int maxX = 0, maxY = 0;

int main()
{
    scanf("%d", &numPoints);
    for (int i = 0; i < numPoints; i++)
    {
        scanf("%d,%d", &tempX, &tempY);
        maxX = std::max(maxX, tempX);
        minX = std::min(minX, tempX);

        maxY = std::max(maxY, tempY);
        minY = std::min(minY, tempY);
    }
    printf("%d,%d\n", minX - 1, minY - 1);
    printf("%d,%d\n", maxX + 1, maxY + 1);
}