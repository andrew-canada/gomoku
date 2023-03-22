#include <stdio.h>
#include <vector>
#include <queue>
#include <utility>
#include <map>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef pair<int, int> pii;

int n, l;
int field[1505][1505];
pii cur;
pii next;
// use 2d arr for vis
vector<pii> vis;

queue<pii> path;

int main()
{
    scanf("%d %d", &n, &l);
    REP(i, 1, n)
    {
        REP(j, 1, n)
        {
            scanf("%d", &field[i][j]);
        }
    }
    path.push(make_pair(1, 1));
    while (!path.empty())
    {
        cur = path.front();
        path.pop();
        if (!vis[cur])
        {
        }
    }
}