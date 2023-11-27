#include <bits/stdc++.h>

using namespace std;

typedef pair<int, int> pii;

int mj(int n, int *arr);

const int INF = 0x3f3f3f3f;
int dp[100];

int main()
{
    // freopen("minJumps.out", "w", stdout);
    int n = 5;
    int arr[5] = {3, 2, 2, 1, 5};
    printf("%d\n", mj(5, arr));
}

int mj(int n, int *arr)
{
    memset(dp, INF, sizeof(dp));
    queue<pii> q;
    q.push({0, 0});
    pii curI;
    while (!q.empty())
    {
        curI = q.front();
        q.pop();
        dp[curI.first] = min(curI.second, dp[curI.first]);
        for (int i = 1; i <= arr[curI.first]; i++)
        {
            // printf("%d\n", curI.first + i);
            q.push({curI.first + i, curI.second + 1});
            if (curI.first + i == n - 1)
            {
                break;
            }
        }
    }
    return dp[n - 1];
}