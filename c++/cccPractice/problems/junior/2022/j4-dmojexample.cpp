#pragma GCC optimize "Ofast"
#include <stdio.h>
#include <ext/pb_ds/assoc_container.hpp>
#define INPUT_SIZE (7700 << 10)
int _i0 = 0;
char _, _i[INPUT_SIZE];
#define su(x)                                                               \
    do                                                                      \
    {                                                                       \
        for (x = _i[_i0++] - 48; 47 < (_ = _i[_i0++]); x = x * 10 + _ - 48) \
            ;                                                               \
    } while (0)

#define NOT_DMOJ

typedef long long ll;

inline ll getname()
{
    ll out = _i[_i0++] - 64;
    while (47 < (_ = _i[_i0++]))
        out = (out * 30) + _ - 64;
    return out;
}

int x, y, g;
ll xx[200000];
ll yy[200000];

__gnu_pbds::gp_hash_table<ll, int> hh;

int main()
{
#ifdef NOT_DMOJ
    freopen("data.txt", "r", stdin);
#endif // NOT_DMOJ
    fread(_i, 1, INPUT_SIZE, stdin);
    su(x);
    for (int i = 0; i < x * 2; i++)
        xx[i] = getname();
    su(y);
    for (int i = 0; i < y * 2; i++)
        yy[i] = getname();
    su(g);
    for (int i = 0; i < g; i++)
        for (int j = 0; j < 3; j++)
            hh[getname()] = i;
    g = 0; // ans
    for (int i = 0; i < x; i++)
    {
        if (hh[xx[i * 2]] != hh[xx[i * 2 + 1]])
            g++;
    }
    for (int i = 0; i < y; i++)
    {
        if (hh[yy[i * 2]] == hh[yy[i * 2 + 1]])
            g++;
    }
    printf("%d\n", g);
}