#include <stdio.h>
#pragma GCC optimize "Ofast"

const int MDIGITS = 10, PW10[MDIGITS] = {0, 10, 100, 1000, 10000, 100000, 1000000, 10000000, 100000000, 1000000000};
const int IO_SZ = 4 << 20;
char _buf[IO_SZ], *_ii = _buf, *_oi = _buf;
template <typename T>
inline void scan(T &x)
{
    for (x = *_ii++ - '0'; *_ii++ >= '0'; x = x * 10 + _ii[-1] - '0')
        ;
}
template <typename T>
inline void print(T x)
{
    int dg = 0;
    while (dg < MDIGITS && PW10[dg] <= x)
        dg++;
    for (char *i = _oi + dg - 1; i >= _oi; --i, x /= 10)
        *i = x % 10 + '0';
    _oi += dg;
}

// if update l = -1
struct Event
{
    int l, r;
};

const int MN = 150005;
const int BSZ1 = 900, BC1 = 170;
const int BSZ2 = 512, BC2 = 300;
int n, m, q;
int line[MN], sArr[MN], blocks[BC2];
int lMem[MN], lInds[MN], lArr[MN]; // lArr only for long lines
Event events[MN];
int ans[MN];
int tmpArr[MN], pref[MN];

int main()
{
    fread(_buf, 1, IO_SZ, stdin);
    scan(n);
    scan(m);
    scan(q);
    for (int i = 0; i < n; i++)
    {
        scan(line[i]);
        lInds[--line[i]]++;
    }
    for (int i = 0; i < n; i++)
        scan(sArr[i]);
    for (int i = 0; i < m; i++)
        lInds[i + 1] += lInds[i];
    for (int i = n - 1; i >= 0; i--)
    {
        int a = line[i];
        lMem[--lInds[a]] = i;
        lArr[lInds[a]] = sArr[i];
    }
    for (int i = 0; i < n; i++)
    {
        int sz = lInds[line[i] + 1] - lInds[line[i]];
        if (sz < BSZ1)
            blocks[i >> 9] += sArr[i];
        else
            sArr[i] = 0;
    }

    for (int i = 0; i < q; i++)
    {
        int type;
        scan(type);
        if (type == 2)
        {
            int a;
            scan(a);
            a--;
            events[i] = {-1, a};
            if (lInds[a + 1] - lInds[a] < BSZ1)
            {
                int prv = sArr[lMem[lInds[a + 1] - 1]];
                for (int j = lInds[a]; j < lInds[a + 1]; j++)
                {
                    int p = lMem[j];
                    blocks[p >> 9] += prv - sArr[p];
                    int newPrv = sArr[p];
                    sArr[p] = prv;
                    prv = newPrv;
                }
            }
        }
        else
        {
            int l, r;
            scan(l);
            scan(r);
            l--;
            events[i] = {l, r};
            for (int j = l >> 9; j < r >> 9; j++)
                ans[i] += blocks[j];
            for (int j = (l >> 9) << 9; j < l; j++)
                ans[i] -= sArr[j];
            for (int j = (r >> 9) << 9; j < r; j++)
                ans[i] += sArr[j];
        }
    }

    for (int a = 0; a < m; a++)
    {
        int s = lInds[a + 1] - lInds[a];
        if (s < BSZ1)
            continue;
        for (int i = 0; i < n; i++)
            tmpArr[i + 1] = tmpArr[i] + (line[i] == a);
        for (int i = 0; i < s; i++)
            pref[i + 1] = pref[i] + lArr[lInds[a] + i];

        int offs = 0;
        for (int qi = 0; qi < q; qi++)
        {
            Event e = events[qi];
            if (e.l == -1)
            {
                if (e.r == a)
                {
                    offs++;
                    if (offs == s)
                        offs = 0;
                }
            }
            else
            {
                int l = tmpArr[e.l] - offs;
                int r = tmpArr[e.r] - offs;
                if (l <= 0)
                    l += s;
                if (r <= 0)
                    r += s;
                ans[qi] += pref[r] - pref[l];
                if (l > r || (tmpArr[e.l] == 0 && tmpArr[e.r] == s))
                    ans[qi] += pref[s];
            }
        }
    }

    for (int i = 0; i < q; i++)
    {
        if (events[i].l >= 0)
            print(ans[i]), *_oi++ = '\n';
    }
    fwrite(_buf, 1, _oi - _buf, stdout);
}