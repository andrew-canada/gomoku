#include <stdio.h>
#include <unordered_map>

typedef long long ll;

int n;
std::unordered_map<int, ll> trees;

void calcNumTrees(int w);

int main()
{
    scanf("%d", &n);
    trees[1] = trees[2] = 1;
    if (n > 2)
    {
        calcNumTrees(n);
    }
    printf("%lld", trees[n]);
}

void calcNumTrees(int w)
{
    ll nt = 0;
    int nst = w;
    while (nst >= 2)
    {
        int stw = w / nst;
        int nstNW = w / (stw + 1);
        int ntSameStw = nst - nstNW;
        if (!trees[stw])
        {
            calcNumTrees(stw);
        }
        nt += ntSameStw * trees[stw];
        nst = nstNW;
    }
    trees[w] = nt;
}