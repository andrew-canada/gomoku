#include <bits/stdc++.h>

using namespace std;

int dp[100][100];

int lcs(string s1, string s2, int l1, int l2)
{
    for (int i = 0; i <= l1; i++)
    {
        for (int j = 0; j <= l2; j++)
        {
            if (i == 0 || j == 0)
            {
                dp[i][j] = 0;
            }
            else if (s1[i - 1] == s2[j - 1])
            {
                dp[i][j] = 1 + dp[i - 1][j - 1];
            }
            else
            {
                dp[i][j] = max(dp[i][j - 1], dp[i - 1][j]);
            }
        }
    }
    return dp[l1][l2];
}

int main()
{
    string s1 = "ABCDGH", s2 = "AEDFHR";
    int l1 = s1.length(), l2 = s2.length();
    memset(dp, -1, sizeof(dp));
    printf("%d\n", lcs(s1, s2, l1, l2));
}