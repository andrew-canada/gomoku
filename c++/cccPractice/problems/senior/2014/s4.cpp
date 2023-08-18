#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef long long ll;

int n, t;
int tx[2005], ty[2005], bx[2005], by[2005];
int diff[2005][2005];

int main()
{
    scanf("%d%d", &n, &t);
    int tlx, tly, brx, bry, ti;
    REP(i, 0, n)
    {
        scanf("%d%d%d%d", tx[i], ty[i], bx[i], by[i]);
    }
}