#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
#define INF 150005

int n, m;
int start, end, gcd;
int diff[INF][20];

int main()
{
    scanf("%d%d", &n, &m);
    REP(i, 0, m - 1)
    {
        scanf("%d%d%d", &start, &end, &gcd);
        diff[start][gcd] += gcd;
    }
}