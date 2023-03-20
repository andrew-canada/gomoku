#include <stdio.h>
#include <algorithm>
#include <functional>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b - 1); i++)

int mm;
int n;
int tot;
int d[105];
int p[105];

int main()
{
    scanf("%d%d", &mm, &n);
    REP(i, 0, n)
    {
        scanf("%d", &d[i]);
    }
    REP(i, 0, n)
    {
        scanf("%d", &p[i]);
    }

    // min
    if (mm == 1)
    {
        sort(d, d + n);
        sort(p, p + n);
        REP(i, 0, n)
        {
            tot += max(d[i], p[i]);
        }
        printf("%d", tot);
    }
    else
    {
        sort(d, d + n, greater<int>());
        sort(p, p + n);
        REP(i, 0, n)
        {
            tot += max(d[i], p[i]);
        }
        printf("%d", tot);
    }
}