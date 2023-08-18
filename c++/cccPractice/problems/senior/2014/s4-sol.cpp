#include <cstdio>
#include <algorithm>

using namespace std;

#define scanu(x)                                                                  \
    do                                                                            \
    {                                                                             \
        while ((x = getchar()) < '0')                                             \
            ;                                                                     \
        for (x -= '0'; '0' <= (_ = getchar()); x = (x << 3) + (x << 1) + _ - '0') \
            ;                                                                     \
    } while (0)
char _;

const int MN = 1e3;
const int INF = 1e9 + 1;

struct U
{
    int x, y;
    long long t;
    int cy;
    bool operator<(struct U u)
    {
        if (x == u.x)
        {
            return y < u.y;
        }
        else
        {
            return x < u.x;
        }
    }
};

struct U upd[4 * MN + 1];
int ry[2 * MN + 1];
long long diff[2 * MN + 1];

int main()
{
    int n;
    long long tint;
    scanu(n);
    scanu(tint);
    for (int i = 0; i < n; i++)
    {
        int xl, yt, xr, yb;
        long long t;
        scanu(xl);
        scanu(yt);
        scanu(xr);
        scanu(yb);
        scanu(t);
        upd[i * 4] = {xl, yt, t};
        upd[i * 4 + 1] = {xl, yb, -t};
        upd[i * 4 + 2] = {xr, yt, -t};
        upd[i * 4 + 3] = {xr, yb, t};
    }
    upd[n * 4] = {INF};
    sort(upd, upd + n * 4, [](struct U &a, struct U &b)
         { return a.y < b.y; });
    upd[0].cy = 1;
    ry[upd[0].cy] = upd[0].y;
    for (int i = 1; i < n * 4; i++)
    {
        if (upd[i].y == upd[i - 1].y)
        {
            upd[i].cy = upd[i - 1].cy;
        }
        else
        {
            upd[i].cy = upd[i - 1].cy + 1;
            ry[upd[i].cy] = upd[i].y;
        }
    }
    int mxcy = upd[n * 4 - 1].cy;
    sort(upd, upd + n * 4);
    long long ans = 0;
    int i = 0;
    while (i < n * 4)
    {
        do
        {
            diff[upd[i].cy] += upd[i].t;
            i++;
        } while (upd[i].x == upd[i - 1].x);
        long long cur = 0;
        for (int j = 1; j <= mxcy; j++)
        {
            cur += diff[j];
            if (cur >= tint)
            {
                ans += (long long)(ry[j + 1] - ry[j]) * (long long)(upd[i].x - upd[i - 1].x);
            }
        }
    }
    printf("%lld\n", ans);
}