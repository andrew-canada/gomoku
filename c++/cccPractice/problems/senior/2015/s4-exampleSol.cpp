#include <climits>
#include <cstdio>
#include <vector>
#include <queue>
#include <functional>

using namespace std;

#define scan(x)                                                                   \
    do                                                                            \
    {                                                                             \
        while ((x = getchar()) < '0')                                             \
            ;                                                                     \
        for (x -= '0'; '0' <= (_ = getchar()); x = (x << 3) + (x << 1) + _ - '0') \
            ;                                                                     \
    } while (0)
char _;

int main()
{
    int thick, islnum, routenum;
    scan(thick);
    scan(islnum);
    scan(routenum);
    // adjto, (time, wear)
    vector<vector<pair<int, pair<int, int>>>> adj(islnum + 1);
    vector<int> bestwear(islnum + 1, INT_MIN);
    for (int i = 0; i < routenum; i++)
    {
        int a, b, time, wear;
        scan(a);
        scan(b);
        scan(time);
        scan(wear);
        adj[a].push_back({b, {time, wear}});
        adj[b].push_back({a, {time, wear}});
    }
    int start, end;
    scan(start);
    scan(end);
    // time, {pos, wear}
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, function<bool(const pair<int, pair<int, int>> &a, const pair<int, pair<int, int>> &b)>> q([](const auto &a, const auto &b)
                                                                                                                                                                           { return a.first > b.first; });
    q.push({0, {start, thick}});
    while (!q.empty())
    {
        pair<int, pair<int, int>> cur = q.top();
        q.pop();
        // if it does not have better wear than a faster time (one that came before it), skip
        if (cur.second.second <= bestwear[cur.second.first])
            continue;
        bestwear[cur.second.first] = cur.second.second;
        if (cur.second.first == end)
        {
            printf("%d\n", cur.first);
            return 0;
        }
        // printf("visiting %d with time %d and wear %d\n", cur.second.first, cur.first, cur.second.second);
        for (const auto &edge : adj[cur.second.first])
        {
            if (cur.second.second - edge.second.second > 0)
            {
                q.push({cur.first + edge.second.first, {edge.first, cur.second.second - edge.second.second}});
                // printf("\tpushing back %d with time %d and wear %d\n", edge.first, cur.first+edge.second.first, cur.second.second-edge.second.second);
            }
        }
    }
    printf("-1\n");
}