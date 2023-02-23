#include <stdio.h>
#include <algorithm>

int main()
{
    int numPoints, tempX, tempY;
    int minX = 100, minY = 100;
    int maxX = 0, maxY = 0;
    scanf("%d", &numPoints);
    for (int i = 0; i < numPoints; i++)
    {
        scanf("%d,%d", &tempX, &tempY);
        if (tempX > maxX)
        {
            maxX = tempX;
        }
        if (tempX < minX)
        {
            minX = tempX;
        }

        if (tempY > maxY)
        {
            maxY = tempY;
        }
        if (tempY < minY)
        {
            minY = tempY;
        }
    }
    printf("%d,%d\n", minX - 1, minY - 1);
    printf("%d,%d\n", maxX + 1, maxY + 1);
}