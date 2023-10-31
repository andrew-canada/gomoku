#include <stdio.h>

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)
typedef long long ll;

int n;
int p[200005], w[200005], d[200005];

ll getTime(int pos);

int main()
{
    scanf("%d", &n);
    REP(i, 0, n - 1)
    {
        scanf("%d%d%d", &p[i], &w[i], &d[i]);
    }
    int low = 0, high = 1e9;
    int mid;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (getTime(mid + 1) > getTime(mid))
        {
            high = mid;
        }
        else
        {
            low = mid + 1;
        }
    }
    printf("%lld", getTime(low));
}

ll getTime(int pos)
{
    ll t = 0;
    REP(i, 0, n - 1)
    {
        if (p[i] < pos - d[i])
        {
            t += (ll)w[i] * (pos - p[i] - d[i]);
        }
        else if (p[i] > pos + d[i])
        {
            t += (ll)w[i] * (p[i] - d[i] - pos);
        }
    }
    return t;
}