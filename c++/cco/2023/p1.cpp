#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int n, k;
int sums[1000005];

int main()
{
    scanf("%d%d", &n, &k);
    REP(i, 0, n - k + 1)
    {
        scanf("%d", &sums[i]);
    }
}