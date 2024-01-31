#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

const int mxN = 100;

struct step
{
    int rw, cl, ns;
};

int r, c;
char grid[mxN + 1][mxN + 1];
int steps[mxN + 1][mxN + 1], xDir[4] = {1, 0, -1, 0}, yDir[4] = {0, 1, 0, -1};
vector<array<int, 2>> cam;
bool vis[mxN + 1][mxN + 1];

bool valid(int r1, int c1)
{
    return r1 >= 0 && c1 >= 0 && r1 < r && c1 < c;
}

bool safe(int r1, int c1)
{
    return valid(r1, c1) && !vis[r1][c1] && grid[r1][c1] != 'W' && grid[r1][c1] != 'C';
}

int main()
{
    cin >> r >> c;
    int sr, sc;
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            cin >> grid[i][j];
            if (grid[i][j] == 'S')
            {
                sr = i, sc = j;
            }
            else if (grid[i][j] == 'C')
            {
                cam.pb({i, j});
            }
            else if (grid[i][j] == '.')
            {
                steps[i][j] = -1;
            }
        }
    }
    for (array<int, 2> pos : cam)
    {
        for (int i = 0; i < 4; i++)
        {
            int cr = pos[0], cc = pos[1];
            while (valid(cr, cc))
            {
                cr += xDir[i], cc += yDir[i];
                if (grid[cr][cc] == 'W')
                {
                    break;
                }
                else if (grid[cr][cc] == '.' || grid[cr][cc] == 'S')
                {
                    grid[cr][cc] = 'C';
                }
            }
        }
    }
    queue<step> q;
    if (grid[sr][sc] == 'S')
    {
        q.push({sr, sc, 0});
    }
    vis[sr][sc] = true;
    step cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (grid[cur.rw][cur.cl] == '.')
        {
            steps[cur.rw][cur.cl] = cur.ns;
        }
        for (int i = 0; i < 4; i++)
        {
            int cr = cur.rw + xDir[i], cc = cur.cl + yDir[i];
            if (!safe(cr, cc))
            {
                continue;
            }
            vis[cr][cc] = true;
            bool ok = true, valid = true;
            while (ok)
            {
                ok = false;
                if (grid[cr][cc] == 'U')
                {
                    cr--;
                    ok = true;
                }
                if (grid[cr][cc] == 'D')
                {
                    cr++;
                    ok = true;
                }
                if (grid[cr][cc] == 'L')
                {
                    cc--;
                    ok = true;
                }
                if (grid[cr][cc] == 'R')
                {
                    cc++;
                    ok = true;
                }
                if (ok && !safe(cr, cc))
                {
                    valid = false;
                    break;
                }
                vis[cr][cc] = true;
                if (grid[cr][cc] == '.')
                {
                    break;
                }
            }
            if (valid)
            {
                q.push({cr, cc, cur.ns + 1});
            }
        }
    }
    for (int i = 0; i < r; i++)
    {
        for (int j = 0; j < c; j++)
        {
            if (steps[i][j])
            {
                cout << steps[i][j] << '\n';
            }
        }
    }
}