#include <stdio.h>
#include <vector>

using namespace std;

typedef long long ll;

int n;
vector<int> nums;

void filterLayers(int layer, ll l, ll r);
bool isCantor(ll val);

int main()
{
    scanf("%d", &n);
    filterLayers(0, 0, n);
    for (int num : nums)
    {
    }
}

void filterLayers(int layer, ll l, ll r)
{
    if (layer == 20)
    {
        for (int i = (int)(l + 0.5); i <= (int)(r - 0.5); i++)
        {
            nums.push_back(i);
        }
    }
    else
    {
        ll len = (r - l) / 3;
        ll r1 = l + len;
        ll l1 = r - len;
        filterLayers(++layer, l, r1);
        filterLayers(++layer, l1, r);
    }
}

bool isCantor(ll val)
{
}