#include <stdio.h>
#include <vector>
#include <queue>
#include <math.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int r, c;
int tmp;
int room[1005][1005];
bool visited[1000005];
queue<int> path;

int main()
{
    scanf("%d%d", &r, &c);
    REP(i, 1, r)
    {
        REP(j, 1, c)
        {
            scanf("%d", &room[i][j]);
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
            for (int i = 1; i <= sqrt(cur); i++)
            {
                int f = cur / i;
                if (f * i == cur)
                {
                    if ((f == r && i == c) || (f == c && i == r))
                    {
                        printf("yes");
                        return 0;
                    }
                    if (f <= r && i <= c)
                    {
                        tmp = room[f][i];
                        if (!visited[tmp])
                        {
                            path.push(tmp);
                        }
                    }
                    if (f <= c && i <= r)
                    {
                        tmp = room[i][f];
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