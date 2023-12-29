#include <bits/stdc++.h>

using namespace std;

int maze[4][4] = {{1, 0, 0, 0}, {1, 1, 1, 1}, {0, 1, 0, 1}, {1, 1, 1, 1}};
int path[4][4];
int n = 4;

bool isSafe(int r, int c);
bool reachEnd(int r, int c);

int main()
{
    if (reachEnd(0, 0))
    {
        printf("Yes\n");
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

bool isSafe(int r, int c)
{
    return r < n && c < n && maze[r][c];
}

bool reachEnd(int r, int c)
{
    if (r == n - 1 && c == n - 1)
    {
        path[r][c] = 1;
        return true;
    }
    if (isSafe(r, c))
    {
        path[r][c] = 1;
        if (reachEnd(r + 1, c))
        {
            return true;
        }
        else if (reachEnd(r, c + 1))
        {
            return true;
        }
        path[r][c] = 0;
    }
    return false;
}