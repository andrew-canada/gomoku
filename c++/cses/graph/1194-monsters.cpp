#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e3;
const int rDir[4] = {1, 0, -1, 0}, cDir[4] = {0, 1, 0, -1};
const char dirChar[4] = {'D', 'R', 'U', 'L'};

int r, c;
string s[mxN + 1];
int dist1[mxN + 1][mxN + 1], dist2[mxN + 1][mxN + 1], par1[mxN + 1][mxN + 1], par2[mxN + 1][mxN + 1];
bool vis[mxN + 1][mxN + 1];

bool isSafe(int r1, int c1)
{
    return r1 >= 0 && c1 >= 0 && r1 < r && c1 < c && s[r1][c1] == '.' && !vis[r1][c1];
}

void bfs(vector<array<int, 2>> pos, int dist[mxN + 1][mxN + 1], int par[mxN + 1][mxN + 1])
{
    memset(vis, 0, sizeof(vis));
    memset(dist, 0x3f3f3f3f, sizeof(dist1));
    queue<array<int, 2>> q;
    for (array<int, 2> arr : pos)
    {
        q.push({arr[0], arr[1]});
        vis[arr[0]][arr[1]] = true;
        dist[arr[0]][arr[1]] = 0;
    }
    array<int, 2> cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        for (int i = 0; i < 4; i++)
        {
            int nr = cur[0] + rDir[i], nc = cur[1] + cDir[i];
            if (!isSafe(nr, nc))
            {
                continue;
            }
            q.push({nr, nc});
            par[nr][nc] = i;
            dist[nr][nc] = dist[cur[0]][cur[1]] + 1;
            vis[nr][nc] = true;
        }
    }
}

int main()
{
    cin >> r >> c;
    int sr, sc;
    vector<array<int, 2>> monster;
    for (int i = 0; i < r; i++)
    {
        cin >> s[i];
        for (int j = 0; j < c; j++)
        {
            if (s[i][j] == 'A')
            {
                sr = i, sc = j;
                s[i][j] = '.';
            }
            else if (s[i][j] == 'M')
            {
                monster.push_back({i, j});
                s[i][j] = '.';
            }
        }
    }
    bfs({{sr, sc}}, dist1, par1), bfs(monster, dist2, par2);
    int er = -1, ec;
    for (int i = 0; i < r; i++)
    {
        if (dist1[i][0] < dist2[i][0])
        {
            er = i, ec = 0;
        }
        if (dist1[i][c - 1] < dist2[i][c - 1])
        {
            er = i, ec = c - 1;
        }
    }
    for (int i = 0; i < c; i++)
    {
        if (dist1[0][i] < dist2[0][i])
        {
            er = 0, ec = i;
        }
        if (dist1[r - 1][i] < dist2[r - 1][i])
        {
            er = r - 1, ec = i;
        }
    }
    if (~er)
    {
        cout << "YES\n";
        string ans;
        while (sr ^ er || sc ^ ec)
        {
            ans += dirChar[par1[er][ec]];
            int dirNum = par1[er][ec] ^ 2;
            er += rDir[dirNum], ec += cDir[dirNum];
        }
        reverse(ans.begin(), ans.end());
        cout << ans.size() << '\n';
        cout << ans;
    }
    else
    {
        cout << "NO\n";
    }
}