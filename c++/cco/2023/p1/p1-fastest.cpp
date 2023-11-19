#include <stdio.h>
using ll = long long;

int constexpr IN_SZ = 8 << 20;
char _i[IN_SZ];
int _i0;
int readint()
{
    int x = 0;
    while (_i[_i0] < 48)
        ++_i0;
    while (_i[_i0] >= 48)
        x = 10 * x + _i[_i0++] - 48;
    return x;
}

int constexpr M = 1'000'003;
ll powmod(ll b, ll e)
{
    ll p = 1;
    while (e)
    {
        if (e & 1)
            p = p * b % M;
        e >>= 1, b = b * b % M;
    }
    return p;
}
int choose(ll n, ll k)
{
    ll num = 1, den = 1;
    if (n - k < k)
        k = n - k;
    if (k < 0)
        return 0;
    for (int i = 0; i < k; ++i)
    {
        num = num * (n - i) % M;
        den = den * (i + 1) % M;
    }
    return num * powmod(den, M - 2) % M;
}

int constexpr N = 1048576;
int s[N];
int val[N];

int main()
{
    fread(_i, 1, IN_SZ, stdin);

    int const n = readint();
    int const k = readint();
    for (int i = 0; i < n - k + 1; ++i)
        s[i] = readint();

    for (int i = 0; i < n; ++i)
        val[i] = -1;
    for (int i = 0; i < n - k; ++i)
    {
        if (s[i] == s[i + 1])
        {
            val[i + k] = val[i];
        }
        if (s[i] == s[i + 1] - 1)
        {
            val[i] = 0;
            val[i + k] = 1;
        }
        if (s[i] == s[i + 1] + 1)
        {
            val[i] = 1;
            val[i + k] = 0;
        }
        if (val[i] == -1)
            continue;
        int const v = val[i];
        for (int j = i - k; j >= 0 && val[j] == -1; j -= k)
        {
            val[j] = v;
        }
    }

    int g = s[0], t = k;
    for (int i = 0; i < k; ++i)
    {
        if (val[i] == 0)
            --t;
        if (val[i] == 1)
            --t, --g;
    }

    /* printf("%d %d\n", t, g); */
    printf("%d\n", choose(t, g));
}