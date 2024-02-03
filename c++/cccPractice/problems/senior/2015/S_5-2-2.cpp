#include <bits/stdc++.h>

using namespace std;

#define INF 0x3f3f3f3f
#define pb push_back

typedef long long ll;

const int mxA = 1e6, mxG = 1e5, mxN = 3e3, mxM = 100;

int n, m;
int arr1[mxN + 1], arr2[mxN + 1], dp[mxN + 1][mxM + 1][mxM + 1][2];

int getSugar(int p, int low, int high, bool canTake)
{
    int ans = 0;
    if (dp[p][low][high][canTake])
    {
        return dp[p][low][high][canTake];
    }
    if (p == n && low > high)
    {
        return dp[p][low][high][canTake] = ans;
    }
    if (canTake)
    {
        if (p < n)
        {
            ans = max({ans,
                       getSugar(p + 1, low, high, true),
                       getSugar(p + 1, low, high, false) + arr1[p]});
        }
        if (low <= high)
        {
            ans = max(ans, getSugar(p, low, high - 1, false) + arr2[high]);
        }
    }
    else
    {
        if (p < n)
        {
            ans = max(ans, getSugar(p + 1, low, high, true));
        }
        if (low <= high)
        {
            ans = max(ans, getSugar(p, low + 1, high, true));
        }
    }
    return dp[p][low][high][canTake] = ans;
}

int main()
{
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> arr1[i];
    }
    cin >> m;
    for (int i = 0; i < m; i++)
    {
        cin >> arr2[i];
    }
    sort(arr2, arr2 + m);
    cout << getSugar(0, 0, m - 1, true);
}

/*
5
10
12
6
14
7
3
1
8
2
*/