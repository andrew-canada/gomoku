/*
derangements = permutation with no fixed points (none in same place as original)
there are n-1 points to place an object (can't place in old position)
if the object is placed in a new position, n-1 other objects need to be placed
if the object is swapped with a position, n-2 other objects need to be placed
*/

#include <bits/stdc++.h>

using namespace std;

typedef long long ll;

const int mxN = 1e6, M = 1e9 + 7;

ll dp[mxN + 1];

int main()
{
    int n;
    cin >> n;
    dp[0] = 1;
    for (int i = 1; i <= n; i++)
    {
        dp[i] = ((i - 1) * dp[i - 1] + (i - 1) * dp[i - 2]) % M;
    }
    cout << dp[n];
}