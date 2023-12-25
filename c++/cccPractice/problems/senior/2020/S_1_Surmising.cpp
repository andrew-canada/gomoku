#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

pii obs[100005];

int main()
{
    int n;
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%d%d", &obs[i].first, &obs[i].second);
    }
    sort(obs, obs + n);
    double maxS = -1, curS = -1;
    REP(i, 0, n)
    {
        curS = abs((1.0 * obs[i].second - obs[i + 1].second) / (1.0 * obs[i].first - obs[i + 1].first));
        maxS = max(maxS, curS);
    }
    printf("%.1lf", maxS);
}