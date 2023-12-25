/*
infinite layers of number line from 0 to N
layer k has 3^k parts
each line is same as previous line, but with covered middle part
find which fractions x/N are never covered, x<=N
print all x
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

#define pb push_back
#define REP(i, a, b) for (int i = int(a); i < int(b); i++)
#define INF 0x3f3f3f3f

vector<int> c;
unordered_map<int, bool> v;

void filter(double l, double r);
bool ic(ll x, int n);

int main()
{
    int n;
    scanf("%d", &n);
    filter(0, n);
    for (int x : c)
    {
        if (ic(x, n))
        {
            printf("%d\n", x);
        }
        v.clear();
    }
}

void filter(double l, double r)
{
    double len = (r - l) / 3;
    if (len <= 1)
    {
        for (int i = ceil(l); i <= floor(r); i++)
        {
            c.pb(i);
        }
    }
    else
    {
        filter(l, l + len);
        filter(r - len, r);
    }
}

bool ic(ll x, int n)
{
    if (3 * x > n && 3 * x < 2 * n)
    {
        return 0;
    }
    if (3 * x <= n)
    {
        x *= 3;
    }
    else
    {
        x = 3 * x - 2 * n;
    }
    if (v[x])
    {
        return 1;
    }
    v[x] = 1;
    return ic(x, n);
}