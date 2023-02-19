#include <stdio.h>

int main()
{
    int shortestPath, horizontalDist, verticalDist;
    int startX, startY, destX, destY, charge;
    scanf("%d %d\n%d %d\n%d", &startX, &startY, &destX, &destY, &charge);

    horizontalDist = startX - destX;
    if (horizontalDist < 0)
    {
        horizontalDist *= -1;
    }

    verticalDist = startY - destY;
    if (verticalDist < 0)
    {
        verticalDist *= -1;
    }

    shortestPath = horizontalDist + verticalDist;

    if (shortestPath > charge)
    {
        puts("N");
    }
    else
    {
        if (charge % 2 == shortestPath % 2)
        {
            puts("Y");
        }
        else
        {
            puts("N");
        }
    }
}