#include <stdio.h>
#include <math.h>
#include <algorithm>

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

typedef long long ll;

int n, ts;
ll sum;
int triangle[3005][3005];

void findMax(int ts);

int main()
{
    scanf("%d%d", &n, &ts);
    REP(i, 0, n - 1)
    {
        REP(j, 0, i)
        {
            scanf("%d", &triangle[i][j]);
        }
    }
    findMax(ts);
    REP(i, 0, n - ts)
    {
        REP(j, 0, i)
        {
            sum += triangle[i][j];
        }
    }
    printf("%lld", sum);
}

void findMax(int tSz)
{
    int subSz;
    if (tSz == 1)
    {
        return;
    }
    else if (tSz == 2)
    {
        subSz = 1;
    }
    else
    {
        subSz = ceil(tSz * 2 / 3.0);
    }

    findMax(subSz);
    REP(i, 0, n - tSz)
    {
        REP(j, 0, i)
        {
            triangle[i][j] = std::max({triangle[i][j], triangle[i + tSz - subSz][j], triangle[i + tSz - subSz][j + tSz - subSz]});
        }
    }
}