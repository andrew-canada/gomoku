#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

typedef vector<int> vi;
typedef vector<vi> vvi;

struct pos
{
    int cost, r, c;
    bool operator<(const pos &p)
    {
        return cost < p.cost;
    }
};

const int INF = 1e9;
int rMove[4] = {0, 0, 1, -1};
int cMove[4] = {1, -1, 0, 0};

int dijkstra(const vvi &grid)
{
    int rows = grid.size(), cols = grid[0].size();
    vvi cost(rows, vi(cols, INF)), vis(rows, vi(cols, 0));
    priority_queue<pair<int, pair<int, int>>> pq;
    pq.push({grid[0][0], {0, 0}});
    cost[0][0] = grid[0][0];
    // pos cur;
    int r1, c1, cost1, r2, c2;
    while (!pq.empty())
    {
        auto cur = pq.top();
        pq.pop();
        r1 = cur.second.first, c1 = cur.second.second, cost1 = cur.first;
        if (cost1 > cost[r1][c1])
        {
            continue;
        }
        REP(i, 0, 4)
        {
            r2 = r1 + rMove[i], c2 = c1 + cMove[i];
            if (r2 >= 0 && c2 >= 0 && r2 < rows && c2 < cols)
            {
                if (cost1 + grid[r2][c2] < cost[r2][c2])
                {
                    cost[r2][c2] = cost1 + grid[r2][c2];
                    pq.push({cost[r2][c2], {r2, c2}});
                }
            }
        }
    }
    return cost[rows - 1][cols - 1];
}

int main()
{
    int cost;
    vvi grid = {{9, 4, 9, 9}, {6, 7, 6, 4}, {8, 3, 3, 7}, {7, 4, 9, 10}};
    cost = dijkstra(grid);
    printf("%d\n", cost);
}