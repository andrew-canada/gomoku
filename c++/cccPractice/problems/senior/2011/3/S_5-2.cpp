#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

const int mxN = 20;
map<int, bool> vis;

int bfs(int start, int k)
{
    queue<array<int, 2>> q;
    // position, num moves
    q.push({start, 0});
    array<int, 2> cur;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (cur[0] == 0)
        {
            return cur[1];
        }
        if (vis[cur[0]])
        {
            continue;
        }
        vis[cur[0]] = true;
        for (int i = 0; i < k; i++)
        {
            if ((cur[0] >> i) ^ 1)
            {
                int nxt = cur[0] | (1 << i);
                int num = 1;
                for (int j = i + 1; j < k; j++)
                {
                    if ((cur[0] >> j) & 1)
                    {
                        num++;
                    }
                    else
                    {
                        break;
                    }
                }
                int pos = i;
                for (int j = i - 1; j >= 0; j--)
                {
                    if ((cur[0] >> j) & 1)
                    {
                        num++;
                        pos = j;
                    }
                    else
                    {
                        break;
                    }
                }
                if (num >= 4)
                {
                    nxt = nxt & (nxt + (1 << pos));
                }
                q.push({nxt, cur[1] + 1});
            }
        }
    }
}

int main()
{
    int k, x, start = 0;
    cin >> k;
    for (int i = 0; i < k; i++)
    {
        cin >> x;
        start |= (x << i);
    }
    cout << bfs(start, k);
}