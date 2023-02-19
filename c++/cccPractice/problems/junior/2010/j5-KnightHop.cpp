#include <stdio.h>

int numHops = 0;
int startX, startY, endX, endY;
bool isVisited[8][8] = {false};
bool movesToMake[8][8] = {false};

int main()
{

    scanf("%d %d\n%d %d", &startX, &startY, &endX, &endY);

    isVisited[8 - startY][startX - 1] = true;
    movesToMake[8 - startY][startX - 1] = true;

    do
    {
        if (isVisited[8 - endY][endX - 1])
        {
            break;
        }
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                if (isVisited[i][j])
                {
                    if (i - 2 >= 0 && j - 1 >= 0)
                    {
                        movesToMake[i - 2][j - 1] = true;
                    }
                    if (i - 2 >= 0 && j + 1 < 8)
                    {
                        movesToMake[i - 2][j + 1] = true;
                    }
                    if (i - 1 >= 0 && j - 2 >= 0)
                    {
                        movesToMake[i - 1][j - 2] = true;
                    }
                    if (i - 1 >= 0 && j + 2 < 8)
                    {
                        movesToMake[i - 1][j + 2] = true;
                    }
                    if (i + 1 < 8 && j - 2 >= 0)
                    {
                        movesToMake[i + 1][j - 2] = true;
                    }
                    if (i + 1 < 8 && j + 2 < 8)
                    {
                        movesToMake[i + 1][j + 2] = true;
                    }
                    if (i + 2 < 8 && j - 1 >= 0)
                    {
                        movesToMake[i + 2][j - 1] = true;
                    }
                    if (i + 2 < 8 && j + 1 < 8)
                    {
                        movesToMake[i + 2][j + 1] = true;
                    }
                }
            }
        }
        for (int i = 0; i < 8; i++)
        {
            for (int j = 0; j < 8; j++)
            {
                isVisited[i][j] = movesToMake[i][j];
            }
        }
        numHops += 1;
    } while (true);

    printf("%d", numHops);
}