#include <bits/stdc++.h>

using namespace std;

int mincostTickets(vector<int> &days, vector<int> &costs)
{
    int numD = days[days.size() - 1];
    vector<int> dp(numD + 1, 0);
    int curD = 0;

    for (int i = 1; i <= numD; i++)
    {
        if (i < days[curD])
        {
            dp[i] = dp[i - 1];
        }
        else
        {
            dp[i] = min({dp[i - 1] + costs[0],
                         dp[max(0, i - 7)] + costs[1],
                         dp[max(0, i - 30)] + costs[2]});
            curD++;
        }
    }
    return dp[numD];
}

int main()
{
    vector<int> days = {1, 4, 6, 7, 8, 20}, costs = {7, 2, 15};
    cout << mincostTickets(days, costs) << '\n';
}