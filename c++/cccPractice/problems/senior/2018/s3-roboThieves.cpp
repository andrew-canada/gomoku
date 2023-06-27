#include <stdio.h>
#include <vector>
#include <utility>
#include <queue>
#include <tuple>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

typedef pair<int, int> pii;
typedef tuple<int, int, int> iii;

int r, c;
char grid[100][100];
int gridSteps[100][100];
bool vis[100][100];
int dir[4][2] = {{0, 1}, {0, -1}, {1, 0}, {-1, 0}};
int startR, startC;
vector<pii> cameras;
queue<iii> steps;

bool coordInRange(int x, int y);
bool isPosValid(int x, int y);

int main()
{
    scanf("%d %d", &r, &c);
    REP(i, 0, r)
    {
        REP(j, 0, c)
        {
            scanf(" %c", &grid[i][j]);
            char cur = grid[i][j];
            if (cur == 'C')
            {
                cameras.push_back(make_pair(i, j));
            }
            else if (cur == '.')
            {
                gridSteps[i][j] = -1;
            }
            else if (cur == 'S')
            {
                startR = i, startC = j;
            }
        }
    }

    int curR, curC;
    REP(i, 0, cameras.size())
    {
        REP(j, 0, 4)
        {
            curR = cameras[i].first, curC = cameras[i].second;
            while (coordInRange(curR, curC))
            {
                curR += dir[j][0], curC += dir[j][1];
                char curVal = grid[curR][curC];
                if (curVal == 'W')
                {
                    break;
                }
                else if (curVal == '.' || curVal == 'S')
                {
                    grid[curR][curC] = 'C';
                }
            }
        }
    }

    curR = startR, curC = startC;
    vis[curR][curC] = true;
    int curSteps;
    if (grid[curR][curC] != 'C')
    {
        steps.push(make_tuple(curR, curC, 0));
    }
    while (!steps.empty())
    {
        curR = get<0>(steps.front()), curC = get<1>(steps.front());
        curSteps = get<2>(steps.front());
        steps.pop();
        if (grid[curR][curC] == '.')
        {
            gridSteps[curR][curC] = curSteps;
        }
        REP(i, 0, 4)
        {
            int nextR = curR + dir[i][0], nextC = curC + dir[i][1];
            int nextSteps = curSteps + 1;
            if (!isPosValid(nextR, nextC))
            {
                continue;
            }
            vis[nextR][nextC] = true;
            bool canContinue = true;
            bool isCorner = false;
            while (canContinue)
            {
                canContinue = false;
                if (grid[nextR][nextC] == 'R')
                {
                    canContinue = true;
                    nextC++;
                }
                if (grid[nextR][nextC] == 'L')
                {
                    canContinue = true;
                    nextC--;
                }
                if (grid[nextR][nextC] == 'U')
                {
                    canContinue = true;
                    nextR--;
                }
                if (grid[nextR][nextC] == 'D')
                {
                    canContinue = true;
                    nextR++;
                }
                if (canContinue && !isPosValid(nextR, nextC))
                {
                    isCorner = true;
                    break;
                }
                vis[nextR][nextC] = true;
                if (grid[nextR][nextC] == '.')
                {
                    break;
                }
            }
            if (!isCorner)
            {
                steps.push(make_tuple(nextR, nextC, nextSteps));
            }
        }
    }

    REP(i, 0, r)
    {
        REP(j, 0, c)
        {
            int curVal = gridSteps[i][j];
            if (curVal != 0)
            {
                printf("%d\n", curVal);
            }
        }
    }
}

bool coordInRange(int x, int y)
{
    return x >= 0 && x < r && y >= 0 && y < c;
}

bool isPosValid(int x, int y)
{
    return coordInRange(x, y) && !vis[x][y] && grid[x][y] != 'W' && grid[x][y] != 'C';
}