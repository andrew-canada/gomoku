#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

typedef long long ll;

int n, c;
int pos;
int pts[1000005];
int psa[1000005];
ll nt;

int main()
{
    scanf("%d%d", &n, &c);
    nt = n * (n - 1) * (n - 2) / 6;
    REP(i, 0, n)
    {
        scanf("%d", &pos);
        pts[pos]++;
    }
    psa[0] = pts[0];
    REP(i, 1, c)
    {
        psa[i] = psa[i - 1] + pts[i];
    }
    REP(i, 0, c)
    {
    }
}