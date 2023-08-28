#include <stdio.h>
#include <vector>
#include <algorithm>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int n;
int s1, s2;
char status[200005];
int cost[200005];
int dp[200005][5];
vector<int> adjL[200005];

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
        scanf("%d", &cost[i]);
    }
    dfs(1, -1);
    printf("%d", min({dp[1][0], dp[1][1], dp[1][2]}));
}

void dfs(int cur, int par)
{
    dp[cur][0] = dp[cur][1] = dp[cur][2] = cost[cur];
    for (int s : adjL[cur])
    {
        if (s == par)
        {
            continue;
        }
        dfs(s, cur);
        dp[cur][0] += min({dp[s][0], dp[s][1], dp[s][2]});
        dp[cur][2] += min({dp[s][0], dp[s][1], dp[s][2]});
    }
}