#include <stdio.h>
#include <vector>
#include <unordered_map>
#include <math.h>

using namespace std;

typedef long long ll;

int n;
vector<int> nums;
unordered_map<int, bool> vis;

void filterLayers(int layer, double l, double r);
bool isCantor(ll val);

int main()
{
    // freopen("s5.in", "r", stdin);
    // freopen("s5.out", "w", stdout);
    scanf("%d", &n);
    filterLayers(0, 0, n);
    for (int num : nums)
    {
        vis.clear();
        if (isCantor(num))
        {
            printf("%d\n", num);
        }
    }
}

void filterLayers(int layer, double l, double r)
{
    double len = (r - l) / 3;
    if (len <= 1)
    {
        for (int i = ceil(l); i <= floor(r); i++)
        {
            nums.push_back(i);
        }
    }
    else
    {
        double r1 = l + len;
        double l1 = r - len;
        filterLayers(layer + 1, l, r1);
        filterLayers(layer + 1, l1, r);
    }
}

bool isCantor(ll val)
{
    if (val * 3 > n && val * 3 < 2 * n)
    {
        return false;
    }
    if (val * 3 <= n)
    {
        val *= 3;
        if (vis[val])
        {
            return true;
        }
    }
    else
    {
        val = val * 3 - n * 2;
        if (vis[val])
        {
            return true;
        }
    }
    vis[val] = true;
    return isCantor(val);
}