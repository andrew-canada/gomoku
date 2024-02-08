#include <bits/stdc++.h>

using namespace std;

#define pb push_back
#define INF 0x3f3f3f3f

typedef long long ll;
typedef vector<ll> vll;
typedef vector<vll> mat;

const int mxN = 2e5, mxX = 1e6, M = 1e9 + 7, mxS = 600;

int arr[mxN + 1], med = -1;
multiset<int> low, high;
ll ls, hs;

void fix()
{
    int ne = low.size() + high.size() + 1;
    if (low.size() > (ne - 1) / 2)
    {
        high.insert(med);
        hs += med;
        med = *--low.end();
        low.erase(low.find(med));
        ls -= med;
    }
    if (low.size() < (ne - 1) / 2)
    {
        low.insert(med);
        ls += med;
        med = *high.begin();
        high.erase(high.find(med));
        hs -= med;
    }
}

void add(int cur)
{
    if (med == -1)
    {
        med = cur;
        return;
    }
    if (cur >= med)
    {
        high.insert(cur);
        hs += cur;
    }
    else
    {
        low.insert(cur);
        ls += cur;
    }
    fix();
}

void rem(int cur)
{
    if (cur == med)
    {
        med = *high.begin();
        high.erase(high.find(med));
        hs -= med;
    }
    else if (cur > med)
    {
        high.erase(high.find(cur));
        hs -= cur;
    }
    else
    {
        low.erase(low.find(cur));
        ls -= cur;
    }
    fix();
}

int main()
{
    int n, k;
    cin >> n >> k;
    for (int i = 0; i < n; i++)
    {
        cin >> arr[i];
    }
    if (k == 1)
    {
        for (int i = 0; i < n; i++)
        {
            cout << "0 ";
        }
        return 0;
    }
    for (int i = 0; i < k - 1; i++)
    {
        add(arr[i]);
    }
    for (int i = k - 1; i < n; i++)
    {
        add(arr[i]);
        cout << (hs - 1ll * high.size() * med) + (1ll * low.size() * med - ls) << " ";
        rem(arr[i - k + 1]);
    }
}