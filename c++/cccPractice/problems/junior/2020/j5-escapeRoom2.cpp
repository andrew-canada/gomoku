#include <stdio.h>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

// #define LOCAL

int row, col;
int room[1001][1001];
queue<int> path;
int visited[1000001];

int main()
{
#ifdef LOCAL
    freopen("in.txt", "r", stdin);
#endif
    scanf("%d%d", &row, &col);
    for (int r = 1; r <= row; r++)
    {
        for (int c = 1; c <= col; c++)
        {
            scanf("%d", &room[r][c]);
        }
    }

    path.push(room[1][1]);
    while (!path.empty())
    {
        int cur = path.front();
        path.pop();
        if (!visited[cur])
        {
            visited[cur] = true;
            for (int x = 1; x * x <= cur; x++)
            {
                if (cur % x == 0)
                {
                    int y = cur / x;

                    if ((x == row && y == col) || (x == col && y == row))
                    {
                        printf("yes");
                        return 0;
                    }

                    if (x <= row && y <= col)
                    {
                        int tmp = room[x][y];
                        if (!visited[tmp])
                        {
                            path.push(tmp);
                        }
                    }
                    if (x <= col && y <= row)
                    {
                        int tmp = room[y][x];
                        if (!visited[tmp])
                        {
                            path.push(tmp);
                        }
                    }
                }
            }
        }
    }
    printf("no");
}