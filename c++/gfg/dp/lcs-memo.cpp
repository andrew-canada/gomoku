#include <bits/stdc++.h>

using namespace std;

int dp[100][100];

int lcs(string s1, string s2, int l1, int l2)
{
    if (dp[l1][l2] != -1)
    {
        return dp[l1][l2];
    }
    if (l1 == 0 || l2 == 0)
    {
        dp[l1][l2] = 0;
    }
    else if (s1[l1 - 1] == s2[l2 - 1])
    {
        return 1 + lcs(s1, s2, l1 - 1, l2 - 1);
    }
    else
    {
        return max(lcs(s1, s2, l1, l2 - 1), lcs(s1, s2, l1 - 1, l2));
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