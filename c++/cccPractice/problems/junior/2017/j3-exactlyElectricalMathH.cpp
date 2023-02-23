#include <stdio.h>
#include <math.h>

int main()
{
    int shortestPath;
    int startX, startY, destX, destY, charge;
    scanf("%d %d\n%d %d\n%d", &startX, &startY, &destX, &destY, &charge);

    shortestPath = abs(startX - destX) + abs(startY - destY);

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