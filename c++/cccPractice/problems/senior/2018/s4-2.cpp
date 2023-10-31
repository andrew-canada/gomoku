#include <stdio.h>
#include <unordered_map>

using namespace std;

typedef long long ll;

unordered_map<int, ll> t;

int n;

void calcTrees(int w);

int main()
{
    scanf("%d", &n);
    t[1] = 1;
    t[2] = 1;
    if (n > 2)
    {
        calcTrees(n);
    }
    printf("%lld", t[n]);
}

void calcTrees(int w)
{
    ll nt = 0;
    int nst = w;
    int stW, nstNw, nstSw;
    while (nst > 1)
    {
        stW = w / nst;
        nstNw = w / (stW + 1);
        nstSw = nst - nstNw;
        if (!t[stW])
        {
            calcTrees(stW);
        }
        nt += nstSw * t[stW];
        nst = nstNw;
    }
    t[w] = nt;
}