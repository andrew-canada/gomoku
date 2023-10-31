#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

typedef pair<int, int> pii;

struct cell
{
    int r, c, s;
};

int r, c;
char f[105][105];
int steps[105][105];
vector<pii> cam;
int dir[4][2] = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
int vis[105][105];
queue<cell> q;
int r0, c0;

bool inRange(int row, int col);
bool isValid(int row, int col);

int main()
{
    scanf("%d%d", &r, &c);
    REP(i, 0, r)
    {
        REP(j, 0, c)
        {
            scanf(" %c", &f[i][j]);
            if (f[i][j] == 'C')
            {
                cam.push_back({i, j});
            }
            else if (f[i][j] == '.')
            {
                steps[i][j] = -1;
            }
            else if (f[i][j] == 'S')
            {
                r0 = i, c0 = j;
            }
        }
    }
    int r1, c1;
    REP(i, 0, cam.size())
    {
        REP(j, 0, 4)
        {
            r1 = cam[i].first, c1 = cam[i].second;
            while (inRange(r1, c1))
            {
                r1 += dir[j][0], c1 += dir[j][1];
                if (f[r1][c1] == 'W')
                {
                    break;
                }
                else if (f[r1][c1] == '.' || f[r1][c1] == 'S')
                {
                    f[r1][c1] = 'C';
                }
            }
        }
    }
    vis[r0][c0] = true;
    int s1;
    int r2, c2, s2;
    if (f[r0][c0] != 'C')
    {
        q.push({r0, c0, 0});
    }
    while (!q.empty())
    {
        r1 = q.front().r, c1 = q.front().c, s1 = q.front().s;
        q.pop();
        if (f[r1][c1] == '.')
        {
            steps[r1][c1] = s1;
        }
        REP(i, 0, 4)
        {
            r2 = r1 + dir[i][0], c2 = c1 + dir[i][1], s2 = s1 + 1;
            if (!isValid(r2, c2))
            {
                continue;
            }
            vis[r2][c2] = true;
            bool canContinue = true;
            while (canContinue)
            {
                canContinue = false;
                if (f[r2][c2] == 'U')
                {
                    canContinue = true;
                    r2--;
                }
                if (f[r2][c2] == 'D')
                {
                    canContinue = true;
                    r2++;
                }
                if (f[r2][c2] == 'L')
                {
                    canContinue = true;
                    c2--;
                }
                if (f[r2][c2] == 'R')
                {
                    canContinue = true;
                    c2++;
                }
                vis[r2][c2] = true;
                if (f[r2][c2] == '.')
                {
                    break;
                }
            }
            q.push({r2, c2, s2});
        }
    }

    REP(i, 0, r)
    {
        REP(j, 0, c)
        {
            if (steps[i][j] != 0)
            {
                printf("%d\n", steps[i][j]);
            }
        }
    }
}

bool inRange(int row, int col)
{
    return row >= 0 && col >= 0 && row < r && col < c;
}

bool isValid(int row, int col)
{
    return inRange(row, col) && !vis[row][col] && f[row][col] != 'W' && f[row][col] != 'C';
}