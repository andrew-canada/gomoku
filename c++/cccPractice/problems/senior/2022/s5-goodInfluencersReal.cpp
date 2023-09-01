#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define MIN(a, b) ((a) < (b) ? (a) : (b))
#define MAXN 200005
#define INF 1000000000

int n;
int s1, s2;
char status[MAXN];
bool yesno[MAXN];
int cost[MAXN];
ll dp[MAXN][3];
vector<int> adjL[MAXN];

void dfs(int cur, int par);

int main()
{
    scanf("%d", &n);
    REP(i, 1, n)
    {
        scanf("%d%d", &s1, &s2);
        adjL[s1].push_back(s2);
        adjL[s2].push_back(s1);
    }
    scanf("%s", &status);
    REP(i, 1, n)
    {
        yesno[i] = (status[i - 1] == 'Y');
    }
    REP(i, 1, n)
    {
        scanf("%d", &cost[i]);
    }
    dfs(1, -1);
    printf("%d", dp[1][1]);
}

void dfs(int cur, int par)
{
    for (int nxt : adjL[cur])
    {
        if (nxt != par)
        {
            dfs(nxt, cur);
        }
    }
    if (yesno[cur])
    {
        dp[cur][0] = INF, dp[cur][1] = 0, dp[cur][2] = cost[cur];
        for (int nxt : adjL[cur])
        {
            if (nxt != par)
            {
                dp[cur][1] += dp[nxt][1];
                dp[cur][2] += dp[nxt][0];
            }
        }
    }
    else
    {
        ll subSum = 0, costSum = 0;
        for (int nxt : adjL[cur])
        {
            if (nxt != par)
            {
                subSum += dp[nxt][0];
                costSum += dp[nxt][1];
            }
        }
        dp[cur][0] = MIN(cost[cur] + subSum, costSum);
        dp[cur][1] = INF, dp[cur][2] = INF;
        for (int nxt : adjL[cur])
        {
            if (nxt != par)
            {
                dp[cur][1] = MIN(dp[cur][1], costSum - dp[nxt][1] + dp[nxt][2]);
                dp[cur][2] = MIN(dp[cur][2], subSum - dp[nxt][0] + dp[nxt][2] + cost[cur]);
            }
        }
    }
    dp[cur][1] = MIN(dp[cur][1], dp[cur][2]);
    dp[cur][0] = MIN(dp[cur][0], dp[cur][1]);
}