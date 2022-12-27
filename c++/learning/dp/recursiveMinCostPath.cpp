#include <stdio.h>

int minOf3(int n1, int n2, int n3);
int getShortestPath(int grid[3][3], int xCoord, int yCoord);

int main()
{
    int grid[3][3] = {1, 2, 3, 4, 8, 2, 1, 5, 3};
    printf("%d\n", getShortestPath(grid, 2, 2));
}

int getShortestPath(int grid[3][3], int xCoord, int yCoord)
{
    if (xCoord < 0 || yCoord < 0)
    {
        return 2147483647;
    }
    else if (xCoord == 0 && yCoord == 0)
    {
        return grid[0][0];
    }
    else
    {
        return grid[xCoord][yCoord] +
               minOf3(getShortestPath(grid, xCoord - 1, yCoord),
                      getShortestPath(grid, xCoord, yCoord - 1),
                      getShortestPath(grid, xCoord - 1, yCoord - 1));
    }
}

int minOf3(int n1, int n2, int n3)
{
    if (n1 < n2)
    {
        n1 < n3 ? n1 : n3;
    }
    else
    {
        n2 < n3 ? n2 : n3;
    }
}
