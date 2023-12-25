#include <bits/stdc++.h>

using namespace std;

int maze[4][4] = {{1, 0, 0, 0}, {1, 1, 0, 1}, {0, 1, 0, 0}, {1, 1, 1, 1}};
int path[4][4];

bool reachEnd();

int main()
{
    int n = 4;
    if (reachEnd())
    {
        printf("Yes");
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < n; j++)
            {
                printf("%d ", path[i][j]);
            }
            printf("\n");
        }
    }
    else
    {
        printf("No");
    }
}

bool reachEnd()
{
}