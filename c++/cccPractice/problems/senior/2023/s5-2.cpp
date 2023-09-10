#include <stdio.h>
#include <math.h>
#include <vector>
#include <unordered_map>

using namespace std;

typedef long long ll;

int d;
vector<int> cantor;
unordered_map<int, bool> vis;

void filter(double l, double r);
bool isCantor(ll n);

int main()
{
    scanf("%d", &d);
    filter(0, d);
    for (int num : cantor)
    {
        vis.clear();
        if (isCantor(num))
        {
            printf("%d\n", num);
        }
    }
}

void filter(double l, double r)
{
    double len = (r - l) / 3;
    if (len <= 1)
    {
        for (int i = ceil(l); i <= floor(r); i++)
        {
            cantor.emplace_back(i);
        }
    }
    else
    {
        double nl = r - len;
        double nr = l + len;
        filter(l, nr);
        filter(nl, r);
    }
}

bool isCantor(ll n)
{
    if (n * 3 > d && n * 3 < d * 2)
    {
        return false;
    }
    if (n * 3 <= d)
    {
        n *= 3;
    }
    else
    {
        n = n * 3 - d * 2;
    }
    if (vis[n])
    {
        return true;
    }
    vis[n] = true;
    return isCantor(n);
}