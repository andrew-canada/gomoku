#include <stdio.h>
#include <utility>
#include <queue>
#include <unordered_map>

using namespace std;

typedef pair<int, int> pii;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int k;
bool lights[30];
int n;
queue<pii> q;
unordered_map<int, int> vis;

int main()
{
    scanf("%d", &k);
    int startRow;
    REP(i, 0, k)
    {
        scanf("%d", &lights[i]);
        startRow += lights[i] << i;
    }
    pii cur;
    q.push({startRow, 0});
    int nextRow;
    int numContig;
    int minPos;
    while (!q.empty())
    {
        cur = q.front();
        q.pop();
        if (vis[cur.first])
        {
            continue;
        }
        if (cur.first == 0)
        {
            n = cur.second;
            break;
        }
        vis[cur.first] = true;
        REP(i, 0, k)
        {
            if (!(cur.first & (1 << i)))
            {
                nextRow = cur.first | (1 << i);
                numContig = -1;
                REP(j, i, k)
                {
                    if (!(nextRow & (1 << j)))
                    {
                        break;
                    }
                    numContig++;
                }
                for (int j = i; j >= 0; j--)
                {
                    if (!(nextRow & (1 << j)))
                    {
                        break;
                    }
                    minPos = j;
                    numContig++;
                }
                if (numContig >= 4)
                {
                    nextRow = nextRow & (nextRow + (1 << minPos));
                }
                q.push({nextRow, cur.second + 1});
            }
        }
    }
    printf("%d", n);
}