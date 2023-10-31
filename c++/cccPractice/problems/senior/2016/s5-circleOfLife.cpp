#include <stdio.h>
#include <string.h>

typedef long long ll;

#define REP(i, a, b) for (int i = int(a); i < int(b); i++)

int n;
ll t;
char cs[100005];
bool startC[100005];
bool endC[100005];

int main()
{
    scanf("%d%lld", &n, &t);
    scanf("%s", &cs);
    REP(i, 0, n)
    {
        startC[i] = cs[i] - '0';
    }
    ll gen;
    int l, r;
    REP(i, 0, 50)
    {
        gen = (ll)1 << i;
        if (t & gen)
        {
            REP(i, 0, n)
            {
                l = (((ll)i - gen) % n + n) % n;
                r = ((ll)i + gen) % n;
                endC[i] = startC[l] ^ startC[r];
            }
            memcpy(startC, endC, sizeof(endC));
        }
    }
    REP(i, 0, n)
    {
        printf("%d", endC[i]);
    }
}