#include <stdio.h>
#include <utility>
#include <algorithm>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int n;
pair<int, int> obs[100005];
double speed;

int main()
{
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%d%d", &obs[i].first, &obs[i].second);
    }
    sort(obs, obs + n);
    REP(i, 0, n - 1)
    {
        speed = max(speed, abs((double)(obs[i + 1].second - obs[i].second) / (obs[i + 1].first - obs[i].first)));
    }
    printf("%.1f", speed);
}