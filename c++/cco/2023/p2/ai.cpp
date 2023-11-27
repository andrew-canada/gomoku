/*

Problem Statement:
Thanks to your help with cropping her picture, Rebecca’s scenic photo is now featured on
the front cover of the newest issue of her magazine. However, it seems that some of her
readers still aren’t pleased with the picture. In particular, they seem to believe that the
mountain in the picture is fake!
For simplicity, we can describe the picture as a sequence of N columns of pixels. In the i-th
column, the first hi pixels from the bottom are of mountains. Her readers will only believe
that the picture contains a real mountain if it contains a single (possibly wide) peak. That
is, if there exists some index p with 1 ≤ p ≤ N such that h1 ≤ h2 ≤ · · · ≤ hp ≥ · · · ≥
hN−1 ≥ hN .
Luckily, Rebecca can still pay her editors to modify the picture and reprint the magazine.
Unfortunately for her though, the editors have a very peculiar pricing scheme for their work.
The only way Rebecca can edit the picture is by sending emails to her editors containing
the integers (i, j, k) such that 1 ≤ i < j < k ≤ N and hi > hj < hk. The editors will then
add an extra pixel of mountains in the j-th column (i.e. increment hj by 1) for a cost of
hi + hj + hk cents. Note that the change in hj may affect the costs of future edits.
To please her readers, Rebecca would like to edit the picture so that they believe it contains
a real mountain. Can you tell her the minimum cost required to do so?

*/

#include <bits/stdc++.h>

using namespace std;

#define REP(i, a, b) for (int i = int(a); i <= int(b); i++)

int h[1000005];
int dp[1000005];

int main()
{
    int n;
    scanf("%d", &n);
    REP(i, 1, n)
    {
        scanf("%d", &h[i]);
    }
    dp[0] = 0;
    dp[1] = 0;
    REP(i, 2, n)
    {
        dp[i] = INT_MAX;
        REP(j, 1, i - 1)
        {
            if (h[j] <= h[i])
            {
                int cost = dp[j] + h[i] + h[i + 1];
                dp[i] = min(dp[i], cost);
            }
        }
    }

    int minCost = INT_MAX;
    REP(i, 1, n)
    {
        minCost = min(minCost, dp[i]);
    }

    printf("%d\n", minCost);
    return 0;
}