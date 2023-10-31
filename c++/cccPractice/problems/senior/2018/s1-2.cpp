#include <stdio.h>
#include <algorithm>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define INF 2000000005

int n;
int v[105];
double minSz = INF;

int main()
{
    scanf("%d", &n);
    REP(i, 0, n)
    {
        scanf("%d", &v[i]);
    }
    sort(v, v + n);
    REP(i, 1, n - 1)
    {
        minSz = min(minSz, (double)(v[i + 1] + v[i]) / 2 - (double)(v[i] + v[i - 1]) / 2);
    }
    printf("%.1f", minSz);
}