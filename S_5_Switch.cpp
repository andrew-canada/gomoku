// row of k bool, each is on or off
// 4 or more consecutive on = block of 4 or more turns off
// turn on min number of bool to turn all off

#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int k;
int r1;
bool r[30];
unordered_map<int, bool> vis;

int bfs();

int main()
{
    // freopen("s5-2011.in", "r", stdin);
    scanf("%d", &k);
    REP(i, 0, k)
    {
        scanf("%d", &r[i]);
        r1 += r[i] << i;
    }
    printf("%d", bfs());
}

int bfs()
{
    queue<pii> q;
    q.push({r1, 0});
    pii cur;
    int nxt;
    int cr, cn;
    int nc;
    int pos;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        cr = cur.first;
        cn = cur.second;
        if (cr == 0)
        {
            return cn;
        }
        if (vis[cr])
        {
            continue;
        }
        vis[cr] = 1;
        REP(i, 0, k)
        {
            if (!(cr & 1 << i))
            {
                nxt = cr | 1 << i;
                nc = -1;
                REP(j, i, k)
                {
                    if (!(nxt & 1 << j))
                    {
                        break;
                    }
                    nc++;
                }
                for (int j = i; j >= 0; j--)
                {
                    if (!(nxt & 1 << j))
                    {
                        break;
                    }
                    nc++;
                    pos = j;
                }
                if (nc >= 4)
                {
                    nxt = nxt & (nxt + (1 << pos));
                }
                q.push({nxt, cn + 1});
            }
        }
    }
}