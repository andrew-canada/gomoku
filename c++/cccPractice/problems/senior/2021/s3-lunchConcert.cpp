#include <stdio.h>

typedef long long ll;
int n;
int p[200005];
int w[200005];
int d[200005];

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

ll getDist(int pos);

int main()
{
    scanf("%d", &n);
    REP(i, 0, n - 1)
    {
        scanf("%d %d %d", &p[i], &w[i], &d[i]);
    }

    int low = 0;
    int high = n;
    int mid;
    while (low < high)
    {
        mid = (low + high) / 2;
        if (getDist(high) > getDist(mid))
        {
            high = mid - 1;
        }
        else
        {
            low = mid + 1;
        }
    }
    printf("%d", getDist(low));
}

ll getDist(int pos)
{
    ll sum = 0;
    REP(i, 0, n - 1)
    {
        if (p[i] > pos + d[i])
        {
            sum += (ll)w[i] * (p[i] - pos - d[i]);
        }
        else if (p[i] < pos - d[i])
        {
            sum += (ll)w[i] * (pos - p[i] - d[i]);
        }
    }
    return sum;
}